#include "motor_simulator.h"
#include <cmath>
#include <iomanip>
#include <sstream>
#include <ctime>
OUNoise::OUNoise(int size, double mu, double theta, double sigma, double dt) 
    : mu(mu), theta(theta), sigma(sigma), dt(dt), state(size, mu), gen(std::random_device{}()), dist(0.0, 1.0) {}
void OUNoise::reset() {
    std::fill(state.begin(), state.end(), mu);
}
std::vector<double> OUNoise::evolve() {
    for (size_t i = 0; i < state.size(); ++i) {
        double dx = theta * (mu - state[i]) * dt + sigma * std::sqrt(dt) * dist(gen);
        state[i] += dx;
    }
    return state;
}
MotorDigitalTwin::MotorDigitalTwin(std::string id) : motor_id(id), state("IDLE"), health_score(100.0), bearing_condition(100.0), 
    ambient_temp(25.0), current_temp(25.0), current_rpm(0.0), current_load(0.0), operating_hours(0.0), noise(10, 0.0, 0.1, 0.05) {
    last_update = std::chrono::steady_clock::now();
}
void MotorDigitalTwin::start() {
    if (state == "IDLE" || state == "COOLDOWN") {
        state = "RUNNING";
        current_rpm = rated_rpm;
        current_load = 80.0;
    }
}
void MotorDigitalTwin::stop() {
    state = "IDLE";
    current_rpm = 0.0;
    current_load = 0.0;
}
void MotorDigitalTwin::inject_fault(const std::string& fault_type, double severity_mult, int duration_sec) {
    active_faults[fault_type] = severity_mult;
}
void MotorDigitalTwin::clear_fault(const std::string& fault_type) {
    active_faults.erase(fault_type);
}
std::vector<std::string> MotorDigitalTwin::get_active_faults() {
    std::vector<std::string> faults;
    for (auto const& [key, val] : active_faults) {
        faults.push_back(key);
    }
    return faults;
}
void MotorDigitalTwin::apply_thermal_dynamics(double dt, double current_A) {
    double heat_generated = std::pow(current_A / rated_current, 2) * heat_gen_coeff * 100;
    double cooling = (current_temp - ambient_temp) * cooling_rate;
    current_temp += (heat_generated - cooling) * dt;
    if (active_faults.count("MOTOR_OVERHEATING")) {
        current_temp += (2.0 * active_faults["MOTOR_OVERHEATING"]) * dt;
    }
    if (current_temp > get_max_temp()) {
        state = "THERMAL_PROTECTION_TRIGGERED";
        current_rpm = 0;
        current_load = 0;
    }
}
TelemetryDataPoint MotorDigitalTwin::update() {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = now - last_update;
    double dt = std::min(diff.count(), 1.0);
    last_update = now;
    if (state == "RUNNING") operating_hours += (dt / 3600.0);
    auto noise_vals = noise.evolve();
    double base_load = 0, base_voltage = rated_voltage + noise_vals[2] * (rated_voltage * 0.02), base_rpm = 0, base_current = 0, vibration = 0, pf = 0, flux = 0, vib_freq = 0, acoustic = 40.0;
    if (state == "RUNNING") {
        base_load = 80.0 + noise_vals[5] * 10;
        base_rpm = rated_rpm - (base_load * 0.1) + noise_vals[3] * 5;
        base_current = (base_load / 100.0) * rated_current + noise_vals[1] * 0.5;
        if (active_faults.count("MOTOR_OVERLOAD")) {
            double m = active_faults["MOTOR_OVERLOAD"];
            base_current *= (1.0 + 0.3 * m);
            base_rpm *= (1.0 - 0.1 * m);
            base_load = std::min(150.0, base_load * 1.5);
        }
        if (active_faults.count("RPM_DROP")) base_rpm *= std::max(0.1, (1.0 - 0.4 * active_faults["RPM_DROP"]));
        if (active_faults.count("BELT_JAM")) {
            double m = active_faults["BELT_JAM"];
            base_load = std::min(250.0, base_load * 2.5 * m);
            base_rpm = 0.0;
            base_current = rated_current * 3.0;
        }
        if (active_faults.count("VOLTAGE_FLUCTUATION")) base_voltage += (noise_vals[0]*1000) * active_faults["VOLTAGE_FLUCTUATION"];
        if (active_faults.count("WINDING_SHORT_CIRCUIT")) base_current *= (1.5 + active_faults["WINDING_SHORT_CIRCUIT"]);
        if (active_faults.count("BEARING_DEGRADATION")) bearing_condition -= dt * 0.01 * active_faults["BEARING_DEGRADATION"];
        if (active_faults.count("BEARING_SEIZURE")) {
            base_current = rated_current * 2;
            base_rpm = 0.0;
        }
        apply_thermal_dynamics(dt, base_current);
        vibration = 2.0 + (100 - bearing_condition)*0.1 + noise_vals[4];
        if (active_faults.count("EXCESSIVE_VIBRATION")) vibration *= (3.0 * active_faults["EXCESSIVE_VIBRATION"]);
        if (active_faults.count("SHAFT_MISALIGNMENT")) {
            double m = active_faults["SHAFT_MISALIGNMENT"];
            vibration *= (1.5 + 0.5 * m);
            base_load *= (1.0 + 0.1 * m);
        }
        pf = 0.85 + noise_vals[6] * 0.05;
        flux = 1.0 + noise_vals[7] * 0.02;
        vib_freq = 50.0 + (100 - bearing_condition) * 5 + noise_vals[8] * 10;
        acoustic = 60.0 + (100 - bearing_condition) * 0.5 + noise_vals[9] * 5;
        bearing_condition = std::max(0.0, bearing_condition - (dt / 3600.0) * 0.001 * (base_load / 100.0));
    } else {
        apply_thermal_dynamics(dt, 0.0);
        if (state == "THERMAL_PROTECTION_TRIGGERED" && current_temp < (ambient_temp + 10.0)) {
            state = "IDLE";
        }
    }
    double temp_penalty = std::max(0.0, (current_temp - get_max_temp() * 0.8) * 0.5);
    double vib_penalty = std::max(0.0, (vibration - 7.1) * 2);
    double bearing_penalty = (100 - bearing_condition) * 0.3;
    health_score = std::max(0.0, 100.0 - temp_penalty - vib_penalty - bearing_penalty);
    std::time_t t = std::time(nullptr);
    char tmbuf[32];
    std::strftime(tmbuf, sizeof(tmbuf), "%Y-%m-%dT%H:%M:%SZ", std::gmtime(&t));
    return {std::string(tmbuf), motor_id, current_temp, base_current, base_voltage, base_rpm, vibration, base_load, pf, flux, vib_freq, acoustic, state};
}

#pragma once
#include <string>
#include <vector>
#include <map>
#include <random>
#include <chrono>
struct TelemetryDataPoint {
    std::string timestamp;
    std::string motor_id;
    double temperature_celsius;
    double current_ampere;
    double voltage_volt;
    double rpm;
    double vibration_mm_s;
    double load_percentage;
    double power_factor;
    double flux_density_tesla;
    double vibration_frequency_hz;
    double acoustic_noise_db;
    std::string state;
};
class OUNoise {
public:
    OUNoise(int size, double mu = 0.0, double theta = 0.15, double sigma = 0.2, double dt = 1.0);
    void reset();
    std::vector<double> evolve();
private:
    double mu, theta, sigma, dt;
    std::vector<double> state;
    std::mt19937 gen;
    std::normal_distribution<double> dist;
};
class MotorDigitalTwin {
public:
    MotorDigitalTwin(std::string motor_id);
    void start();
    void stop();
    void inject_fault(const std::string& fault_type, double severity_mult, int duration_sec);
    void clear_fault(const std::string& fault_type);
    TelemetryDataPoint update();
    std::string motor_id;
    std::string state;
    double health_score;
    double bearing_condition;
    std::vector<std::string> get_active_faults();
private:
    double ambient_temp, current_temp;
    double current_rpm, current_load;
    double operating_hours;
    OUNoise noise;
    std::map<std::string, double> active_faults; 
    std::chrono::time_point<std::chrono::steady_clock> last_update;
    void apply_thermal_dynamics(double dt, double current_A);
    double get_max_temp() { return 155.0; }
    double rated_voltage = 400.0;
    double rated_current = 25.0;
    double rated_rpm = 1450.0;
    double heat_gen_coeff = 0.05;
    double cooling_rate = 0.02;
};

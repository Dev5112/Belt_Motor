#include "httplib.h"
#include "json.hpp"
#include "motor_simulator.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <map>
using json = nlohmann::json;
std::map<std::string, MotorDigitalTwin> motors;
std::map<std::string, std::deque<TelemetryDataPoint>> history;
std::mutex mtx;
void to_json(json& j, const TelemetryDataPoint& p) {
    j = json{
        {"timestamp", p.timestamp},
        {"motor_id", p.motor_id},
        {"temperature_celsius", p.temperature_celsius},
        {"current_ampere", p.current_ampere},
        {"voltage_volt", p.voltage_volt},
        {"rpm", p.rpm},
        {"vibration_mm_s", p.vibration_mm_s},
        {"load_percentage", p.load_percentage},
        {"power_factor", p.power_factor},
        {"flux_density_tesla", p.flux_density_tesla},
        {"vibration_frequency_hz", p.vibration_frequency_hz},
        {"acoustic_noise_db", p.acoustic_noise_db},
        {"state", p.state}
    };
}
void simulation_loop() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lock(mtx);
        for (auto& pair : motors) {
            auto pt = pair.second.update();
            auto& hist = history[pair.first];
            hist.push_front(pt);
            if (hist.size() > 1000) hist.pop_back();
        }
    }
}
int main() {
    motors.emplace("MOTOR_001", MotorDigitalTwin("MOTOR_001"));
    motors.emplace("MOTOR_002", MotorDigitalTwin("MOTOR_002"));
    for (auto& m : motors) {
        m.second.start();
    }
    std::thread sim_thread(simulation_loop);
    httplib::Server svr;
    svr.Options(R"(.*)", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "*");
        res.status = 204;
    });
    svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
        FILE* f = fopen("dashboard.html", "r");
        if (f) {
            fseek(f, 0, SEEK_END);
            long fsize = ftell(f);
            fseek(f, 0, SEEK_SET);
            std::string html(fsize, 0);
            fread(&html[0], 1, fsize, f);
            fclose(f);
            res.set_content(html, "text/html");
        } else {
            res.set_content("Dashboard not found.", "text/plain");
        }
    });
    svr.Get("/api/v1/health", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        json j = {{"status", "ok"}};
        res.set_content(j.dump(), "application/json");
    });
    svr.Get("/api/v1/motors", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        std::lock_guard<std::mutex> lock(mtx);
        json j = json::array();
        for (auto& pair : motors) {
            auto& m = pair.second;
            j.push_back({
                {"motor_id", m.motor_id},
                {"state", m.state},
                {"health_score", m.health_score},
                {"bearing_condition", m.bearing_condition},
                {"active_faults", m.get_active_faults()}
            });
        }
        res.set_content(j.dump(), "application/json");
    });
    svr.Get("/api/v1/telemetry/latest", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        std::lock_guard<std::mutex> lock(mtx);
        json j = json::array();
        for (auto& pair : history) {
            if (!pair.second.empty()) {
                j.push_back(pair.second.front());
            }
        }
        res.set_content(j.dump(), "application/json");
    });
    svr.Get(R"(/api/v1/telemetry/([^/]+))", [](const httplib::Request& req, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        std::string motor_id = req.matches[1];
        int limit = 100;
        if (req.has_param("limit")) limit = std::stoi(req.get_param_value("limit"));
        std::lock_guard<std::mutex> lock(mtx);
        json j = json::array();
        if (history.count(motor_id)) {
            auto& hist = history[motor_id];
            int count = 0;
            for (auto& pt : hist) {
                if (count >= limit) break;
                j.push_back(pt);
                count++;
            }
        }
        res.set_content(j.dump(), "application/json");
    });
    svr.Post("/api/v1/faults/inject", [](const httplib::Request& req, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        auto body = json::parse(req.body);
        std::string motor_id = body["motor_id"];
        std::string fault_type = body["fault_type"];
        double mult = body.value("intensity_multiplier", 1.0);
        int dur = body.value("duration_seconds", 60);
        std::lock_guard<std::mutex> lock(mtx);
        if (motors.count(motor_id)) {
            motors.at(motor_id).inject_fault(fault_type, mult, dur);
            res.set_content(json{{"status", "success"}}.dump(), "application/json");
        } else {
            res.status = 404;
        }
    });
    svr.Post(R"(/api/v1/faults/clear/([^/]+)/([^/]+))", [](const httplib::Request& req, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        std::string motor_id = req.matches[1];
        std::string fault_type = req.matches[2];
        std::lock_guard<std::mutex> lock(mtx);
        if (motors.count(motor_id)) {
            motors.at(motor_id).clear_fault(fault_type);
            res.set_content(json{{"status", "success"}}.dump(), "application/json");
        } else {
            res.status = 404;
        }
    });
    std::cout << "Starting C++ Telemetry Server on http://localhost:8080..." << std::endl;
    svr.listen("0.0.0.0", 8080);
    return 0;
}

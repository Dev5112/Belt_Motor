# Industrial Conveyor-Belt Motor Telemetry & Digital Twin Simulator

An advanced industrial IoT (IIoT) simulation and monitoring system for conveyor-belt motors. This project features a **C++ backend** that simulates multi-motor "Digital Twins" generating realistic telemetry data, and a **Python Streamlit dashboard** for real-time monitoring, fault injection, and historical analytics.

## 🌟 Project Overview

In industrial environments, predictive maintenance is critical to preventing downtime. This project simulates a fleet of conveyor belt motors running in real-time, producing high-fidelity telemetry metrics such as temperature, vibration, current, voltage, and acoustic noise. 

It uses **Ornstein-Uhlenbeck (OU) stochastic noise processes** to mimic real-world sensor fluctuations and implements complex thermal dynamics and physical degradation modeling. Users can proactively inject various faults (e.g., bearing wear, stator short) and observe how the telemetry responds, making this an excellent tool for training Anomaly Detection and Remaining Useful Life (RUL) machine learning models.

## 🚀 Key Features

- **Realistic Digital Twins**: High-fidelity simulation of AC induction motors with physics-informed thermal dynamics.
- **Stochastic Noise Modeling**: Uses Ornstein-Uhlenbeck processes for realistic, mean-reverting sensor noise.
- **Advanced Fault Injection System**: Simulate up to 10 distinct physical faults (e.g., bearing degradation, rotor imbalance) with configurable severity, duration, and exponential recovery behaviors.
- **High-Performance C++ Backend**: Built using `cpp-httplib` to provide a robust, low-latency REST API.
- **Embedded Database**: Uses DuckDB with Write-Ahead Logging (WAL) for highly efficient, PostgreSQL-grade analytical persistence of telemetry data.
- **Interactive Dashboard**: A Streamlit and Plotly-powered Python frontend offering Live Monitoring, Fault Management, and Historical Analytics.

## 🛠️ Technology Stack

**Backend:**
- C++17
- `cpp-httplib` (REST API framework)
- `nlohmann/json` (JSON serialization)
- DuckDB (Embedded OLAP Database)

**Frontend:**
- Python 3
- Streamlit (Web Dashboard)
- Plotly (Data Visualization)
- Pandas & Requests

## 📂 Project Structure

```text
├── cpp_backend/               # C++ Source Code
│   ├── main.cpp               # REST API Server and Database Initialization
│   ├── motor_simulator.cpp    # Implementation of Digital Twin and OU Noise
│   ├── motor_simulator.h      # Definitions for Telemetry and Fault models
│   ├── httplib.h              # C++ HTTP library
│   └── json.hpp               # C++ JSON library
├── dashboard/                 
│   └── app.py                 # Streamlit Frontend Application
├── requirements.txt           # Python dependencies for the dashboard
├── .gitignore                 
└── README.md                  # Project Documentation
```

## ⚙️ Setup & Installation

### 1. Compile the C++ Backend
Navigate to the `cpp_backend` directory and compile the server using a C++17 compatible compiler (like `clang++` or `g++`).

```bash
cd cpp_backend
clang++ -std=c++17 main.cpp motor_simulator.cpp -o backend_server -lpthread
```

### 2. Setup the Python Frontend
Create a virtual environment and install the dashboard dependencies:

```bash
cd ..
python3 -m venv venv
source venv/bin/activate  # On Windows use: venv\Scripts\activate
pip install -r requirements.txt
```

## 🏃‍♂️ Running the Project

You will need two terminal windows to run the system.

**Terminal 1: Start the Backend Server**
```bash
cd cpp_backend
./backend_server
```
*(The backend runs on `http://localhost:8080/api/v1`)*

**Terminal 2: Start the Dashboard**
```bash
source venv/bin/activate
streamlit run dashboard/app.py
```
*(The dashboard runs on `http://localhost:8501`)*

## 📡 REST API Reference

The C++ backend provides several endpoints for interacting with the digital twins:

- `GET /api/v1/motors` - Fetch the current state and health score of all motors.
- `GET /api/v1/telemetry/latest` - Get the most recent telemetry readings.
- `POST /api/v1/faults/inject` - Inject a physical fault into a specific motor.
- `POST /api/v1/faults/clear/{motor_id}/{fault_type}` - Clear an active fault.

## 🔮 Future Roadmap

- **Rule-based & ML Hybrid Anomaly Detection**: Integrating autoencoders to automatically flag deviations.
- **Advanced RUL Prediction**: Estimating Remaining Useful Life based on degradation slopes.
- **External Message Brokers**: Integration with MQTT/Kafka for distributed edge deployments.

---
*Built for advanced Industrial IoT (IIoT) telemetry simulation and predictive maintenance research.*

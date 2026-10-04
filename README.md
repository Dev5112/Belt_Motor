# Industrial Conveyor-Belt Motor Telemetry & Fault Injector

##  Quick Start
```bash
# Navigate to the directory
cd industrial-motor-telemetry

# Set up a virtual environment and install dependencies
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt

# Run the FastAPI Backend in terminal 1
export PYTHONPATH=.
uvicorn app.main:app --reload --port 8000

# Run the Streamlit Dashboard in terminal 2
export PYTHONPATH=.
streamlit run dashboard/app.py
```

## 🔧 Features
- Multi-motor digital twin with Ornstein-Uhlenbeck noise processing
- 10 fault types with physical degradation modeling
- PostgreSQL-grade persistence with DuckDB (WAL enabled, batch inserts)
- Production REST API with FastAPI
- Interactive Streamlit dashboard

## Future Roadmap
- Rule-based + ML hybrid anomaly detection
- Advanced RUL (Remaining Useful Life) prediction
- Integration with external message brokers (MQTT/Kafka)

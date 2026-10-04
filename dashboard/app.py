import streamlit as st
import requests
import pandas as pd
import time
import plotly.express as px
import plotly.graph_objects as go

st.set_page_config(page_title="Motor Telemetry Dashboard", layout="wide", page_icon="⚙️")

API_URL = "http://localhost:8080/api/v1"

def fetch_motors():
    try:
        res = requests.get(f"{API_URL}/motors")
        if res.status_code == 200:
            return res.json()
    except:
        return []
    return []

def fetch_latest_telemetry():
    try:
        res = requests.get(f"{API_URL}/telemetry/latest")
        if res.status_code == 200:
            return res.json()
    except:
        return []
    return []

def inject_fault(motor_id, fault_type, severity, duration, multiplier):
    payload = {
        "motor_id": motor_id,
        "fault_type": fault_type,
        "severity": severity,
        "duration_seconds": duration,
        "intensity_multiplier": multiplier,
        "injection_method": "gradual",
        "recovery_behavior": "exponential",
        "concurrent_fault_allowed": False
    }
    try:
        res = requests.post(f"{API_URL}/faults/inject", json=payload)
        return res.status_code == 200
    except:
        return False

def clear_fault(motor_id, fault_type):
    try:
        res = requests.post(f"{API_URL}/faults/clear/{motor_id}/{fault_type}")
        return res.status_code == 200
    except:
        return False

st.title("⚙️ Industrial Conveyor-Belt Motor Telemetry Dashboard")

tab1, tab2, tab3 = st.tabs(["Overview & Live Monitoring", "Fault Injection", "Historical Analytics"])

with tab1:
    st.header("Real-Time Fleet Status")
    
    col1, col2 = st.columns([1, 2])
    
    motors = fetch_motors()
    if motors:
        with col1:
            for m in motors:
                st.metric(f"Motor {m['motor_id']} Health", f"{m['health_score']:.1f}%", delta_color="inverse")
                st.write(f"State: {m['state']}")
                st.write(f"Bearing Condition: {m['bearing_condition']:.1f}%")
                if m.get('active_faults'):
                    for fault in m['active_faults']:
                        st.error(f"⚠️ FAULT ALERT: {fault} detected!")
                st.divider()
    
    with col2:
        placeholder = st.empty()
        
        # The button simply triggers a rerun of the script, 
        # which will fetch the latest telemetry data naturally.
        st.button("Refresh Telemetry")
        
        data = fetch_latest_telemetry()
        if data:
            df = pd.DataFrame(data)
            
            # Display charts
            fig = go.Figure()
            for motor_id in df['motor_id'].unique():
                motor_data = df[df['motor_id'] == motor_id]
                fig.add_trace(go.Indicator(
                    mode="gauge+number",
                    value=motor_data['temperature_celsius'].iloc[-1],
                    title={'text': f"{motor_id} Temp (°C)"},
                    gauge={'axis': {'range': [None, 180]}, 'bar': {'color': "red"}},
                    domain={'row': 0, 'column': df['motor_id'].unique().tolist().index(motor_id)}
                ))
            fig.update_layout(grid={'rows': 1, 'columns': len(df['motor_id'].unique())})
            st.plotly_chart(fig, use_container_width=True)

with tab2:
    st.header("Fault Injection Control Panel")
    if motors:
        motor_ids = [m['motor_id'] for m in motors]
        selected_motor = st.selectbox("Select Motor", motor_ids)
        
        fault_types = [
            "MOTOR_OVERHEATING", "MOTOR_OVERLOAD", "BEARING_DEGRADATION", 
            "EXCESSIVE_VIBRATION", "RPM_DROP", "BELT_JAM", "VOLTAGE_FLUCTUATION", 
            "BEARING_SEIZURE", "SHAFT_MISALIGNMENT", "WINDING_SHORT_CIRCUIT"
        ]
        selected_fault = st.selectbox("Fault Type", fault_types)
        
        severity = st.select_slider("Severity", options=["LOW", "MEDIUM", "HIGH", "CRITICAL"])
        multiplier = st.slider("Intensity Multiplier", 0.5, 2.0, 1.0)
        duration = st.number_input("Duration (seconds, 0=infinite)", min_value=0, value=60)
        
        col1, col2 = st.columns(2)
        with col1:
            if st.button("Inject Fault", type="primary"):
                if inject_fault(selected_motor, selected_fault, severity, duration, multiplier):
                    st.success(f"Injected {selected_fault} into {selected_motor}")
                else:
                    st.error("Failed to inject fault")
        with col2:
            if st.button("Clear Fault"):
                if clear_fault(selected_motor, selected_fault):
                    st.success(f"Cleared {selected_fault} from {selected_motor}")
                else:
                    st.error("Failed to clear fault")

with tab3:
    st.header("Historical Data (DuckDB)")
    if motors:
        selected_motor_hist = st.selectbox("Select Motor for History", motor_ids, key="hist_motor")
        if st.button("Load History"):
            try:
                res = requests.get(f"{API_URL}/telemetry/{selected_motor_hist}?limit=1000")
                if res.status_code == 200:
                    df = pd.DataFrame(res.json())
                    if not df.empty:
                        df['timestamp'] = pd.to_datetime(df['timestamp'])
                        
                        fig = px.line(df, x='timestamp', y=['temperature_celsius', 'current_ampere', 'vibration_mm_s'])
                        st.plotly_chart(fig, use_container_width=True)
                        
                        st.dataframe(df)
                    else:
                        st.warning("No data found")
            except Exception as e:
                st.error(f"Error loading data: {e}")

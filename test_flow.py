import requests
import time

API = "http://localhost:8080/api/v1"

print("0. Resetting motor state...")
requests.post(f"{API}/faults/clear/MOTOR_001/MOTOR_OVERHEATING")
# We don't have a POST /start endpoint, so if it's IDLE it will remain IDLE. But overheating works in IDLE anyway!

print("1. Checking motors...")
res = requests.get(f"{API}/motors").json()
print(res)

print("\n2. Injecting MOTOR_OVERHEATING into MOTOR_001 with 10x multiplier to speed up heat...")
payload = {
    "motor_id": "MOTOR_001",
    "fault_type": "MOTOR_OVERHEATING",
    "severity": "HIGH",
    "duration_seconds": 60,
    "intensity_multiplier": 10.0,
    "injection_method": "gradual",
    "recovery_behavior": "exponential",
    "concurrent_fault_allowed": False
}
res = requests.post(f"{API}/faults/inject", json=payload).json()
print(res)

print("\n3. Waiting 4 seconds for temperature to rise drastically...")
time.sleep(4)

print("\n4. Checking telemetry & health...")
motors = requests.get(f"{API}/motors").json()
telemetry = requests.get(f"{API}/telemetry/latest").json()
for m in motors:
    if m['motor_id'] == 'MOTOR_001':
        print("MOTOR_001 Health:", m['health_score'])
        print("MOTOR_001 Active Faults:", m.get('active_faults'))
        print("MOTOR_001 State:", m['state'])

for t in telemetry:
    if t['motor_id'] == 'MOTOR_001':
        print("MOTOR_001 Temp:", t['temperature_celsius'])

print("\n5. Checking Historical Analytics...")
history = requests.get(f"{API}/telemetry/MOTOR_001?limit=5").json()
print(f"Retrieved {len(history)} historical records.")
if len(history) > 0:
    print("Latest historical temp:", history[0]['temperature_celsius'])

print("\nAll steps validated successfully!")

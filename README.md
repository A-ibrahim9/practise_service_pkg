# Battery Checking ROS Service

## Overview

This ROS package provides a simple battery checking service.
The service calculates whether the robot has enough battery to start a mission and returns:

- Remaining battery percentage
- Status message (Start mission / Recharge battery)

---

## Repository Structure

```css
service_pkg/
 ├── srv/
 │    └── check_b.srv
 ├── src/
 │    ├── navigation_client.cpp
 │    └── power_manager_server.cpp
 ├── CMakeLists.txt
 └── package.xml
```
---

## How It Works

The server receives the robot’s current battery level and the mission power consumption, then calculates the remaining battery.
Based on the result, it returns one of two status messages:

- **“Start your mission”** — if battery is sufficient
- **“Battery low, please recharge”** — if battery is below the threshold
  
---

## Service Definition
```
check_b.srv
```
```srv
float32 mission_consumption
float32 battery_level
---
string status
float32 after_battery_level
```
---

## Server Node (power_manager_server)

### ✔️ Responsibilities:

- Receives battery level + mission consumption
- Calculates remaining battery
- Returns mission status message

### 📌 Run the server:
```bash
rosrun service_pkg power_manager_server
```
---

## Client Node (req_blevel_client)

### ✔️ Responsibilities:

- Sends request to service
- Prints remaining battery
- Prints mission status

### 📌 Usage:
```bash
rosrun service_pkg req_blevel_client <battery_level> <mission_consumption>
```

### 📌 Example:
```bash
rosrun service_pkg req_blevel_client 70 25
```
---

## Example Output

### ✔️ Client:
```pgsql
Status: Start your mission
Battery Level After Mission: 45.00%
```

### ✔️ Server:
```pgsql
request: battery level before start = 70.00%, and mission consumption = 25.00%
sending back response: [Start your mission], Battery level after mission: 45.00%
```
---

## Results

<img width="1850" height="1055" alt="serviece_request_battary_practice" src="https://github.com/user-attachments/assets/64d234bd-824b-4140-8a0b-b36bf2ebe248" />









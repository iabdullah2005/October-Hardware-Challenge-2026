# October Hardware Challenge 2026

A 31-day challenge focused on building, simulating, documenting, and sharing hardware and embedded-system projects.

The projects are developed using **ESP32** and simulated primarily in **Velxio**.

## Challenge Progress

| Day | Project | Main Components | Status |
|-----|---------|-----------------|--------|
| Day 01 | Environment Data Logging System | ESP32, DHT22 | Completed |
| Day 02 | Automatic Heat Detection System | ESP32, Temperature Sensor, LED, Buzzer | Completed |
| Day 03 | Smart Parking Assistant | ESP32, HC-SR04, Servo, LEDs, Buzzer | Completed |
| Day 04 | Smart Door Lock System | ESP32, 4×4 Keypad, Servo, LEDs, Buzzer | Completed |
| Day 05 | Smart Pedestrian Crossing | ESP32, LCD, Push Button, LEDs, Buzzer | Completed |
| Day 06 | Coming Soon | — | Planned |
| Day 07 | Coming Soon | — | Planned |
| Day 08 | Coming Soon | — | Planned |
| Day 09 | Coming Soon | — | Planned |

---

## Projects

### Day 01 — Environment Data Logging System

An ESP32-based environmental monitoring project using a DHT22 sensor to collect temperature and humidity readings and send timestamped data for analysis.

**Main Hardware:**
- ESP32
- DHT22
- Breadboard
- Jumper wires

> Day 01 was maintained in a separate repository.

---

### Day 02 — Automatic Heat Detection System

A temperature monitoring and alert system that detects abnormal heat conditions and activates visual and audio alerts.

**Main Hardware:**
- ESP32
- Temperature sensor
- LED
- Buzzer

**Simulation:** Velxio

📁 [`Day-02-Automatic-Heat-Detection`](./Day-02-Automatic-Heat-Detection)

---

### Day 03 — Smart Parking Assistant

A parking assistance system that uses an ultrasonic sensor to detect vehicle distance and provide visual and audio feedback.

**Main Hardware:**
- ESP32
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- Red, Yellow and Green LEDs
- Buzzer

**Distance Logic:**

- Above 50 cm → Parking Available
- 20–50 cm → Vehicle Approaching
- Below 20 cm → Vehicle Too Close

**Simulation:** Velxio

📁 [`Day03`](./Day03)

---

### Day 04 — Smart Door Lock System

A keypad-controlled electronic door lock using an ESP32. Users enter a PIN to unlock the system, while LEDs and a buzzer provide access feedback.

**Main Hardware:**
- ESP32
- 4×4 Matrix Keypad
- Servo Motor
- Green LED
- Red LED
- Buzzer

**Default PIN:**

`1234`

**Simulation:** Velxio

📁 [`Day04`](./Day04)

---

### Day 05 — Smart Pedestrian Crossing

A pedestrian crossing controller that combines a push button, traffic LEDs, LCD countdown, and buzzer to simulate a smart road-crossing system.

**Main Hardware:**
- ESP32
- 16×2 I2C LCD
- Push Button
- Red LED
- Yellow LED
- Green LED
- Buzzer

**System Flow:**

```text
ROAD CLEAR
     ↓
Button Pressed
     ↓
GET READY
     ↓
Traffic STOPPED
     ↓
10 Second Countdown
     ↓
CROSS NOW
     ↓
ROAD CLEAR

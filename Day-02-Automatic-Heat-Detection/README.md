# Day 02 — Automatic Heat Detection System

## Overview

The Automatic Heat Detection System is an embedded system designed to monitor temperature and automatically trigger an alert when the temperature exceeds a predefined threshold.

This project was developed as part of my **October Hardware Challenge**, where I am building and documenting a different hardware-based project every day.

## Objective

The objective of this project is to understand how a microcontroller can read temperature data from a sensor and use that data to control output devices automatically.

## Components

* ESP32 DevKit V1
* Temperature sensor
* LED
* Buzzer
* Breadboard
* Jumper wires

## Simulation

The project was designed and tested using **Velxio**.

## How It Works

1. The temperature sensor provides the current temperature to the ESP32.
2. The ESP32 reads and processes the sensor value.
3. The temperature is compared with a predefined threshold.
4. If the temperature exceeds the threshold:

   * The warning LED is activated.
   * The buzzer is activated.
5. When the temperature returns below the threshold, the alert is deactivated.

## Project Structure

```text
Day-02-Automatic-Heat-Detection/
├── sketch.ino
├── diagram.json
├── libraries.txt
├── wokwi-project.txt
└── README.md
```

## Learning Outcomes

Through this project, I practiced:

* ESP32 GPIO control
* Reading sensor data
* Conditional logic
* Digital output control
* Buzzer and LED control
* Hardware simulation
* Basic embedded-system programming

## October Hardware Challenge

**Day 02 / 31**

The goal of this challenge is to build one hardware-focused project every day while gradually learning embedded systems, sensors, actuators, microcontrollers, and hardware interfacing.

---

**Next Project:** Day 03 — Smart Parking Assistant

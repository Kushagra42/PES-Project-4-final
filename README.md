# 🔧 PES Project 4 – Final Submission

> A state machine-based temperature monitoring system using KL25Z and TMP102 sensor, developed as part of an academic course project.

---

## 👥 Created By

- **Vaidehi Salway**
- **Kushagra Pandey**

📅 **Date**: 04-Nov-2019

---

## 📌 Project Overview

This project integrates a **KL25Z Freedom board** with an **I2C-based TMP102 temperature sensor** to demonstrate:

- Finite State Machines (FSM)
- Logging mechanisms with multiple modes
- Sensor data handling and alert mechanisms via LEDs
- Micro Unit Testing for embedded systems

We implemented both:
- ✅ State-Driven State Machine
- ✅ Table-Driven State Machine

---

## ⚙️ Features

- 🟢 **Green LED**: Room temperature detected
- 🔵 **Blue LED**: Sub-zero temperature alert
- 🔴 **Red LED**: Sensor disconnected
- 📤 UART-based logging via MCUXpresso terminal
- 🧪 Micro Unit Test implementation

---

## 📂 Repo Structure

```bash
├── main.c / main.h
├── STATEMACHINE.c / STATEMACHINE.h
├── Table_State_Machine.c / Table_State_Machine.h
├── LED_Blinking.c / LED_Blinking.h
├── Delay_Function.c / Delay_Function.h
├── Logger.c / Logger.h
├── TESTING_CONDITIONS.c / TESTING_CONDITIONS.h
├── uCUnit.c / uCUnit.h
├── I2C_Capture2/
├── README.md

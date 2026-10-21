# Bio-Mimetic Robotic Prosthetic Hand Series

An ongoing personal engineering research and development series focused on the design, 3D printing, and microcontroller programming of an electromechanical robotic hand. This project is structured as a 4-Stage R&D pipeline to systematically transition a low-cost mechanical proof-of-concept into a fully functional, self-powered medical device prototype.

## 🛠️ Project Tech Stack
* **Mechanical CAD:** Autodesk Inventor (Parametric Part Modeling & Assemblies)
* **Embedded Software:** C++ (Arduino IDE)
* **Electrical Control Components:** Microcontrollers (Arduino Uno / ESP32), PWM Actuators, Pull-down Resistor Switching Networks, External DC Power Distribution.

---

## Stage 1: Kinematic Proof-of-Concept & Manual Control (COMPLETED)
**Objective:** Validate structural durability, 3D print joint clearances, and basic tendon-wire actuation pathways using rapid-prototyping, budget-friendly materials.

### Engineering & Testing Milestones:
* **Parametric Design:** Modeled fundamental human finger joint constraints in Autodesk Inventor to optimize range of motion and analyze assembly clearances.
* **Low-Cost Actuation Testing:** Utilized lightweight SG90 micro-servo motors and clear monofilament fishing line to establish a baseline mechanical "pull" profile.
* **Electrical Verification:** Built a breadboard routing network integrating discrete push-buttons with physical pull-down resistors to eliminate digital pin floating and ensure crisp input signal transitions.

### Stage 1 Verification Results:
* Fully assembled structural hand printed and cleared for basic mechanical articulation.
* Successfully validated full finger closing and gripping sequences via button matrix inputs.

### CAD Model Design Architecture:
![Inventor CAD Model](https://github.com/user-attachments/assets/88e24cae-55be-4790-b2c8-86b36b7983c4)


<!-- 📸 PHOTO HINT 2: DRAG AND DROP A PICTURE OF YOUR PHYSICAL BREADBOARDED CIRCUIT WIRE NEST HERE -->
### Breadboard Input Subsystem:
![Circuit Prototyping](https://github.com/user-attachments/assets/824e803b-3c58-429d-baef-3fea7154b7a9)

<!-- 📸 PHOTO HINT 3: DRAG AND DROP A PICTURE OR SHORT GIF OF YOUR COMPLETED SG90 PHYSICAL PRINT MOVING HERE -->
### Assembled Physical Prototype (V1):
[Insert Physical Build Image Here]

---

## Stage 1 Engineering Troubleshooting & Debugging Log

During initial hardware assembly and hardware-in-the-loop (HIL) testing phases, several structural and electrical hurdles were systematically resolved:

### 1. Motor Jitter & Voltage Sag Mitigation
* **The Problem:** When multiple buttons were pressed simultaneously, the servos exhibited erratic jittering, and the microcontroller occasionally reset.
* **The Root Cause:** The servos were pulling peak current directly from the microcontroller's onboard 5V regulator, exceeding its thermal and current thresholds and causing a voltage sag.
* **The Fix:** Isolated the electronic logic power rail from the motor power rail. Integrated a dedicated external DC power supply to feed the servos directly and tied the grounds together to establish a shared reference potential.

### 2. Eliminating Floating Pin State Errors
* **The Problem:** The servos would occasionally trigger randomly without a button being actively pressed.
* **The Root Cause:** The input pins on the microcontroller were left floating when the mechanical switches were open, absorbing ambient static noise and shifting unpredictably between high and low logic states.
* **The Fix:** Rewired the input matrix with solid pull-down resistor configurations, forcing a deterministic electrical state during standby.

---

## Stage 2: Heavy-Duty Industrial Material Upgrades (ACTIVE DEVELOPMENT)
**Objective:** Replace budget components with ruggedized, high-torque industrial hardware to validate weight-bearing grip strength and mechanical reliability.

### Upgraded Specifications:
* **High-Torque Actuators:** Transitioning from plastic SG90s to high-torque, metal-geared **TowerPro MG996R** servo motors to scale structural grip forces.
* **Tendon Tensile Strength:** Replacing monofilament fishing line with high-tensile **braided line** to completely eliminate mechanical stretching under load.
* **Dynamic Tension Springs:** Integrating mechanical tension return springs into the knuckle assemblies to ensure automated joint extension and variable-surface gripping compliance.

---

## 🩺 Stage 3: Analog EMG Signal Control Integration (FUTURE DEVELOPMENT)
**Objective:** Transition the prototype control mechanism away from discrete manual button triggers to autonomous, biological analog signal inputs.

### Technical Milestones:
* **EMG Sensor Integration:** Interface surface electromyography (EMG) muscle sensors to capture microvolt biological potentials from the forearm.
* **Signal Conditioning:** Develop software-based signal filters (such as moving-average or low-pass digital filters) in C++ to smooth out raw analog sensor noise.
* **Custom PCB Layout:** Migrate the current messy breadboard layout into a clean, compact printed circuit board designed in KiCAD to fit seamlessly inside a compact housing cavity.

---

## 🏁 Stage 4: Comprehensive Medical Socket & Internal Power (FINAL MILESTONE)
**Objective:** Finalize the assembly into a wearable, fully integrated, finished medical device package optimized for an end-user amputee.

### Design Targets:
* **Anatomical Socket Design:** Modeled and contoured a custom forearm socket shell featuring integrated internal cavities specifically engineered to seat skin-contact surface EMG sensors comfortably.
* **Independent Internal Power:** Incorporate a high-capacity, rechargeable lithium-ion battery management system (BMS) with integrated safety circuit protections directly into the forearm structure to eliminate the need for external power tethers.
* **Comprehensive Validation:** Execute continuous-cycle stress testing to document battery life profiles, thermal boundaries, and structural joint durability under long-term daily operating conditions.

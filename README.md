# Bio-Mimetic Prosthetic Hand Series

An ongoing personal engineering research and development series focused on the design, 3D printing, and microcontroller programming of an electromechanical robotic hand. This project is structured as a 4-Stage R&D pipeline to transition a low-cost mechanical proof-of-concept into a fully functional, self-powered medical device prototype.

## 🛠️ Project Tech Stack
* **Mechanical CAD:** Autodesk Inventor (Parametric Part Modeling & Assemblies)
* **Embedded Software:** C++ (Arduino IDE)
* **Electrical Control Components:** Microcontrollers (Arduino Uno), SG90 Micro-Servos, Pull-down Resistor Switching Networks, External 5V DC Power Distribution.
---
---

## Stage 1: Kinematic Proof-of-Concept & Manual Control (COMPLETED)
**Objective:** Validate structural durability, 3D print joint clearances, and basic tendon-wire actuation pathways using rapid-prototyping, budget-friendly materials.

### Engineering & Testing Milestones:
* **Parametric Design:** Modeled fundamental human finger joint constraints in Autodesk Inventor to optimize range of motion and analyze assembly clearances.
* **Low-Cost Actuation Testing:** Utilized lightweight SG90 micro-servo motors and clear monofilament fishing line to establish a baseline mechanical "pull" profile.
* **Electrical Verification:** Built a breadboard routing network integrating discrete push-buttons with internal pull-down resistors to eliminate digital pin floating and ensure great input signal transitions.

### Stage 1 Verification Results:
* Fully assembled structural hand printed and cleared for basic mechanical articulation.
* Successfully validated full finger closing and gripping sequences via button matrix inputs.

### CAD Model Design Architecture:
![Inventor CAD Model](https://github.com/user-attachments/assets/88e24cae-55be-4790-b2c8-86b36b7983c4)

### Breadboard Input Subsystem:
![Circuit Prototyping]()

### Assembled Physical Prototype (V1):
![Physical Build]()

## Stage 1 Troubleshooting & Debugging Log

During the initial hardware assembly, kinematic testing, and hardware-in-the-loop (HIL) verification phases, several complex electrical and mechanical hurdles were systematically resolved:

### 1. Eliminating Floating Pin State Errors (Electrical)
* **The Problem:** The servos would occasionally trigger randomly without a button being actively pressed.
* **The Root Cause:** The input pins on the microcontroller were left floating when the mechanical switches were open, absorbing stray electromagnetic ambient noise and shifting unpredictably between high and low logic states.
* **The Fix:** Rewired the input matrix with solid external pull-down resistor configurations to force a deterministic ground state during standby.

### 2. Overcoming Kinematic Joint Jams & Friction Lock (Mechanical)
* **The Problem:** When starting from a completely flat, straight-finger position, the servo motors stalled or struggled to actuate the tendon strings, causing the finger linkages to bind and jam into themselves.
* **The Root Cause:** In a perfectly straight profile, the tendon tensile force vectors were aligned directly parallel to the hinge pin centerlines, resulting in zero initial torque leverage. Combined with high static friction across the 3D-printed joints, the mechanics hit a mathematical vector lock.
* **The Fix:** Redesigned the parametric finger models in Autodesk Inventor to establish a slight, bio-mimetic baseline curvature at rest. This engineered pre-curve ensures an immediate, favorable moment arm for the tendon line to pull against, completely eliminating joint binding, drastically reducing motor strain, and optimizing natural cosmetic aesthetics.

### 3. Decoupling Tendon Tension from Wrist Rotation (Mechanical)
* **The Problem:** Rotating the wrist assembly caused the fingers to unexpectedly clench or hyper-extend, skewing the calibrated servo motor positions.
* **The Root Cause:** The original design routed the tendon lines along the external surface of the forearm. As the wrist joint rotated, the paths of the lines twisted around the outer diameter, artificially tightening or slackening the fishing line and coupling the wrist and finger mechanics together.
* **The Fix:** Engineered a centralized **through-hole routing manifold** positioned directly concentric with the wrist axis of rotation. Passing the tendon strings down through the geometric center of the wrist cylinder ensures that line pathways remain perfectly uniform in length regardless of the hand's rotational angle, completely decoupling the mechanical subsystems.

---
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

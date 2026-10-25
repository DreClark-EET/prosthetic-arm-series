# Bio-Mimetic Prosthetic Hand Series

An ongoing personal engineering research and development series focused on the design, 3D printing, and microcontroller programming of an electromechanical robotic hand. This project is structured as a 5-Stage R&D pipeline to transition a low-cost mechanical proof-of-concept into a fully functional, self-powered medical device prototype.

## Project Tech Stack (So Far)
* **CAD:** Autodesk Inventor (Parametric Part Modeling & Assemblies)
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
* **The Problem:** The servos would occasionally trigger and twitch randomly without a mechanical switch being actively pressed.
* **The Root Cause:** The input pins on the microcontroller were originally left floating when the switches were open. Lacking a fixed voltage reference, the sensitive digital input gates acted like antennae—absorbing ambient electromagnetic noise and fluctuating unpredictably between high and low logic states.
* **The Fix:** Optimized the system architecture by eliminating the need for external hardware resistors. Configured the embedded firmware to utilize the Arduino's internal `INPUT_PULLUP` resistor network within the software setup initialization and re-routed the physical button switches directly to Ground (GND). This guarantees a deterministic, solid 5V (HIGH) reference potential during standby, dropping to a clean 0V (LOW) trigger only upon switch compression, entirely resolving the input noise.


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

## Stage 2: Heavy-Duty Material Upgrades (ACTIVE DEVELOPMENT)
**Objective:** Replace budget components with ruggedized, high-torque hardware to validate weight-bearing grip strength and mechanical reliability. While also continuing to optimize overall design.

### Upgraded Specifications:
* **High-Torque Actuators:** Transitioning from plastic SG90s to high-torque, metal-geared **TowerPro MG996R** servo motors to scale structural grip forces.
* **Tendon Tensile Strength:** Replacing monofilament fishing line with high-tensile **braided line** to completely eliminate mechanical stretching under load.
* **Dynamic Tension Springs:** Integrating mechanical tension return springs into the tendon line system to ensure automated joint extension and gripping while letting servos reach their designated angle.
* **Optimize Overall Design:** Modify servo mounts to be able to fit the **TowerPro MG996R** motors, modify tendon through holes to fit the larger diameter braided line, and improve overall design.

---

## Stage 3: Analog EMG Signal Control Integration (FUTURE DEVELOPMENT)
**Objective:** Transition the prototype control mechanism away from discrete manual button triggers to autonomous, biological analog signal inputs.

### Technical Milestones:
* **EMG Sensor Integration:** Interface surface electromyography (EMG) muscle sensors to capture microvolt biological potentials from the forearm.
* **Signal Conditioning:** Develop software-based signal filters (such as moving-average or low-pass digital filters) in C++ to smooth out raw analog sensor noise.
* **Custom PCB Layout:** Migrate the current messy breadboard layout into a clean, compact printed circuit board designed in KiCAD to fit seamlessly inside a compact housing cavity.

---

## Stage 4: Internal Power Architecture (FUTURE DEVELOPMENT)
**Objective:** Eliminate external power tethers by designing an independent, safely regulated on-board power delivery network.

### Technical Milestones:
* **Lithium-Ion Integration:** Incorporate a high-capacity, multi-cell Lithium-Ion battery bank directly into the forearm structural envelope.
* **Smart Rechargeable System Infrastructure:** Integrate a dedicated USB-C charging interface managed by a lithium charging IC (such as a TP4056 or similar), enabling safe recharging capabilities without removing the battery bank from the housing shell.
* **Battery Management System (BMS):** Integrate a dedicated circuit module to handle cell-balancing, over-voltage/under-voltage protection, and thermal runaway prevention.
* **Voltage Regulation Loops:** Implement high-efficiency buck-boost DC-DC voltage regulators to supply steady 5V/6V lines to the heavy-duty MG996R servos while cleanly isolating power ripples

---

## Stage 5: Comprehensive Medical Socket Integration (FINAL MILESTONE)
**Objective:** Finalize the assembly into a wearable, fully integrated, finished medical device package optimized for an end-user amputee.

### Design Targets:
* **Anatomical Socket Design:** Model and 3D contour a custom, dual-walled forearm prosthetic socket shell engineered to cleanly house all internal actuators, the power bank, and the custom control PCB.
* **Embedded Sensor Matrix:** Map out interior socket guide cavities to firmly seat skin-contact surface EMG sensors comfortably against the residual limb muscles without signal slippage.
* **System-Level Validation Testing:** Execute continuous-cycle stress testing to document battery discharge curves, maximum load lift capacities, and joint durability under long-term daily operating conditions.

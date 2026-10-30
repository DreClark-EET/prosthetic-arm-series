#include <Servo.h>

// --- PIN DEFINITIONS ---
const int servoPin1 = 8;    
const int buttonPin1 = 3;   

const int servoPin2 = 9;    
const int buttonPin2 = 4;   

const int servoPin3 = 10;   
const int buttonPin3 = 5;   

const int servoPin4 = 11;   
const int buttonPin4 = 6;   

const int servoPin5 = 12;   
const int buttonPin5 = 7;   

// --- OBJECTS & STATES ---
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

bool lastButtonState1 = HIGH;
bool isClosed1 = false;

bool lastButtonState2 = HIGH;
bool isClosed2 = false;

bool lastButtonState3 = HIGH;
bool isClosed3 = false;

bool lastButtonState4 = HIGH;
bool isClosed4 = false;

bool lastButtonState5 = HIGH;
bool isClosed5 = false;

void setup() {
  Serial.begin(9600);

  // Setup Button Pins (using built-in pullups)
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);

  // Attach Servos and set initial starting positions
  // SECTION 1: Pinky
  servo1.attach(servoPin1);
  servo1.write(0); // Pin 1: Open position (Reversed)
  // SECTION 2: Ring
  servo2.attach(servoPin2);
  servo2.write(0); // Pin 2: Open position (Reversed)
  // SECTION 3: Middle
  servo3.attach(servoPin3);
  servo3.write(180);   // Pin 3: Open position (Normal)
  // SECTION 4: Pointer
  servo4.attach(servoPin4);
  servo4.write(180);   // Pin 4: Open position (Normal)
  // SECTION 5: Thumb
  servo5.attach(servoPin5);
  servo5.write(180);   // Pin 5: Open position (Normal)
}

void loop() {
  // SECTION 1: Pinky
  int currentButtonState1 = digitalRead(buttonPin1);
  if (currentButtonState1 == LOW && lastButtonState1 == HIGH) {
    isClosed1 = !isClosed1;
    if (isClosed1) {
      servo1.write(150); // Closed angle
    } else {
      servo1.write(0); // Open angle
    }
    delay(200);
  }
  lastButtonState1 = currentButtonState1;

  // SECTION 2: Ring
  int currentButtonState2 = digitalRead(buttonPin2);
  if (currentButtonState2 == LOW && lastButtonState2 == HIGH) {
    isClosed2 = !isClosed2;
    if (isClosed2) {
      servo2.write(180); // Closed angle
    } else {
      servo2.write(0); // Open angle
    }
    delay(200);
  }
  lastButtonState2 = currentButtonState2;

  // SECTION 3: Middle
  int currentButtonState3 = digitalRead(buttonPin3);
  if (currentButtonState3 == LOW && lastButtonState3 == HIGH) {
    isClosed3 = !isClosed3;
    if (isClosed3) {
      servo3.write(0); // Closed angle
    } else {
      servo3.write(180); // Open angle
    }
    delay(200);
  }
  lastButtonState3 = currentButtonState3;

  // SECTION 4: Pointer
  int currentButtonState4 = digitalRead(buttonPin4);
  if (currentButtonState4 == LOW && lastButtonState4 == HIGH) {
    isClosed4 = !isClosed4;
    if (isClosed4) {
      servo4.write(0); // Closed angle
    } else {
      servo4.write(180); // Open angle
    }
    delay(200);
  }
  lastButtonState4 = currentButtonState4;

  // SECTION 5: Thumb
  int currentButtonState5 = digitalRead(buttonPin5);
  if (currentButtonState5 == LOW && lastButtonState5 == HIGH) {
    isClosed5 = !isClosed5;
    if (isClosed5) {
      servo5.write(50); // Closed angle
    } else {
      servo5.write(180); // Open angle
    }
    delay(200);
  }
  lastButtonState5 = currentButtonState5;
}
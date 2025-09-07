#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int button1Pin = 7; // Pin for button 1 (increase angle)
const int button2Pin = 8; // Pin for button 2 (decrease angle)
int servoPosition = 90;   // Starting position of the servo

void setup() {
  myservo.attach(9);               // Attach the servo to pin 9
  myservo.write(servoPosition);     // Start the servo at 90 degrees
  pinMode(button1Pin, INPUT_PULLUP);  // Set button 1 as input with internal pull-up
  pinMode(button2Pin, INPUT_PULLUP);  // Set button 2 as input with internal pull-up
}

void loop() {
  int button1State = digitalRead(button1Pin);  // Read the state of button 1
  int button2State = digitalRead(button2Pin);  // Read the state of button 2

  // If button 1 is pressed, increase the servo angle
  if (button1State == LOW) {          // LOW means button is pressed due to INPUT_PULLUP
    servoPosition += 1;               // Increase servo position
    if (servoPosition > 180) {
      servoPosition = 180;            // Ensure it doesn't go beyond 180 degrees
    }
    myservo.write(servoPosition);     // Move the servo to the new position
    delay(30);                        // Wait for the servo to move
  }

  // If button 2 is pressed, decrease the servo angle
  if (button2State == LOW) {          // LOW means button is pressed due to INPUT_PULLUP
    servoPosition -= 1;               // Decrease servo position
    if (servoPosition < 0) {
      servoPosition = 0;              // Ensure it doesn't go below 0 degrees
    }
    myservo.write(servoPosition);     // Move the servo to the new position
    delay(30);                        // Wait for the servo to move
  }

  delay(50);  // Debounce delay
}

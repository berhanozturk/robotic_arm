#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

//define the joystick pins
int joystick_X1 = A0;
int joystick_Y1 = A1;
int joystick_X2 = A2;
int joystick_Y2 = A3;
//define button pin
int buttonPin = 2;
//define joystick values and button values 
int joystick1XValue;
int joystick1YValue;
int joystick2XValue;
int joystick2YValue;

int buttonState;
int prevButtonState;
//define the positions of the servo motors when the program starts
int servo1Angle = 90;
int servo2Angle = 90;
int servo3Angle = 90;
int servo4Angle = 90;
int servo5Angle = 90;

void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(11);

  pinMode(buttonPin, INPUT_PULLUP);

  prevButtonState = HIGH;

  servo1.write(servo1Angle);
  servo2.write(servo2Angle);
  servo3.write(servo3Angle);
  servo4.write(servo4Angle);
  servo5.write(servo5Angle);
}

void loop() {
  // Read the joystick values
  joystick1XValue = analogRead(joystick1X);
  joystick1YValue = analogRead(joystick1Y);
  joystick2XValue = analogRead(joystick2X);
  joystick2YValue = analogRead(joystick2Y);

  // convert from joystick values to servo angles
  int newServo1Angle = map(joystick1XValue, 0, 1023, 0, 180);
  int newServo2Angle = map(joystick1YValue, 0, 1023, 0, 180);
  int newServo3Angle = map(joystick2XValue, 0, 1023, 0, 180);
  int newServo4Angle = map(joystick2YValue, 0, 1023, 0, 180);


  if (newServo1Angle != servo1Angle) {
    servo1Angle = newServo1Angle;
    servo1.write(servo1Angle);
  }

  if (newServo2Angle != servo2Angle) {
    servo2Angle = newServo2Angle;
    servo2.write(servo2Angle);
  }

  if (newServo3Angle != servo3Angle) {
    servo3Angle = newServo3Angle;
    servo3.write(servo3Angle);
  }

  if (newServo4Angle != servo4Angle) {
    servo4Angle = newServo4Angle;
    servo4.write(servo4Angle);
  }


  buttonState = digitalRead(buttonPin);


  if (buttonState == LOW && prevButtonState == HIGH) {
    servo5Angle = 180 - servo5Angle;
    servo5.write(servo5Angle);
  }

  prevButtonState = buttonState;
}
#include <Servo.h>

Servo baseServo, shoulderServo, elbowServo, wristServo;

int joyX = A0;
int joyY = A1;

void setup() {
  baseServo.attach(9);
  shoulderServo.attach(10);
  elbowServo.attach(11);
  wristServo.attach(12);
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
}

void loop() {
  int xPos = analogRead(joyX);
  int yPos = analogRead(joyY);

  int baseAngle = map(xPos, 0, 1023, 0, 180);
  int shoulderAngle = map(yPos, 0, 1023, 0, 180);

  baseServo.write(baseAngle);
  shoulderServo.write(shoulderAngle);

  delay(15);  // Düzgün hareket için küçük bir gecikme
}

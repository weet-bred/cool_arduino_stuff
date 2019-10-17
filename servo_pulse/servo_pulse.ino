#include <Servo.h>

Servo rightServo;
Servo leftServo;

int rightServoPin = 6;
int leftServoPin = 11;
int powerPin = 13;

void setup() {
  // put your setup code here, to run once:
  rightServo.attach(rightServoPin);
  leftServo.attach(leftServoPin);

  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, HIGH);
  
  //pinMode(rightServoPin, OUTPUT);
  //pinMode(leftServoPin, OUTPUT);
  
  //Serial.begin(9600);
}

void loop() {
  rightServo.write(0);
  leftServo.write(180);
  
  //digitalWrite(rightServoPin, HIGH);
  //delayMicroseconds(pulse);
  //digitalWrite(servoPin, LOW);
  //delay(20);
}

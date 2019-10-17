//to have a big servo powered, there needs to be a red to red and black to black connection, with another ground going to the arduino gnd pin

#include <Servo.h>

int servoPin = 10;
Servo big;

void setup() {
  // put your setup code here, to run once:
  big.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  big.write(180);
  delay(700);
  big.write(0);
  delay(700);
  
}

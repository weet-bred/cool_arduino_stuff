#include <Servo.h>

//Servo big;
int pin = 9;

void setup() {
  // put your setup code here, to run once:
  //big.attach(bigservopin);
}


void loop() {

digitalWrite(pin, HIGH);
delay(1000);
digitalWrite(pin, LOW);
}

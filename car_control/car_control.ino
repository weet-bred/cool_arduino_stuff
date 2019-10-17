#include <Servo.h>
#include <IRremote.h>

int irPin = 7;
IRrecv irrecv(irPin);
decode_results results;

Servo rightServo;
Servo leftServo;

int rightServoPin = 6;
int leftServoPin = 11;
int powerPin = 13;

int leftSpeed = 180;
int rightSpeed = 15;

/*
int IRright = 23205;
int IRleft  = 25979;
int IRup    = 6375;
int IRok    = 14535;
int IRzero  = 15355;
int IRone   = 9755;
int IRtwo   = 7611;
int IRthree = 28031;
*/
int drivespeed = 1;
int movement = -2;
int delaylen = 1000;

void setup() {
  // put your setup code here, to run once:
  rightServo.attach(rightServoPin);
  leftServo.attach(leftServoPin);

  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, HIGH);

  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  
}

void moveleft(int delaylen) {
  rightServo.write(rightSpeed);
  leftServo.write(90);
  delay(delaylen);
  return;
}

void moveright(int delaylen) {
  rightServo.write(90);
  leftServo.write(leftSpeed);
  delay(delaylen);
  return;
}

void moveforward(int delaylen) {
  rightServo.write(rightSpeed);
  leftServo.write(leftSpeed);
  delay(delaylen);
  return;
}

void movestop(int delaylen) {
  leftServo.write(90);
  rightServo.write(90);
  delay(delaylen);
}

void loop() {

  moveforward(1000);
  //the right servo is slower than the left one for some reason. probably not enough power
  moveright(1150);
  moveleft(1000);
  movestop(1000);

  /*if (irrecv.decode(&results)){
    dir = results.value;
    Serial.println(dir);
    movement = 0 - movement;
    irrecv.resume();
  }
  */
  
  
    
  
}

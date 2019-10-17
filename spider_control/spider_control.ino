#include <Servo.h>

//each var wil control 2 servos
Servo frontLeft1;
Servo frontLeft2;
Servo backLeft1;
Servo backLeft2;

Servo frontRight1;
Servo frontRight2;
Servo backRight1;
Servo backRight2;

//different speeds for the servos
int fast = 300;
int med = 500;
int slow = 1000;

int frontLeft1pin = 2;
int frontLeft2pin = 3;
int backLeft1pin = 4;
int backLeft2pin = 5;

int frontRight1pin = 8;
int frontRight2pin = 9;
int backRight1pin = 12;
int backRight2pin = 11;

int walkspeed = med;
int input = 1;

void setup() {
  // attach each servo and move to the initial position
  
  frontLeft1.attach(frontLeft1pin);
  frontLeft2.attach(frontLeft2pin);
  backLeft1.attach(backLeft1pin);
  backLeft2.attach(backLeft2pin);
  frontLeft1.write(0);
  frontLeft2.write(0);
  backLeft1.write(0);
  backLeft2.write(0);

  frontRight1.attach(frontRight1pin);
  frontRight2.attach(frontRight2pin);
  backRight1.attach(backRight1pin);
  backRight2.attach(backRight2pin);
  frontRight1.write(0);
  frontRight2.write(0);
  backRight1.write(0);
  backRight2.write(0);
  
  delay(5000);
  
}

void loop() {
  /*
  if (input == 0)
  {
    walkspeed = fast;
  }
  else if (input == 1)
  {
    walkspeed = med;
  }
  else if (input == 2)
  {
    walkspeed = slow;
  }
  */
  
  backLeft1.write(60);
  //delay(walkspeed/2);
  frontLeft1.write(80);
  delay(walkspeed);
  
  backLeft2.write(0);
  delay(walkspeed/2);
  frontLeft2.write(20);
  delay(walkspeed/2);
  
  backLeft1.write(80);
//  delay(walkspeed/2);
  frontLeft1.write(60);
  delay(walkspeed/2);
  
  backLeft2.write(20);
  delay(walkspeed/2);
  frontLeft2.write(0);
  delay(walkspeed/2);

  //right

  frontRight1.write(60);
  //delay(walkspeed/2);
  backRight1.write(80);
  delay(walkspeed);
  
  frontRight2.write(0);
  delay(walkspeed/2);
  backRight2.write(20);
  delay(walkspeed/2);
  
  frontRight1.write(80);
//  delay(walkspeed/2);
  backRight1.write(60);
  delay(walkspeed/2);
  
  frontRight2.write(20);
  delay(walkspeed/2);
  backRight2.write(0);
  delay(walkspeed/2);
  
}

//////////////////////////////////////////
/////////////// SETTING UP ///////////////
//////////////////////////////////////////

//spiderbot control script by Peter Engels, 9/24/18

#include <Servo.h>
//#include <IRremote.h>

/*//set up the infrared and signal definitions
int irPin = 13;
IRrecv irrecv(irPin);
decode_results results;
// button = signal
//int IRdown  = 16730805;
int IRright = 16734885;
int IRleft  = 16716015;
int IRup    = 16718055;
int IRok    = 16726215;
int IRzero  = 16750695;
int IRone   = 16753245;
int IRtwo   = 16736925;
int IRthree = 16769565;
/*int four  = 16720605; //don't need these right now
int five  = 16712445;
int six   = 16761405;
int seven = 16769055;
int eight = 16754775;
int nine  = 16748655;
int star  = 16738455;
//int hash  = 16756815;
*/

//each var wil control a servo
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
int med  = 500;
int slow = 1000;

//choose which function to run
char whichfunc[10];

// MOVEMENT DEFINITIONS
  //for *left1, 60 = down, 80 = up
  //for *Right1, 120 = up, 100 = down
  //for *Left2, 0 = back, 20 = forward
  //for *Right2, 0 = back, 20 = forward
int leftdown = 80;
int leftup = 100;
int rightdown = 80;
int rightup = 100;
int back = 0;
int forward = 20;

// pin definitions for the servos
int frontLeft1pin = 2;
int frontLeft2pin = 3;
int backLeft1pin = 4;
int backLeft2pin = 5;

int frontRight1pin = 8;
int frontRight2pin = 9;
int backRight1pin = 10;
int backRight2pin = 11;

//just so it exists
int walkspeed = fast;
//int dir;

void setup() {
  // attach each servo and move to the initial position

  //attach the whole left side
  frontLeft1.attach(frontLeft1pin);
  frontLeft2.attach(frontLeft2pin);
  backLeft1.attach(backLeft1pin);
  backLeft2.attach(backLeft2pin);
  //set them all to straight down
  frontLeft1.write(0);
  frontLeft2.write(0);
  backLeft1.write(0);
  backLeft2.write(0);

  //attach the whole right side
  frontRight1.attach(frontRight1pin);
  frontRight2.attach(frontRight2pin);
  backRight1.attach(backRight1pin);
  backRight2.attach(backRight2pin);
  //set them all to straight down
  frontRight1.write(180);
  frontRight2.write(0);
  backRight1.write(180);
  backRight2.write(0);

  /*//start talking to the IR receiver
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
*/
  walkspeed = fast;
  //dir=IRup;
  
  delay(5000);
  
}

/////////////////////////////////////////
/////////////// FUNCTIONS ///////////////
/////////////////////////////////////////

void updown() { // move up and down (called by the other functions)
  //move up and down left side
  backLeft1.write(leftdown);
  delay(walkspeed/4);
  frontLeft1.write(leftup);
  delay(walkspeed/4);
  //move up and down right side
  frontRight1.write(rightup);
  delay(walkspeed/4);
  backRight1.write(rightdown);
  delay(walkspeed/4);
  return;
}

void downup() { //move up and down part 2 
  //move down and up left side
  backLeft1.write(leftup);
  delay(walkspeed/4);
  frontLeft1.write(leftdown);
  delay(walkspeed/4);
  
  //move down and up right side
  frontRight1.write(rightdown);
  delay(walkspeed/4);
  backRight1.write(rightup);
  delay(walkspeed/4);
  return;
}

void moveforward() { // move forward normally  

  updown();
  
  //move forward and back left legs
  backLeft2.write(back);
  delay(walkspeed/4);
  frontLeft2.write(forward);
  delay(walkspeed/4);
  //move forward and back right legs
  frontRight2.write(back);
  delay(walkspeed/4);
  backRight2.write(forward);
  delay(walkspeed/4);

  downup();
  
  //move back and forward left legs
  backLeft2.write(forward);
  delay(walkspeed/4);
  frontLeft2.write(back);
  delay(walkspeed/4);
  //move backward and forward right legs
  frontRight2.write(forward);
  delay(walkspeed/4);
  backRight2.write(back);
  delay(walkspeed/4);
  
  return;
}
/*
void moveleft() { // move left
  
  //move up and down
  updown();

  //move forward and back left legs
  backLeft2.write(back);
  frontLeft2.write(forward/2);
  //move forward and back right legs
  frontRight2.write(back);
  backRight2.write(forward);
  delay(walkspeed);
  
  //move down and up
  downup();
  
  //move back and forward left legs
  backLeft2.write(forward/2);
  frontLeft2.write(back);
  //move backward and forward right legs
  frontRight2.write(forward);
  backRight2.write(back);
  delay(walkspeed);
  
  return;
}

void moveright() { // move right
  
  //move up and down
  updown();
  
  //move forward and back left legs
  backLeft2.write(back);
  frontLeft2.write(forward);
  //move forward and back right legs
  frontRight2.write(back);
  backRight2.write(forward/2);
  delay(walkspeed);
  
  //move down and up
  downup();
  
  //move back and forward left legs
  backLeft2.write(forward);
  frontLeft2.write(back);
  //move backward and forward right legs
  frontRight2.write(forward/2);
  backRight2.write(back);
  delay(walkspeed);
  
  return;
}
/*
void movestop() { //don't move anything
  //literally just wait
  delay(1000);
  return;
}
*/
void loop() {
moveforward();
  
  /*
if (irrecv.decode(&results)){
    dir = results.value;
    Serial.println(dir);
    irrecv.resume();
  }

  /*
    if (dir == IRright) {
      moveright(); }
    else if (dir == IRleft) {
      moveleft(); }
    else if (dir == IRup) {
      moveforward(); }
    else if (dir == IRzero) {
       movestop(); }
    else if (dir == IRone) {
       walkspeed = slow; }
    else if (dir ==  IRtwo) {
       walkspeed = med; }
    else if (dir == IRthree) {
       walkspeed = fast; }
  */
}

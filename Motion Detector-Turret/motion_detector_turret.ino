#include <Servo.h>
int horizontal = 90;
int vertical = 90;

Servo vServo;
Servo hServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  vServo.attach(9);
  hServo.attach(11);

  vServo.write(90);
  hServo.write(90);
}

void loop() {
   handleSerial();
   
   //Serial.println("HZ: " + horizontal);
   //Serial.println("VZ: " + vertical);
   delay(200);
}
 
void handleSerial() {
 while (Serial.available() > 0) {
   char incomingCharacter = Serial.read();
   if (incomingCharacter > 10) 
   switch (incomingCharacter) {
     case '1':
      left();
      break;
     case '2':
      right();
      break;
     case '3':
      up();
      break;
     case '4':
      down();
      break;
     case '5':
      reset();
      break;
     case '6':
      up90();
      break;
     case '7':
      hzero();
      break;
     case '8':
      vzero();
      break;
     case '9':
      h90();
      break;
      
     case '11':
      fastLeft();
      break;
     case '12':
      fastRight();
     case '13':
      fastUp();
     case '14':
      fastDown;

      case '15':
      slowLeft();
      break;
     case '16':
      slowRight();
      break;
     case '17':
      slowUp();
      break;
     case '18':
      slowDown();
      break;
    }
  }
}

void left() {
  if (horizontal <= 110) {
    horizontal += 5;
    hServo.write(horizontal);
  }
}

void right() {
  if (horizontal >= 75) {
    horizontal -= 5;
    hServo.write(horizontal);
  }
}

void up() {
  if (vertical <= 130) {
    vertical += 5;
    vServo.write(vertical);
  }
}

void down() {
  if (vertical >= 75) {
    vertical -= 5;
    vServo.write(vertical);
  }
}

void reset() {
  vServo.write(0);
  hServo.write(0);
  horizontal = 0;
  vertical = 0;
}

void up90() {
  vertical = 90;
  vServo.write(90);
}

void h90() {
  horizontal = 90;
  hServo.write(90);
}

void hzero() {
  horizontal = 0;
  hServo.write(0);
}

void vzero() {
  vertical = 0;
  vServo.write(0);
}

void fastUp() {
  if (vertical <= 120) {
  vertical += 15;
  vServo.write(vertical);  
  }
}
void fastDown() {
  if (vertical >= 110) {
    vertical -= 15;
    vServo.write(vertical);
  }
}
void fastLeft() {
  if (horizontal <= 100) {
    horizontal += 15;
    hServo.write(horizontal);
  }
}
void fastRight() {
  if (horizontal >= 85) {
    horizontal -= 15;
    hServo.write(horizontal);  
  }
}

void slowUp() {
  if (vertical < 180) {
    vertical += 1;
    vServo.write(vertical);  
  }
}
  
void slowDown() {
  vertical -= 1;
  vServo.write(vertical);
}
void slowLeft() {
  horizontal += 1;
  hServo.write(horizontal);
}
void slowRight() {
  horizontal -= 1;
  hServo.write(horizontal);
}

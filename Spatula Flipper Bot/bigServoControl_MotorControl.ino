#include <Servo.h>

Servo orange;
Servo yellow;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  orange.attach(10);
  yellow.attach(12);
}

void loop() {
   handleSerial();
   
   delay(200);
}

//functions have to be above the handleSerial() function or it bugs out
void up() {
  yellow.write(0);
  orange.write(180);
}

void down() {
  yellow.write(180);
  orange.write(0);
}


void yellow0() {
  yellow.write(0);
}

void yellow180() {
  yellow.write(180);

}

void orange0() {
  orange.write(0);
}

void orange180() {
  orange.write(180);

} 
void handleSerial() {
 while (Serial.available() > 0) {
   char incomingCharacter = Serial.read();
   switch (incomingCharacter) {
     case '1':
      up();
      break;
     case '2':
      down();
      break;
     case '3':
      orange0();
      break;
     case '4':
      orange180();
      break;
    }
  }
}

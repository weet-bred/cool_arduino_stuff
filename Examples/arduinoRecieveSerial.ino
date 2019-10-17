
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
   handleSerial();
   
   delay(200);
}

//functions have to be above the handleSerial() function or it bugs out

//turn the LED on 
void on() {
  digitalWrite(13, HIGH);  
}

//turn the LED off
void off() {
  digitalWrite(13, LOW);

}
 
void handleSerial() {
 while (Serial.available() > 0) {
   char incomingCharacter = Serial.read();
   if (incomingCharacter > 10) 
   switch (incomingCharacter) {
     case '1':
      on();
      break;
     case '2':
      off();
      break;
    }
  }
}

#include <IRremote.h>

int irPin = 7;
IRrecv irrecv(irPin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)){
    Serial.println(results.value);
    irrecv.resume();
  }
}

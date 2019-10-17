void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a0pin = 0;
  a0pin = digitalRead(A0);
  int pintwo = 0;
  pintwo = digitalRead(2);
  //Serial.println("A0 ");
  Serial.println(a0pin);
  //Serial.println("2");
  //Serial.println(pintwo);
  delay(1000);
}

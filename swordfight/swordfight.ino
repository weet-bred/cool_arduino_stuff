#include <Servo.h> // this adds the "Servo" library to the program
 
// the following creates two servo objects
Servo leftMotor;
Servo rightMotor;

void setup()
{
    leftMotor.attach(9);
    rightMotor.attach(11);
    Serial.begin(9600);
} 
 
void loop()
{
    int sensorValueLeft = analogRead(A5);
    float degree = (sensorValueLeft * (120 / 1023.0)) + 100;
    leftMotor.write(degree);
    int sensorValueRight = analogRead(A0);
    degree = (sensorValueRight * (120 / 1023.0)) + 100;
    rightMotor.write(degree);
    Serial.println(degree);

    //delay(500);
}

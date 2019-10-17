#include <Servo.h> // this adds the "Servo" library to the program
 
// the following creates two servo objects
Servo leftMotor;
Servo rightMotor;


void setup()
{
    leftMotor.attach(9);
    rightMotor.attach(11);
}
 
 
void loop()
{
    leftMotor.write(70);
    delay(1000);
    rightMotor.write(110);
    delay(1000);
    leftMotor.write(110);
    delay(1000);
    rightMotor.write(70);
    delay(1000);
}

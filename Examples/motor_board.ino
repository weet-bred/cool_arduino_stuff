/*

For setup, connnect the motors to the motor board appropriately. Connect motor board to an external power source, and attach it to the top of the arduino


Documentation for an older version of the board here: https://www.dfrobot.com/wiki/index.php/Arduino_Motor_Shield_(L298N)_(SKU:DRI0009)

Pin 4 = M1 = Motor 1 Directional Control
Pin 5 = E1 = Motor 1 PWM Control
Pin 6 = E2 = Motor 2 PWM Control
Pin 7 = M2 = Motor 2 Direction Control

Truth Table:

E1    M1
L     X   Motor 1 disabled
PWM   L   Motor 1 PWM Speed Forward
PWM   H   Motor 1 PWM Speed Backward

E2    M2
L     X   Motor 2 disabled
PWM   H   Motor 2 PWM Speed Forward
PWM   L   Motor 2 PWM Speed Backward

H is HIGH, L is LOW, PWM is PWM Signal, X is any voltage
PWM Values are 0 to 255

*/

//Arduino PWM Speed Control：
int E1 = 5;  
int M1 = 4; 
int E2 = 6;                      
int M2 = 7;                        

void setup() 
{ 
    pinMode(M1, OUTPUT);
    pinMode(M2, OUTPUT); 
} 

//Forward
void forward()
{
  digitalWrite(M1, LOW);   
  digitalWrite(M2, HIGH);
}

//Backward
void backward()
{
  digitalWrite(M1, HIGH);   
  digitalWrite(M2, LOW);
}
//Turn Right
void right()
{
  digitalWrite(M1, LOW);   
  digitalWrite(M2, LOW);
}

//Turn Left
void left()
{
  digitalWrite(M1, HIGH);   
  digitalWrite(M2, HIGH);
}
void loop() 
{ 
  analogWrite(E1, 255);   //PWM Speed Control
  analogWrite(E2, 255);   //PWM Speed Control
  
  
  forward();     
  delay(3000); 
  
  backward();
  delay(3000);
  
  right();
  delay(3000); 
  
  left();
  delay(3000); 
    

}

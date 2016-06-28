#include <Servo.h>
Servo myServo;
int sensorVal = 0;
int angle = 0;
void setup()
{
  //Servo myServo;
  myServo.attach(9);
  Serial.begin(9600);

}

void loop()
{
  //myServo.attach(9);
  const int sensorPin = A0;
 
  sensorVal = analogRead(sensorPin);
  angle = map(sensorVal,0,1023,0,179);
  
  Serial.print("\t");
  Serial.print(angle);
  
  myServo.write(angle);
  delay(15);
  
}

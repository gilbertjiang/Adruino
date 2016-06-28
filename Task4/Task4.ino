void setup()
{ 
  Serial.begin(9600);
  
  const int LEDPinRed = 11;
  const int LEDPinGreen = 9;
  const int LEDPinBlue = 10;
  
  //assign output pins
  pinMode(LEDPinRed,OUTPUT);
  pinMode(LEDPinGreen,OUTPUT);
  pinMode(LEDPinBlue,OUTPUT);
}

void loop()
{
  int redValue = 0;
  int greenValue = 0;
  int blueValue = 0;
  
  //assign pin numbers
  const int sensorPinRed = A0;
  const int sensorPinGreen = A1;
  const int sensorPinBlue = A2;
  
  const int LEDPinRed = 11;
  const int LEDPinGreen = 9;
  const int LEDPinBlue = 10;
  
  //declare sensor values
  int sensorValRed = 0;
  int sensorValGreen = 0;
  int sensorValBlue = 0;
  
  //read photo resister sensors values
  sensorValRed = analogRead(sensorPinRed);
  delay(250);
  sensorValGreen = analogRead(sensorPinGreen);
  delay(250);
  sensorValBlue = analogRead(sensorPinBlue);
  delay(250);
  
  //printout sensor values
  Serial.print("Red sensor value: ");
  Serial.print(sensorValRed);
  Serial.print("\t Green sensor value: ");
  Serial.print(sensorValGreen);
  Serial.print("\t Blue sensor value: ");
  Serial.print(sensorValBlue);
  
  redValue = sensorValRed/4;
  greenValue = sensorValGreen/4;
  blueValue = sensorValBlue/4;
  
  analogWrite(LEDPinRed, redValue);
  analogWrite(LEDPinGreen, greenValue);
  analogWrite(LEDPinBlue, blueValue);
}

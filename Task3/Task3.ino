void setup(){
  Serial.begin(9600); //open a serial port to view sensor data
  
  for(int pinNumber = 3; pinNumber<6; pinNumber++)
  {
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  
}

void loop()
{
  const int sensorPin = A0;
  const float baselineTemp = 25.0;
  int sensorVal = analogRead(sensorPin);
  Serial.print("Temperature Sensor Value: ");
  Serial.print(sensorVal);
  
  //convert ADC to voltage
  float voltage = (sensorVal/1024.0)*5.0;
  Serial.print(", Sensor Voltage: ");
  Serial.print(voltage);
  
  //conver voltage to degree C
  float temperature = (voltage-0.5)*100;
  Serial.print(", Degree C: ");
  Serial.print(temperature);
  
  if (temperature<baselineTemp){
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  else if(temperature>=baselineTemp && temperature<baselineTemp+2)
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
    else if(temperature>=baselineTemp+2 && temperature<=baselineTemp+4)
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  }
    else if(temperature>=baselineTemp+4)
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  }
  delay(250);
}

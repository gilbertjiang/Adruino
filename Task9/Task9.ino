const int inputPin = 12;
const int outputPin = 9;
boolean theSwitch = LOW;
void setup()
{
  pinMode(inputPin,INPUT);
  pinMode(outputPin,OUTPUT);
}

void loop()
{
  theSwitch = digitalRead(inputPin);
  if(theSwitch == HIGH)
  {
    digitalWrite(outputPin,HIGH);
  }
  else
  {
    digitalWrite(outputPin,LOW);
  }
  delay(20);
}

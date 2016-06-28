const int sensorPin = A0;
const int tonePin = 9;
int sensorVal = 0;
int high=0;
int low=1023;
void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);
  Serial.begin(9600);

  while(millis()<5000)
  {
    sensorVal = analogRead(sensorPin);
    delay(20);
    if(sensorVal > high)
    {
      high = sensorVal;
    }
    if(sensorVal < low)
    {
      low = sensorVal;
    }
  }
  digitalWrite(13,HIGH);
}

void loop()
{
  sensorVal = analogRead(sensorPin);
  delay(20);

  //Serial.print("sensor value for photoresistor: ");
  //Serial.print(sensorVal);
  //Serial.print("\t");

  int pitch = map(sensorVal,low,high,50,4000);
  tone(9,pitch,20);
 }

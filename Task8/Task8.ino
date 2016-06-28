int previousSwitchState = LOW;
unsigned long previousTime=0;
unsigned long currentTime=0;
int led = 4;
void setup(){
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, INPUT);
}

void loop(){
  int pin = 0;
  int interval = 3000;
  currentTime = millis();
  int switchState = digitalRead(13);
  unsigned long currentTime = millis();
  if (switchState!=previousSwitchState)
  {
    for (pin=4;pin<8;pin++)
    {
      digitalWrite(pin,LOW);
    }
    led=4;
  }
  if(currentTime-previousTime>interval)
  {
    previousTime = currentTime;
    digitalWrite(led,HIGH);
    led++;
    
    if (led == 8)
    {
      led=4;
    }
  }
  previousSwitchState = switchState;
}

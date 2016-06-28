const int enablePin = 10;
const int controlPin1 = 9;
const int controlPin2 = 4;
const int directionSwitchPin = 12;
const int enableSwitchPin = 11;
boolean directionSwitch = LOW;
boolean enableSwitch = LOW;
boolean previousDirectionSwitch = LOW;
boolean previousEnableSwitch = LOW;
int motorEnabled = 0;
int motorDirection = 0;
int motorSpeed = 0;
int sensorVal = 0;

void setup(){
  pinMode(enablePin, OUTPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(directionSwitchPin, INPUT);
  pinMode(enableSwitchPin, INPUT);
  digitalWrite(enablePin, LOW);
  
  //Serial.begin(9600);
}

void loop(){
  sensorVal = analogRead(A0);
  motorSpeed = sensorVal/4; //motor speed
  directionSwitch = digitalRead(directionSwitchPin);
  delay(1);
  enableSwitch = digitalRead(enableSwitchPin);
  
  //set enablePin
  if (enableSwitch == HIGH && previousEnableSwitch == LOW)
  {
    motorEnabled = !motorEnabled;
    previousEnableSwitch = enableSwitch; 
  }
  
  //set enablePin
  if (motorEnabled == 1)
  {
    analogWrite(enablePin, motorSpeed);
  }
  else
  {
    digitalWrite(enablePin, LOW);
  }
  
  //set motor direction
    if (directionSwitch == HIGH && previousDirectionSwitch == LOW)
    {
      motorDirection = !motorDirection;
      previousDirectionSwitch = directionSwitch;
    }
    
    if(motorDirection == 1)
    {
      digitalWrite(controlPin1, HIGH);
      digitalWrite(controlPin2, LOW);
    }
    else if(motorDirection == 0)
    {
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, HIGH);
    }
    //delay(300);
  //Serial.print("\t motorspeed: ");
  //Serial.print(motorSpeed);
  //Serial.print("\t motorEnabled: ");
  //Serial.print(motorEnabled);
  //Serial.print("\t motorDirection: ");
  //Serial.print(motorDirection);
}

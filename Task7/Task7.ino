void setup(){
  Serial.begin(9600);
}

void loop(){
  const int sensorPin = A0;
  int sensorVal = analogRead(sensorPin);
  
  int notes[] = {262, 294, 330, 349};
  Serial.print("\t");
  Serial.print(sensorVal);
  
  if(sensorVal<=1023 && sensorVal>1020){
    tone(8, notes[0]);
  }
  else if(sensorVal<=1004 && sensorVal>1000){
    tone(8, notes[1]);
  }
  else if(sensorVal<=520 && sensorVal>500){
    tone(8, notes[2]);
  }
  else if(sensorVal<=20 && sensorVal>0){
    tone(8, notes[3]);
  }
  else{
    noTone(8);
  }
  delay(10);
}

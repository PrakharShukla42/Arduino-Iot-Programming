int IRSensor = 3;
int LED = 11;
void setup() 
{
  pinMode (IRSensor, INPUT); 
  pinMode (LED, OUTPUT); 
}

void loop()
{  
  int Sensordata = digitalRead (IRSensor);  
  Serial.print("Sensor value:");
  Serial.println(Sensordata);
  
  if (Sensordata==1)
  {
    digitalWrite(LED, HIGH);
  }
  else 
  {
    digitalWrite(LED, LOW);
  }
  
}
int LED=2;
int BUZZ=3;
int IR=6;
void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUZZ,OUTPUT);
  pinMode(IR,INPUT);
}

void loop()
{
  if(digitalRead(IR)==1)
  {
  Serial.print("Motion Detected");
  digitalWrite(LED, HIGH);
  digitalWrite(BUZZ, HIGH);
  }
  else
  {
    Serial.print("Motion Not Detected");
    digitalWrite(LED,LOW);
    digitalWrite(BUZZ,LOW);
  }
}

int LED =12;
int BUZZ=2;
int ir=6;
void setup()
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(BUZZ,OUTPUT);
  pinMode(ir,INPUT);
  }
void loop(){
  if(digitalRead(ir)==1)
  {
    Serial.print("motion detects");
    digitalWrite(LED,HIGH);
    digitalWrite(BUZZ,HIGH);
  }
  else
  {
    Serial.print("not detected");
    digitalWrite(LED,LOW);
    digitalWrite(BUZZ,LOW);
    }
}

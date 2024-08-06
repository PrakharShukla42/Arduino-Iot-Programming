int tem;
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
}
void loop()
{
  tem=analogRead(A0);
  Serial.print(tem);
  Serial.print("\nDegree");
}
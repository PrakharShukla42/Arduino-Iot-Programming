int light;
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
}
void loop()
{
  light=analogRead(A0);
  Serial.print(light);
  Serial.print("\nintensity");
}
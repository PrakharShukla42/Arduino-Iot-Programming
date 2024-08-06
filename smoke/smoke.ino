int gas;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);

}

void loop() {
   gas=analogRead(A0);
   Serial.println(gas);
}

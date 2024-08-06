#include <TinyDHT.h>
#define DHTTYPE DHT11
#define DHTPIN 4  

DHT dht(DHTPIN,DHTTYPE);
void setup() {
  Serial.begin(9600);
}

void loop() 
{
  delay(2000);
  float humidity=dht.readHumidity();
  float Celcius=dht.readTemperature();
  float Farenheit=dht.readTemperature(true);
  Serial.println("Humdity");
  Serial.println(humidity);
  Serial.println("Temerature In Celcius");
  Serial.println(Celcius);
  Serial.println("Temperature In Farenheit");
  Serial.println(Farenheit);
}

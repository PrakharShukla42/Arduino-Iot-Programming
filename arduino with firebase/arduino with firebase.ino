#define FIREBASE_HOST "your-firebase-project-id.firebaseio.com"
#define FIREBASE_AUTH "Your_Firebase_Database_Secret"
#define WIFI_SSID "Your WiFi SSID"
#define WIFI_PASSWORD "Your WiFi Password"
#include <Arduino_LSM6DS3.h>
#include <Firebase_Arduino_WiFiNINA.h>
#define FIREBASE_HOST "your-firebase-project-id.firebaseio.com"
#define FIREBASE_AUTH "Your_Firebase_Database_Secret"
#define WIFI_SSID "Your WiFi SSID"
#define WIFI_PASSWORD "Your WiFi Password"
FirebaseData firebaseData;
String path = "/IMU_LSM6DS3";
String jsonStr;
void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println();
  Serial.print("Initialize IMU sensor…");
  if (!IMU.begin()) {
    Serial.println(" failed!");
    while (1);
  }
  Serial.println(" done");
  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.print("Connecting to WiFi…");
  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print(".");
    delay(300);
  }
  Serial.print(" IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASSWORD);
  Firebase.reconnectWiFi(true);
}
void loop()
{
  float x, y, z;
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    if (Firebase.setFloat(firebaseData, path + "/1-setFloat/X", x)) {
      Serial.println(firebaseData.dataPath() + " = " + x);
    }
    if (Firebase.setFloat(firebaseData, path + "/1-setFloat/Y", y)) {
      Serial.println(firebaseData.dataPath() + " = " + y);
    }
    if (Firebase.setFloat(firebaseData, path + "/1-setFloat/Z", z)) {
      Serial.println(firebaseData.dataPath() + " = " + z);
    }
    jsonStr = "{\"X\":" + String(x,6) + ",\"Y\":" + String(y,6) + ",\"Z\":" + String(z,6) + "}";
    if (Firebase.pushJSON(firebaseData, path + "/2-pushJSON", jsonStr)) {
      Serial.println(firebaseData.dataPath() + " = " + firebaseData.pushName());
    }
    else {
      Serial.println("Error: " + firebaseData.errorReason());
    }

    Serial.println();
    delay(2000);
  }
}
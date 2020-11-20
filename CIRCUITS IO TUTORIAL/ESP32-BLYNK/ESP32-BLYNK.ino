#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_PRINT Serial

int L1 =21;

//Get Auth Token from Blynk App by your email.
char auth[]="Auth token here";

//your WiFi credentials.
//set pasword to " " for open networks.
char ssid[] =  "wifi name";
char pass[] = "wifi password";

void setup(){
  pinMode(L1, OUTPUT);
  pinMode(L1, HIGH);
  Serial.begin(115200);

  delay(10);
  Serial.print("Connecting to...");
  Serial.print(ssid);

  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected.");
  Blynk.begin("Your auth token key", ssid, pass);
}

void loop(){
  Blynk.run();
}

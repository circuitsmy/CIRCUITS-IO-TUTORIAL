#include "WiFi.h"

void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.begin("wifi name here" , "wifi password here");

    Serial.println("Connecting WiFi...");
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("");
      Serial.println("WiFi connected");
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());
    }
    
}

void loop(){
  if (WiFi.status() != WL_CONNECTED) {
      Serial.println("WiFi not connected");
      delay(1000); 
  }   
}

#include <WiFi.h>
#include <HTTPClient.h>
// Replace with your network credentials
const char* ssid     = "shawaltechnologies@unifi";
const char* password = "st7418960";


void setup() {
  Serial.begin(115200);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  //WiFi.softAP("esp32 wifi","1234567890");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  HTTPClient http;   
   http.begin("http://api.circuits.my/input1.php");  //Specify destination for HTTP request
   http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header
   int httpResponseCode = http.POST("input=HelloWorld");   //Send the actual POST request
   if(httpResponseCode > 0){
    String response = http.getString();  //Get the response to the request
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
   }else{
    Serial.print("Error on HTTP request: ");
    Serial.println(httpResponseCode);
   }
   http.end();  //Free resources
  delay(3000);
}

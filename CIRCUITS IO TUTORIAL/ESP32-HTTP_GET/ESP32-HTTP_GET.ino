#include <WiFi.h>

// Replace with your network credentials
const char* ssid     = "WiFi name here";
const char* password = "password here";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

void setup() {
  Serial.begin(115200);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {


  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {

            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            if (header.indexOf("GET /msg1") >= 0) {
              client.println("This is a message from esp32");
              client.println();
            } else if (header.indexOf("GET /viewdata") >= 0) {
              //DO NOTHING....
              client.println(F("<!DOCTYPE HTML><html>"));
              client.println(F("<!-- Rui Santos - Complete project details at https://RandomNerdTutorials.com"));
              client.println(F(""));
              client.println(F("Permission is hereby granted, free of charge, to any person obtaining a copy"));
              client.println(F("of this software and associated documentation files."));
              client.println(F("The above copyright notice and this permission notice shall be included in all"));
              client.println(F("copies or substantial portions of the Software. -->"));
              client.println(F("<head>"));
              client.println(F("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"));
              client.println(F("<script src=\"https://code.highcharts.com/highcharts.js\"></script>"));
              client.println(F("<style>"));
              client.println(F("body {"));
              client.println(F("min-width: 310px;"));
              client.println(F("max-width: 800px;"));
              client.println(F("height: 400px;"));
              client.println(F("margin: 0 auto;"));
              client.println(F("}"));
              client.println(F("h2 {"));
              client.println(F("font-family: Arial;"));
              client.println(F("font-size: 2.5rem;"));
              client.println(F("text-align: center;"));
              client.println(F("}"));
              client.println(F("</style>"));
              client.println(F("</head>"));
              client.println(F("<body>"));
              client.println(F("<h2>ESP Weather Station</h2>"));
              client.println(F("<div id=\"chart-temperature\" class=\"container\"></div>"));
              client.println(F("<div id=\"chart-humidity\" class=\"container\"></div>"));
              client.println(F("</body>"));
              client.println(F("<script>"));
              client.println(F("var chartT = new Highcharts.Chart({"));
              client.println(F("chart:{ renderTo : 'chart-temperature' },"));
              client.println(F("title: { text: 'DHT11 Temperature' },"));
              client.println(F("series: [{"));
              client.println(F("showInLegend: false,"));
              client.println(F("data: []"));
              client.println(F("}],"));
              client.println(F("plotOptions: {"));
              client.println(F("line: { animation: false,"));
              client.println(F("dataLabels: { enabled: true }"));
              client.println(F("},"));
              client.println(F("series: { color: '#059e8a' }"));
              client.println(F("},"));
              client.println(F("xAxis: { type: 'datetime',"));
              client.println(F("dateTimeLabelFormats: { second: '%H:%M:%S' }"));
              client.println(F("},"));
              client.println(F("yAxis: {"));
              client.println(F("title: { text: 'Temperature (Celsius)' }"));
              client.println(F("//title: { text: 'Temperature (Fahrenheit)' }"));
              client.println(F("},"));
              client.println(F("credits: { enabled: false }"));
              client.println(F("});"));
              client.println(F("setInterval(function ( ) {"));
              client.println(F("var xhttp = new XMLHttpRequest();"));
              client.println(F("xhttp.onreadystatechange = function() {"));
              client.println(F("if (this.readyState == 4 && this.status == 200) {"));
              client.println(F("var x = (new Date()).getTime(),"));
              client.println(F("y = parseFloat(this.responseText);"));
              client.println(F("//console.log(this.responseText);"));
              client.println(F("if(chartT.series[0].data.length > 20) {"));
              client.println(F("chartT.series[0].addPoint([x, y], true, true, true);"));
              client.println(F("} else {"));
              client.println(F("chartT.series[0].addPoint([x, y], true, false, true);"));
              client.println(F("}"));
              client.println(F("}"));
              client.println(F("};"));
              client.println(F("xhttp.open(\"GET\", \"/temperature\", true);"));
              client.println(F("xhttp.send();"));
              client.println(F("}, 5000 ) ;"));
              client.println(F(""));
              client.println(F("var chartH = new Highcharts.Chart({"));
              client.println(F("chart:{ renderTo:'chart-humidity' },"));
              client.println(F("title: { text: 'DHT11 Humidity' },"));
              client.println(F("series: [{"));
              client.println(F("showInLegend: false,"));
              client.println(F("data: []"));
              client.println(F("}],"));
              client.println(F("plotOptions: {"));
              client.println(F("line: { animation: false,"));
              client.println(F("dataLabels: { enabled: true }"));
              client.println(F("}"));
              client.println(F("},"));
              client.println(F("xAxis: {"));
              client.println(F("type: 'datetime',"));
              client.println(F("dateTimeLabelFormats: { second: '%H:%M:%S' }"));
              client.println(F("},"));
              client.println(F("yAxis: {"));
              client.println(F("title: { text: 'Humidity (%)' }"));
              client.println(F("},"));
              client.println(F("credits: { enabled: false }"));
              client.println(F("});"));
              client.println(F("setInterval(function ( ) {"));
              client.println(F("var xhttp = new XMLHttpRequest();"));
              client.println(F("xhttp.onreadystatechange = function() {"));
              client.println(F("if (this.readyState == 4 && this.status == 200) {"));
              client.println(F("var x = (new Date()).getTime(),"));
              client.println(F("y = parseFloat(this.responseText);"));
              client.println(F("//console.log(this.responseText);"));
              client.println(F("if(chartH.series[0].data.length > 20) {"));
              client.println(F("chartH.series[0].addPoint([x, y], true, true, true);"));
              client.println(F("} else {"));
              client.println(F("chartH.series[0].addPoint([x, y], true, false, true);"));
              client.println(F("}"));
              client.println(F("}"));
              client.println(F("};"));
              client.println(F("xhttp.open(\"GET\", \"/humidity\", true);"));
              client.println(F("xhttp.send();"));
              client.println(F("}, 5000 ) ;"));
              client.println(F("</script>"));
              client.println(F("</html>"));


            }else{
              //DO nothing....
            }

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

const int LED = 2; //led pin to D2
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}
void loop() {
  // reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(A0);

  Serial.print("Analog reading = ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 10) {
    Serial.println(" - Light");
    digitalWrite(LED, HIGH); // turn ON LED
  } else if (analogValue < 50) {
    Serial.println(" - Dim");
  } else if (analogValue < 100) {
    Serial.println(" - Dark");
    digitalWrite(LED, LOW); // turn OFF LED
  } else {
    Serial.println(" - Dark");
  }
  delay(3000);
}

const int buzzer =  26;      // the number of the buzzer GPIO pin
int buzzerState = LOW;             // set initial state for buzzer

// Generally, use "unsigned long" for variables that hold time
unsigned long previousMillis = 0;        // will store last time updated
const long interval = 1000;           // interval at which to beep (milliseconds)

void setup() {
  pinMode(buzzer, OUTPUT);  // set the digital pin as output:
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // if the Buzzer is off turn it on and vice-versa:
    if (buzzerState == LOW) {
      buzzerState = HIGH;
    } else {
      buzzerState = LOW;
    }
    // set the Buzzer with the buzzerState of the variable:
    digitalWrite(buzzer, buzzerState);
  }
}

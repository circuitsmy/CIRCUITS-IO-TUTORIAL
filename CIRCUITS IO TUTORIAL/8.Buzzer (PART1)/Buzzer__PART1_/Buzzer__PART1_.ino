const int buzzer = 6; // buzzer to arduino pin 6

void setup() {
  pinMode(buzzer, OUTPUT); //Set buzzer - pin 6 as an output
}

void loop() {
  tone(buzzer, 1000); //send 1KHz sound signal
  delay(1000);        //...for 1 sec
  noTone(buzzer);     //stop sound
  delay(1000);        //...for 1 sec
}

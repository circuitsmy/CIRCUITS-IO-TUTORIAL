void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button = digitalRead(5);
  if (button == 1) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
}

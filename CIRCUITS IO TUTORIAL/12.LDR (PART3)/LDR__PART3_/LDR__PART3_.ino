const int Buzzer = 2;
const int LDR = A0;

void setup () {

Serial.begin(9600);
pinMode(Buzzer, OUTPUT);
pinMode(LDR, INPUT);

}

void loop() {
int ldrStatus = analogRead(A0);

if (ldrStatus >= 100) {
tone(Buzzer, 100);
delay(100);

noTone(Buzzer);
delay(100);

Serial.println("----------- ALARM ACTIVATED -----------");
}

else {
noTone(Buzzer);
Serial.println("ALARM DEACTIVATED");

delay (1000);
}
}

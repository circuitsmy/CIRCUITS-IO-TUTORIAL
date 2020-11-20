void setup() {
  // put your setup code here, to run once:
pinMode(23,OUTPUT);
pinMode(21,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button = digitalRead(21);
  if(button == 1){
    digitalWrite(23,HIGH);
  }else{
    digitalWrite(23,LOW);
  }
}

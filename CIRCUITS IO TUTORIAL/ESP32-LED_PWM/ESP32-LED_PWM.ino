//LED connected to GPIO 23
void setup() {
  ledcSetup(0,2000,8); //channel,freq,resolution
  ledcAttachPin(23,0); //GPIO,channel
}

void loop() {
  for(int pwm = 0; pwm < 255; pwm++){
  ledcWrite(0,pwm);
  delay(10);
  }
  for(int pwm = 255; pwm > 0; pwm--){
  ledcWrite(0,pwm);
  delay(10);
  }
}

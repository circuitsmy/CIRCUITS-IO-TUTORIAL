                                                                                                                                                                                                                                                                                                                                                                                                                   // the setup function runs once you press reset or power the board
void setup(){
  //initialize digital pin LED
  pinMode(3,OUTPUT);
}

//the loop function runs over and over
void loop(){
  digitalWrite(3, HIGH); //turn ON the LED
  delay(500);           //wait for 0.5 second
  digitalWrite(3,LOW); //turn OFF the LED
  delay(500);           //wait for 0.5 second
}

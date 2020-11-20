#include <Adafruit_Fingerprint.h>
#include <Servo.h>

SoftwareSerial mySerial(2, 3);
Servo servo;

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()
{  
  Serial.begin(9600);
  servo.attach(12);
  servo.write(0);
  finger.begin(57600);
  delay(1000);

}

void loop()
{
  getFingerprintIDez();
}

int getFingerprintIDez() {
  uint8_t p = finger.getImage(); 
  if (p != FINGERPRINT_OK){
  Serial.println(" --Scanning-- ");
  }

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK);

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  Serial.println("scan succesful");
  delay(500);
  Serial.print(" --Door Open--");
  servo.write(180);
  delay(5000);
  servo.write(0); 
  Serial.print(" --Door Close--");
  
  return finger.fingerID; 
}

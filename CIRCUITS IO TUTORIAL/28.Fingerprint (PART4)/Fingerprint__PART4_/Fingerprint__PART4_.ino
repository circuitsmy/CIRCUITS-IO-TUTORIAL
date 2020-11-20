#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
#include <LCD_I2C.h>
#include <Servo.h>

SoftwareSerial mySerial(2, 3);
Servo myservo;
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
LCD_I2C lcd(0x27);

int getFingerprintIDez();

void setup()
{  
  Serial.begin(9600);
  myservo.attach(12);
  myservo.write(0);
  
  lcd.begin();
  lcd.backlight();
  lcd.print("  CIRCUITS IO  ");
  lcd.setCursor(0,1);
  
  delay(1000);

  lcd.clear();
  lcd.print("Enter Fingerprint");
  lcd.setCursor(0,1);
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
    lcd.setCursor(0,0);
    lcd.print("   Scanning   ");
   return -1;
  }
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK);{
    lcd.setCursor(0,0);
    lcd.print("  Not Match  ");
   return -1;   
  }

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK){
    lcd.setCursor(0,0);
    lcd.print("  Not Match  ");
    lcd.setCursor(0,1);
    lcd.print("  Not Match  ");   
    return -1;
  }
    Serial.println("scan successful");
    lcd.setCursor(0,0);
    lcd.print(" Scan successful");
    lcd.setCursor(0,1);
    lcd.print("  -door open-  "); 
    doorLock();  
 
  return finger.fingerID; 
}

void doorLock(){
  myservo.write(180);
  delay(500);
  myservo.write(0);
  lcd.print("  -door close-  "); 
}

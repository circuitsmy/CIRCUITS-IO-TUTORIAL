#include <Keypad.h>
#include<EEPROM.h>
#include <LCD_I2C.h>
#include <Servo.h>

LCD_I2C lcd(0x27);
Servo myservo;

const int servo = 12;
int pos = 0;
int lockStatus = 0;
char password[4];
char initial_password[4] ={1,2,3,4} , new_password[4];
int i = 0;
char key_pressed = 0;
int getKeypad();

const byte rows = 4;
const byte columns = 3;
char hexaKeys[rows][columns] = {

  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}

};

byte row_pins[rows] = {11, 10, 9, 8};
byte column_pins[columns] = {5, 4, 3};

Keypad keypad_key = Keypad( makeKeymap(hexaKeys), row_pins, column_pins, rows, columns);


void setup()

{
  myservo.attach(servo);
  myservo.write(0);
  lcd.begin();
  lcd.backlight();
  lcd.print("CIRCUITS IO");
  lcd.setCursor(0, 1);
  
  for (int j = 0; j < 4; j++) {
    EEPROM.write(j, j + 49);
  }
  for (int j = 0; j < 4; j++) {
    initial_password[j] = EEPROM.read(j);
  }
}

void loop()
{
  keypad_mode();
}

void keypad_mode() {
  lcd.clear();
  lcd.println("Enter Password");
  lcd.setCursor(0, 1);
  
    key_pressed = keypad_key.getKey();
    if (key_pressed == '#')
      change(); 
    if (key_pressed)
    { 
      password[i++] = key_pressed;
      lcd.print(key_pressed);
    }
    if (i == 4)
    {
      delay(200);
      for (int j = 0; j < 4; j++) {
        initial_password[j] = EEPROM.read(j);
      }
      if (!(strncmp(password, initial_password, 4)))
      {

        door_trigger_5s(); 
        
        lcd.clear();
        lcd.print("Pass Accepted");
        delay(2000);

        lcd.setCursor(0, 1);
        lcd.print("Pres # to change");
        delay(2000);

        lcd.clear();
        lcd.print("Enter Password:");
        lcd.setCursor(0, 1);
        i = 0;
      }
      else
      {
        lcd.clear();
        lcd.print("Wrong Password");
        lcd.setCursor(0, 1);
        lcd.print("Pres # to Change");
        delay(2000);

        lcd.clear();
        lcd.print("Enter Password");
        lcd.setCursor(0, 1);
        i = 0;
      }
    
  }
}

void change()
{
  int j=0;
  lcd.clear();
  lcd.print("Current Password");
  lcd.setCursor(0,1);
  while(j<4)
  {
    char key=keypad_key.getKey();
    if(key)
    {
      new_password[j++]=key;
      lcd.print(key);
    }
    key=0;
  }
  delay(500);
  if((strncmp(new_password, initial_password, 4)))

  {
    lcd.clear();
    lcd.print("Wrong Password");
    lcd.setCursor(0,1);
    lcd.print("Try Again");
    delay(1000);
  }
  else
  {
    j=0;
    lcd.clear();
    lcd.print("New Password:");
    lcd.setCursor(0,1);  
    while(j<4)
    {
      char key=keypad_key.getKey();
      if(key)
      {
        initial_password[j]=key;
        lcd.print(key);
        EEPROM.write(j,key);
        j++;
      }
    }
    lcd.print("Pass Changed");
    delay(1000);
  }
  lcd.clear();
  lcd.print("Enter Password");
  lcd.setCursor(0,1);
  key_pressed=0;
}

void door_trigger_5s(){
        myservo.write(180);
        delay(500);
        myservo.write(0);                   
}

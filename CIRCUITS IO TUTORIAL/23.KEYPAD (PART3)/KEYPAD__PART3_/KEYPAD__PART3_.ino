#include <Keypad.h> //Keypad Library
#include<EEPROM.h> //Arduino library contain password
#include <LCD_I2C.h> //LCD_I2C library

LCD_I2C lcd(0x27);

char password[4]; //password contain 4 character
char initial_password[4],new_password[4];
int i=0;
char key_pressed=0; //initialize key_pressed
const byte rows = 4; 
const byte columns = 3; 
char hexaKeys[rows][columns] = {

  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}

};

byte row_pins[rows] = {11, 10, 9, 8};
byte column_pins[columns] = {5, 4, 3};  

//initialize key
Keypad keypad_key = Keypad( makeKeymap(hexaKeys), row_pins, column_pins, rows, columns);

void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(16,0);
  lcd.print("CIRCUITS IO");

  delay(2000);
  
  lcd.clear();
  lcd.print("Enter Password");
  lcd.setCursor(0,1);
}

void loop()
{
  key_pressed = keypad_key.getKey(); //get pressed key
  if(key_pressed=='#')
    change();
  if (key_pressed)
  {
    password[i++]=key_pressed;
    lcd.print(key_pressed);
      }

  if(i==4)

  {
    delay(200);
    for(int j=0;j<4;j++){
        initial_password[j]=EEPROM.read(j);
    }
    if(!(strncmp(password, initial_password,4)))
    {
      lcd.clear();
      lcd.print("Pass Accepted"); 
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("Pres # to change");
      delay(2000);

      lcd.clear();
      lcd.print("Enter Password:");
      lcd.setCursor(0,1);
      i=0;
    }
    
    else{    
      lcd.clear();
      lcd.print("Wrong Password");
      lcd.setCursor(0,1);
      lcd.print("Pres # to Change");
      delay(2000);
      lcd.clear();
      lcd.print("Enter Password");
      lcd.setCursor(0,1);
      i=0;     
    }   
  }
}

// change password
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

//fixed initial pasword to "1234"
void initialpassword(){
  
  for(int j=0;j<4;j++){
  EEPROM.write(j, j+49);
  }
  for(int j=0;j<4;j++){
  initial_password[j]=EEPROM.read(j);
 }
} 




      

        

      


  

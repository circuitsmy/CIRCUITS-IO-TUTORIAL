#include<LiquidCrystal.h>
#include <LCD_I2C.h>
#include "DHT.h"

//Constants
#define DHTPIN 2     // DHT 22  (AM2302) - pin used for DHT22 
#define DHTTYPE DHT11
LCD_I2C lcd(0x27);
DHT dht(DHTPIN, DHTTYPE);

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}

void loop()
{
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float hum = dht.readHumidity();
    // Read temperature as Celsius
    float temp = dht.readTemperature();
    //Print temp and humidity values to LCD
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");
    lcd.print(hum);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temp: "); 
    lcd.print(temp);
    lcd.println("Celcius");
    delay(2000); //Delay 2 sec between temperature/humidity check.
}

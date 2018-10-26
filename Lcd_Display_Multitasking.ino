#define led1 0
#define led2 8
#define button 7
unsigned long zeit;
unsigned long zeit1;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(button, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  zeit = millis();
}

void loop() {

  lcd.clear();
  lcd.print("LED1 State: ");
  
  if ((millis() - zeit) >= 1000){
    digitalWrite(led1, !digitalRead(led1));  
    zeit = millis();
    }
    
  lcd.setCursor(13, 0);
  if (!digitalRead(led1)){lcd.print("OFF");}
  else {lcd.print("ON");}

  lcd.setCursor(0,1);
  lcd.print("Button: ");
  
  if (!digitalRead(button)){
    zeit1 = millis();
    }

  lcd.setCursor(9, 1);
  if (digitalRead(button)){lcd.print("OFF");}
  else {lcd.print("ON");}
    

  if ((millis() - zeit1) <=2000){
    digitalWrite(led2, !digitalRead(button));
    zeit1 = millis();
    }

  delay(250);

  
}

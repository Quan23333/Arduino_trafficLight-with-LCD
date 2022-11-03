//Init
int Led_R = 7;
int Led_Y = 6;
int Led_G = 5;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  // put your setup code here, to run once:
  //Define
  pinMode (Led_R, OUTPUT);
  pinMode (Led_Y, OUTPUT);
  pinMode (Led_G, OUTPUT);

  // initialize the lcd
  lcd.init();
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  //lightUp(1=Red, 2=Yellow, 3=Green)
  //countDown("light colour", sec)  
  //Red Light Count Down 10Sec
  lightUp(1);
  countDown("Red", 15);

  //Yellow Light Count Down 5Sec
  lightUp(2);
  countDown("Yellow", 5);

  //Green Light Count Down 15Sec
  lightUp(3);
  countDown("Green", 10);
}

void lightUp(int col) {
  switch (col) {
    case 1:
      //do something when var equals 1
      digitalWrite(Led_R, HIGH);
      digitalWrite(Led_Y, LOW);
      digitalWrite(Led_G, LOW);
      break;
    case 2:
      //do something when var equals 2
      digitalWrite(Led_R, LOW);
      digitalWrite(Led_Y, HIGH);
      digitalWrite(Led_G, LOW);
      break;
    case 3:
      //do something when var equals 3
      digitalWrite(Led_R, LOW);
      digitalWrite(Led_Y, LOW);
      digitalWrite(Led_G, HIGH);
      break;
    default:
      // if nothing else matches, do the default
      // default is optional
      digitalWrite(Led_R, LOW);
      digitalWrite(Led_Y, LOW);
      digitalWrite(Led_G, LOW);
      break;
  }
}
void countDown(String col, int sec) {
  for (int i = sec; i > 0; i--) {
    lcd.setCursor(0, 0);
    lcd.print(col + " light");
    lcd.setCursor(14, 1);
    lcd.print(i);
    lcd.setCursor(0, 1);
    lcd.print("Time left >>>");
    delay(1000);
    lcd.clear();
  }
}

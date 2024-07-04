// Libraries included
#include <LiquidCrystal.h>

// Declare constants
const int LM35 = A0;
const int fan = 13;
const int heater = 9;
const int LedRed = 12;
const int LedGreen = 11;
const int LedBlue = 10;

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(fan, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(LedRed, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  pinMode(LedBlue, OUTPUT);
  delay(1000);
  lcd.clear();
  lcd.print("Temp= ");
  lcd.setCursor(0, 1);
  lcd.print("Fan= ");
  lcd.setCursor(8, 1);
  lcd.print("&");
  lcd.setCursor(9, 1);
  lcd.print("Hot= ");
}

void loop() {
  // Section for the temperature sensor
  int value = analogRead(LM35);
  float Temperature = value;
  lcd.setCursor(6, 0);
  lcd.print(Temperature);

  // Seccion of the fan and heater
  if (Temperature > 30) {
    digitalWrite(fan, HIGH);
    digitalWrite(heater, LOW);
    digitalWrite(LedRed, HIGH);
    digitalWrite(LedGreen, LOW);
    digitalWrite(LedBlue, LOW);
    lcd.setCursor(5, 1);
    lcd.print("ON ");
    lcd.setCursor(13, 1);
    lcd.print("OFF ");

  } else if (Temperature < 25) {
    digitalWrite(fan, LOW);
    digitalWrite(heater, HIGH);
    digitalWrite(LedRed, LOW);
    digitalWrite(LedGreen, LOW);
    digitalWrite(LedBlue, HIGH);
    lcd.setCursor(5, 1);
    lcd.print("OFF");
    lcd.setCursor(13, 1);
    lcd.print("ON ");
  } else {
    digitalWrite(fan, LOW);
    digitalWrite(heater, LOW);
    digitalWrite(LedRed, LOW);
    digitalWrite(LedGreen, HIGH);
    digitalWrite(LedBlue, LOW);
    lcd.setCursor(5, 1);
    lcd.print("OFF");
    lcd.setCursor(13, 1);
    lcd.print("OFF ");
  }

  delay(1000);
}
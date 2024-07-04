#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int count = 0;
void setup() {
  lcd.begin(16, 2);

}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("count: ");
  lcd.print(count);

  count++;

  if (count > 10) {
    count = 0;
  }
  delay(500);

}


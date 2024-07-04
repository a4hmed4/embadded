#define red 7
#define yellow 8
#define green 9

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

}

void loop() {
  digitalWrite(red, 1);
  delay(3000);
  digitalWrite(red, 0);

  for(int i = 1; i<=5; i++)
  {
  digitalWrite(yellow, 1);
  delay(500);
  /* digitalWrite(yellow, 0);
  delay(500); */
  }

  digitalWrite(green, 1);
  delay(3000);
  digitalWrite(green, 0);

}

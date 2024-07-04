#define pot A0
void setup() {
  // put your setup code here, to run once:
  pinMode(pot,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int data = analogRead(pot);
  Serial.println(data);
  delay(100);
}

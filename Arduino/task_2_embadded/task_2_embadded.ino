#define led 7
#define button 8

void setup() {
    pinMode(led,OUTPUT);
    pinMode(button,INPUT);

}

void loop() {
  int data = digitalRead(button);
  if(data == 1)
  {
    digitalWrite(led,1);
  }
  else
  {
    digitalWrite(led,0);
  }

}

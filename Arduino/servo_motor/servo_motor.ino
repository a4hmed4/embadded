
#include <Servo.h>

Servo myservo;  


void setup() {
  myservo.attach(9);  
}

void loop() {
  
  myservo.write(500);
  delay(2000);
  myservo.write(65);
  delay(1000);
  myservo.write(50);
  delay(1000);
  myservo.write(100);

}

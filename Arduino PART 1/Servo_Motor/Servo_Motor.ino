#include <Servo.h>
Servo servo;

int servo = 0;

void setup() {
  servo.attach(3);
  servo.write(0);
  delay(2000);
}
void loop() {
  servo.write(0);  
  delay(0);
  servo.write(90);              
  delay(0);  
  servo.write(180);  
  delay(0);
  servo.write(90);              
  delay(0);
                  
}

#include <Servo.h>

Servo s1, s2;

void setup() {
  s1.attach(8);
  s2.attach(9);

    // move to 0°
  s2.write(0);
  s1.write(0);    // move to 0°
  s2.write(15);
  s1.write(0);    // move to 0°
  s2.write(35);
  s1.write(0);    // move to 0°
  s2.write(-60);
  
  
  
}

void loop() {
  

  
  
  
}

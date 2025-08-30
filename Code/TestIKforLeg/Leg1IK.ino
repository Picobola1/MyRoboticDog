#include <Servo.h>
#include <FABRIK2D.h>

Servo HipServo;
Servo KneeServo; 

int lengths[] = {110, 110}; // 2DOF arm where shoulder to elbow is 110mm and elbow to end effector is 110mm.
Fabrik2D fabrik2D(3, lengths); // This arm has 3 joints; one in the origin, the elbow and the end effector.

float y = 0;
int toggle_y = 0;



void setup() {
  // put your setup code here, to run once:
  HipServo.attach(8);
  KneeServo.attach(9);
  fabrik2D.setTolerance(0.5);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // Move from -30 to 40 in the y axis
  if (y < 10) {
    toggle_y = 0;
    y = 10;
  } else if (y > 150) {
    toggle_y = 1;
    y = 150;
  }

  // Solve inverse kinematics given the coordinates x and y and the list of lengths for the arm.
  fabrik2D.solve(180,y,lengths);

  int HipAngle = fabrik2D.getAngle(0) * 180.0 / PI;
  int KneeAnge = fabrik2D.getAngle(1) * 180.0 / PI;
  HipServo.write(HipAngle);
  KneeServo.write(KneeAnge);

  if (toggle_y == 0) {
    y++;
  } else {
    y--;
  }

  delay(30);

}



#include <Castilla.h>
#include <Servo.h>

// Two standard servos are connected to each of 
// the tinkerkit digital connections, that is 9 and 10
StandardServo front=StandardServo(9); 
StandardServo back=StandardServo(10);

void setup(){
  front.begin(); //servos are initialized
  back.begin();
}

void loop(){
  //Make the robot crawl by setting the servos to opposite angles.
  //90 is the middle angle
  front.setAngle(120);
  delay(200);
  back.setAngle(60);
  delay(200);
  front.setAngle(60);
  delay(200);
  back.setAngle(120);
  delay(200);
}

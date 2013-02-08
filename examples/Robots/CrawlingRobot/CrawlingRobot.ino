#include <Castilla.h>
#include <Servo.h>

Servo front, back;

void setup(){
  //servos are initialized
  front.attach(9); 
  back.attach(10);
}

void loop(){
  //Make the robot crawl by setting the servos to opposite angles.
  //90 is the middle angle
  front.write(120);
  delay(200);
  back.write(60);
  delay(200);
  front.write(60);
  delay(200);
  back.write(120);
  delay(200);
}

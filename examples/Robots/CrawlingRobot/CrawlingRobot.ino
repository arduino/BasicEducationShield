/*
* This small robot can crawl. 
* It’s all it can do, and it isn’t very good at it. 
* But it is super cute and great fun.
*/

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
  back.detach();
  front.attach(9);
  front.write(110);   //Rotation front legs
  delay(200);
  
  front.detach();
  back.attach(10);
  back.write(70);
  delay(200);
  
  back.detach();
  front.attach(9);
  front.write(70);
  delay(200);
  
  front.detach();
  back.attach(10);
  back.write(110);
  delay(200);
}

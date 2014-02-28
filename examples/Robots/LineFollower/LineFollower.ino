/*
  LineFollower  
  The Line Follower does exactly what the name suggests, 
  it follows a line. Make it go where ever you want by 
  showing the way with a 3 cm wide, black line. 
  
  (c) 2014 Arduino Verkstad
*/


#include <BasicEducationShield.h>
//Servo.h is necessary to be included here
#include <Servo.h>

//IRArray(IR1, IR2, IR3)
IRArray ir = IRArray(A1, A2, A3);
//(Wheels(left, right)
Wheels wheels=Wheels(10, 9);

void setup(){
  wheels.begin();
  delay(1000);
}

void loop(){
  int dir = ir.readLine();
  wheels.follow(dir);
}

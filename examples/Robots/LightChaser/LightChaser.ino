/*
  Light Chaser
  
  This little vehicle is on an impossible, never ending 
  mission to catch the light. You can make it follw you 
  by pointing a flashligt at it. (The one on your mobile 
  phone eg.) It will always turn towards the light. 
  
  (c) 2013 Arduino LLC
*/

#include <BasicEducationShield.h>

//Servo.h is necessary to be included here
#include <Servo.h>

//Declare the two wheels of robot, left wheel to D10 and
// right wheel to D9
Wheels wheels=Wheels(10, 9);

//Declare the two LDR sensors
LDR sensorLeft=LDR(A0);
LDR sensorRight=LDR(A2);

void setup(){
  //initialize the LDR sensors
  sensorLeft.config(600,800);
  sensorRight.config(600,800);

  //initialize the servo motors
  wheels.begin();
}
void loop(){
  if(sensorLeft.getState()){
	//Left ldr detects strong light, the vechile turns left
    wheels.turnLeft();
  }else if(sensorRight.getState()){
	//Right ldr detects strong light, the vechile turns right
    wheels.turnRight();
  }else{
	//No strong light detected, the vechile goes straight
    wheels.goForward();
  }
}

/*
* This little car is simple and smart. It goes on 
* and on straight, but if you point a flashlight on it, 
* the Vehicle will turn towards the light. 
* So just take a flashlight(or use the flashlight of 
* your mobile phone), stir it around and have fun!
*/

#include <Castilla.h>

//Servo.h is necessary to be included here
#include <Servo.h>

//Declare the two wheels of robot
ContinuousServo left=ContinuousServo(10,false);
ContinuousServo right=ContinuousServo(9,true);

//Declare the two LDR sensors
LDR sensorLeft=LDR(A0);
LDR sensorRight=LDR(A2);

void setup(){
  //initialize the LDR sensors
  sensorLeft.config(200,500);
  sensorRight.config(200,500);

  //initialize the servo motors
  left.begin(); 
  right.begin();
}
void loop(){
  if(sensorLeft.getState()){
	//Left ldr detects strong light, the vechile turns left
    left.goBackwards(); 
    right.goForward(); 
  }else if(sensorRight.getState()){
	//Right ldr detects strong light, the vechile turns right
    left.goForward(); 
    right.goBackwards(); 
  }else{
	//No strong light detected, the vechile go straight
    left.goForward(); 
    right.goForward(); 
  }
  delay(30);
}

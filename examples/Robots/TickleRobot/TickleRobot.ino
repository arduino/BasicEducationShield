/*
    Tickle Robot
    
    This is just a regular ticklish robot in a rocking chair. 
    Come to think of it, that doesn't sound very regular at all. 
    Tickle the robot on its heart and it will start wiggle like crazy. 
    
    (c) 2013 Arduino LLC
*/

#include <BasicEducationShield.h>

//Necessary to include Servo.h when using Servo
#include <Servo.h>

//Necessary to include CapacitiveSensor.h when using capacitive sensor
#include <CapacitiveSensor.h>

//Declare the servo for controlling the string robot
Servo pull;

//Declare the capacitive sensor
CapacitiveSwitch sensor=CapacitiveSwitch(2,3);

void setup(){
  //initialize the capacitive sensor. Threshold is 400
  //See the example CapacitiveSwitchTest in the Help folder
  //to find the right thresshold
  sensor.config(400);

  //initialize the servo motor
  pull.attach(9);
}
void loop(){
  if(sensor.getState()){
	//If the capacitive sensor is touched, pull the strings
    pull.write(0);
  }else{
	//Otherwise, loosen the strings
    pull.write(90);
  }
  delay(30);

}

#include <Castilla.h>

//Necessary to include Servo.h when using Servo
#include <Servo.h>

//Necessary to include CapacitiveSensor.h when using capacitive sensor
#include <CapacitiveSensor.h>

//Declare the servo for controlling the string doll
LimitedServo me=LimitedServo(9);

//Declare the capacitive sensor
CapacitiveSwitch sensor=CapacitiveSwitch(13,12);

void setup(){
  //initialize the capacitive sensor. Threshold is 400
  sensor.config(400);
  
  //initialize the servo motor
  me.begin();
}
void loop(){
  if(sensor.getState()){
	//If the capacitive sensor is touched, lift the doll
    me.setAngle(30);
  }else{
	//Otherwise, lower the doll
    me.setAngle(0);
  }
  delay(30);

}

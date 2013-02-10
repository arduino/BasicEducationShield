#include <Castilla.h>

//Necessary to include Servo.h when using Servo
#include <Servo.h>

//Necessary to include CapacitiveSensor.h when using capacitive sensor
#include <CapacitiveSensor.h>

//Declare the servo for controlling the string doll
Servo pull;

//Declare the capacitive sensor
CapacitiveSwitch sensor=CapacitiveSwitch(2,3);

void setup(){
  //initialize the capacitive sensor. Threshold is 400
  sensor.config(400);
  
  //initialize the servo motor
  pull.attach(9);
}
void loop(){
  if(sensor.getState()){
	//If the capacitive sensor is touched, lift the doll
    pull.write(90);
  }else{
	//Otherwise, lower the doll
    pull.write(0);
  }
  delay(30);

}

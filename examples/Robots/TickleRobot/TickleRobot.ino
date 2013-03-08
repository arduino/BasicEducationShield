/* 
* Do you like string puppets? This is one of them, 
* and very special because it’s a ticklish puppet. 
* If you tickle it, it will start jumping around 
* like crazy(or at least it tries to).
*/

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
	//If the capacitive sensor is touched, pull the strings
    pull.write(0);
  }else{
	//Otherwise, loosen the strings
    pull.write(90);
  }
  delay(30);

}

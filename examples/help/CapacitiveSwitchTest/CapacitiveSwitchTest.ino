/*
	CapacitiveSwitch Test
*/

#include <CapacitiveSensor.h>
#include <BasicEducationShield.h>

//The sensor is connected between 2 and 3 by default
CapacitiveSwitch me=CapacitiveSwitch(2,3);

void setup(){
  Serial.begin(9600);
}
void loop(){
  //Print out the value of the sensor
  me.test();
  delay(30);
}

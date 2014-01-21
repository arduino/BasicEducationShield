/*	CapacitiveSwitch
*/

#include <CapacitiveSensor.h>
#include <BasicEducationShield.h>

//The sensor is connected between 2 and 3 by default
CapacitiveSwitch me=CapacitiveSwitch(2,3);

void setup(){
  Serial.begin(9600);
  me.config(400);
}
void loop(){
  Serial.println("Please press...");
  //Wait until the capacitive sensor is pressed.
  Serial.println(me.pressed());

  delay(1000);

  Serial.println("Please release...");
  //Wait untill the capacitive sensor is released.
  Serial.println(me.released());

  do{	//Print values bigger than 10. Print 0 otherwise.
	Serial.println(me.getValue(20));
  }while(true);
}

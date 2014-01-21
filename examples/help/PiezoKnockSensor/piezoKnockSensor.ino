/*
	Piezo Knock Sensor
*/

#include <BasicEducationShield.h>

PiezoKnockSensor sensor=PiezoKnockSensor(A0);

void setup(){
  Serial.begin(9600);
  sensor.config(40,80);

}
void loop(){
  Serial.println("Please knock...");
  //Wait until the button is knocked.
  Serial.println(sensor.knocked());
}

/*	Piezo Knock Sensor
*	
*	Piezo can play music, as well as used as knock sensor.
*	
*	Connect the red pin of piezo to an analog pin(A5 in 
*	this example), black pin to GND. Connect a 1m ohm 
*	resistor parallel with the piezo. 
*	
*/

#include <Castilla.h>

//Be careful: Piezo as speaker is connected to digital pin
//while piezo as knock sensor is connected to analog pin.
PiezoKnockSensor sensor=PiezoKnockSensor(A0);

void setup(){
  Serial.begin(9600);
  //define the threshold and debounce time of the knock 
  //sensor. Threshold defines how hard you need to knock,
  //debounce time prevents the sensor from returning several
  //hits from one knock, but also limits how rapid you can knock.
  sensor.config(40,80);
  
}
void loop(){
  Serial.println("Please knock...");
  
  //knocked(timeout)
  //	timeout: milliseconds within which the sensor should 
  //		be knocked. If knocked within time, the function
  //		returns 1, otherwise 0. If not used, it waits 
  //		untill being knocked. 
  //
  //Wait until the button is knocked.
  Serial.println(sensor.knocked());
}

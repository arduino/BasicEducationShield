/*
LDR

LDR is a sensor that reads the intensity of light. It gives 
analog reading. When connected with Arduino analog pins, 
its value ranges from 0 to 1023 depending on the amount of 
light shining on it. 

The BasicEducationShield library includes some features for 
using the LDR as a button, or get values directly. Se the 
example LDRtest fo more information about how to configure
it correctly. 

(c) 2013 Arduino LLC
*/


#include <BasicEducationShield.h>

//Tinkerkit LDR is connected to analog 1.
LDR sensor = LDR(A1);

void setup(){

  Serial.begin(9600);

  //LDR needs to be configured with baseValue
  //and threshold. See LDRTest sketch for
  //details.
  sensor.config(700,900);
}

void loop(){
  Serial.println("Please press...");

  //pressed(timeout)
  //	timeout: milliseconds within which the
  //		LDR should be cover-uncovered. If
  //		cover-uncovered within time, the
  //		function returns 1, otherwise 0. If
  //		not used, it waits untill being
  //		cover-uncovered.
  //
  //Wait until the LDR gets cover-uncovered.
  Serial.println(sensor.pressed());

  Serial.println("Please press...");

  //released(timeout)
  //	timeout: same as in pressed(timeout).
  //
  //Wait until the LDR gets uncover-covered.
  Serial.println(sensor.pressed());


  While(true){
  //getState()
  //	returns whether the sensor readings has
  //	passed the threshold. Returns true if the
  //	threshold has been passed, false if not.
  //	Unlike pressed or released, this function
  //	does not stop the whole program.
  //
  //Continuously output whether the sensor has
  //passed threshold.
	Serial.println(sensor.getState());
	delay(30);
  }

}

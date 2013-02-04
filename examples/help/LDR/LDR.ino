#include <Castilla.h>

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

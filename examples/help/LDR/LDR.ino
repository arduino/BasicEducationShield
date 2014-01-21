/*
  LDR
*/


#include <BasicEducationShield.h>

LDR sensor = LDR(A1);

void setup(){
  Serial.begin(9600);
  sensor.config(700,900);
}

void loop(){
  Serial.println("Please press...");
  //Wait until the LDR gets cover-uncovered.
  Serial.println(sensor.pressed());

  Serial.println("Please press...");
  //Wait until the LDR gets uncover-covered.
  Serial.println(sensor.pressed());


  While(true){
  //Continuously output whether the sensor has
  //passed threshold.
	Serial.println(sensor.getState());
	delay(30);
  }

}

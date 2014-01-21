/*
  TiltSwitch
*/

#include <BasicEducationShield.h>

TiltSwitch me=TiltSwitch(10);

void setup(){
  Serial.begin(9600);

  //Initialize the component. Must be called.
  me.begin();
}
void loop(){
  Serial.println("Please tilt...");

  //Wait until the tilt switch is tilted.
  Serial.println(me.pressed());
}

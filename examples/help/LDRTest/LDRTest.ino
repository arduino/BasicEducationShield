/*
	LDR test
*/
#include <BasicEducationShield.h>

//Tinkerkit LDR is connected to analog 1.
LDR sensor = LDR(A1);

void setup(){
  Serial.begin(9600);
}

void loop(){
  //test() prints data to Serial port.
  sensor.test();
  delay(100);
}

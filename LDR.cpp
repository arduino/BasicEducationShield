#include "Castilla.h"

LDR::LDR(int pin):Button(pin,HIGH){
}

void LDR::config(int baseValue, int threashold){
	//Base value should be the one when nothing is covering
	//Threashold should be between base and covering value
	
	this->base=baseValue;
	this->threashold=threashold;
}

void LDR::test(){
	//Use the test to determin base and threashold first
	Serial.println(analogRead(pin));
}

bool LDR::getState(){
	int value=analogRead(pin);
	return abs(value-base)>abs(threashold-base);
}
#include "Castilla.h"

LDR::LDR(int pin):Button(pin,HIGH){
}

void LDR::config(int baseValue, int threashold){
	this->base=baseValue;
	this->threashold=threashold;
}

void LDR::test(){
	//Serial.println(pin);
	Serial.println(analogRead(pin));
}

bool LDR::getState(){
	int value=analogRead(pin);
	return abs(value-base)>abs(threashold-base);
}
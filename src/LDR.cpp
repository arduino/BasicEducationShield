#include "IntelCTC.h"
#include <Arduino.h>

LDR::LDR(int pin):Button(pin,HIGH){
}

void LDR::calibrate(int t){
	long startT=millis();
	int low=1023;
	int high=0;

	while(millis()-startT<t){
		int val=analogRead(pin);
		if(val<low){
			low=val;
		}else if(val>high){
			high=val;
		}
		delay(2);
	}

	this->base=high;
	this->threashold=(high-low)/2;

}

void LDR::config(int baseValue, int threashold){
	//Base value should be the one when nothing is covering
	//Threashold should be between base and covering value

	this->base=baseValue;
	this->threashold=threashold;
}

void LDR::showConfig(){
	Serial.print("base "+this->base);
	Serial.print(this->base);
	Serial.print(' ');
	Serial.print("threashold ");
	Serial.println(this->threashold);
}

void LDR::test(){
	//Use the test to determin base and threashold first
	Serial.println(analogRead(pin));
}

bool LDR::getState(){
	int value=analogRead(pin);
	return abs(value-base)>abs(threashold-base);
}

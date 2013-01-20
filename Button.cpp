#include "Castilla.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

Button::Button(int pin,bool pressedValue){
	this->pin=pin;
	this->pressedValue=pressedValue;
}
void Button::initialize(){
	pinMode(pin,INPUT);
}
bool Button::pressed(int timeout){
	//from unpressed to pressed
	return checkPress(timeout,pressedValue);
}
bool Button::released(int timeout){
	//from pressed to unpressed
	return checkPress(timeout,!pressedValue);
}
bool Button::doublePressed(int timeout,int tolerance){
	//two clicks within tolerance time
	if(pressed(timeout)){
		return pressed(tolerance);
	}else{
		return false;
	}
}
bool Button::checkPress(int timeout,bool requiredState){
	//help function, check if the button has changed 
	//from not "requiredState" to "requiredState" within timeout
	int timer=millis();
	bool iStart=false;
	do{
		if(!iStart){
			if(digitalRead(pin)!=requiredState){
				iStart=true;
			}
		}else{
			if(digitalRead(pin)==requiredState){
				return true;
			}
		}
		delay(10);
	}while(millis()-timer<=timeout || !timeout );
	
	return false;
}
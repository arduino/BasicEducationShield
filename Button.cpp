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
void Button::begin(){
	//Must be called in setup
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
	long timer=millis();
	bool iStart=false;
	do{
		if(!iStart){
			if(getState()!=requiredState){
				iStart=true;
			}
		}else{
			if(getState()==requiredState){
				return true;
			}
		}
		//delay(10);
	}while(millis()-timer<=timeout || !timeout );
	
	return false;
}

bool Button::getState(){
	return digitalRead(pin);
}

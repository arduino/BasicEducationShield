#include "Castilla.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

ButtonGroup::ButtonGroup(){
	for(int i=0;i<BUTTONGROUP_LENGTH;i++){
		this->buttons[i]=-1;
	}
}

void ButtonGroup::begin(int length, int buttons[],bool pressedValue){
	for(int i=0;i<length;i++){
		this->buttons[i]=buttons[i];
		//this->iStarted[i]=false;
	}
	this->buttonsCount=length;
	this->pressedValue=pressedValue;
}

int ButtonGroup::pressed(int timeout){
	return this->checkPress(timeout, this->pressedValue);
}

int ButtonGroup::checkPress(int timeout, bool requiredValue){
	bool iStarted[this->buttonsCount];
	for(int i=0;i<this->buttonsCount;i++){
		iStarted[i]=false;
	}
	
	long timer=millis();
	while(!timeout || millis()-timer<=timeout){
		for(int i=0;i<this->buttonsCount;i++){
			bool stat=digitalRead(this->buttons[i]);
			if(stat==!requiredValue && !iStarted[i]){
				iStarted[i]=true;
			}else{
				if(iStarted[i] && stat==requiredValue){
					return i;
					
				}
			}
		}
	}
	return -1;
}
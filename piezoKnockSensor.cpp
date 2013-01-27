#include "Castilla.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

PiezoKnockSensor::PiezoKnockSensor(int pin){
	this->pin=pin;
}

void PiezoKnockSensor::config(int threshold, int debounceTime){
	this->threshold=threshold;
	this->debounceTime=debounceTime;
}

bool PiezoKnockSensor::knocked(int timeout){
	long begin=millis();
	do{
		if(analogRead(pin)>threshold){
			delay(debounceTime);
			return true;
		}
	}while(millis()-begin>timeout || !timeout);
	return false;
}

void PiezoKnockSensor::test(){
	int val=analogRead(A5);
	Serial.println(val);
	delay(debounceTime);
}
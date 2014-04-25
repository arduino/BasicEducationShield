#include "BasicEducationShield.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

UltrasonicSensor::UltrasonicSensor(int trig, int echo){
	this->trig=trig;
	this->echo=echo;
}

int UltrasonicSensor::getDistance(){
	pinMode(trig, OUTPUT);
	digitalWrite(trig,LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(5);
	digitalWrite(trig, LOW);
	
	pinMode(echo, INPUT);
	int duration = pulseIn(echo, HIGH,11800);
	int distance = duration/29/2;
	
	return distance;
}

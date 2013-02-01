#include "Castilla.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

ContinuousServo::ContinuousServo(int pin, bool direction){
	this->direction=direction;
	this->pin=pin;
}

void ContinuousServo::begin(int stillSpeed){
	//Must be called in setup
	this->stillSpeed=stillSpeed;
    servo.attach(pin);
}

void ContinuousServo::goForward(int speed){
    //this->speed=speed;
	go(speed,true);
}

void ContinuousServo::goBackwards(int speed){
    //this->speed=speed;
	go(speed,false);
}

void ContinuousServo::go(int speed, bool toDirection){
	int toSpeed;
	if((direction && toDirection) || !(direction || toDirection)){
		toSpeed=stillSpeed+speed;
		if(toSpeed>180)
			toSpeed=180;
	}
	else{
		toSpeed=stillSpeed-speed;
		if(toSpeed<0)
			toSpeed=0;
	}
    servo.write(toSpeed);
}


void ContinuousServo::standStill(){
    //this->stillSpeed=stillSpeed;
    servo.write(stillSpeed);
}

void ContinuousServo::setSpeed(int speed){
    this->speed=speed;
    servo.write(speed);
}


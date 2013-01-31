#include "Castilla.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

ContinuousServo::ContinuousServo(int pin){
	this->pin=pin;
}

void ContinuousServo::begin(){
	//Must be called in setup
    servo.attach(pin);
}

void ContinuousServo::goForward(int speed){
    this->speed=speed;
    servo.write(speed);
}

void ContinuousServo::goBackwards(int speed){
    this->speed=speed;
    servo.write(speed);
}

void ContinuousServo::standStill(int speed){
    this->speed=speed;
    servo.write(speed);
}

void ContinuousServo::setSpeed(int speed){
    this->speed=speed;
    servo.write(speed);
}


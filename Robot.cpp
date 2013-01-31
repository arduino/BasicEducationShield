#include "Castilla.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

Robot::Robot(int pin){
	this->pin=pin;
}

void Robot::begin(){
	//Must be called in setup
    servo.attach(pin);
}

void Robot::goForward(){
    servo.write(180);
}

void Robot::goBackwards(){
    servo.write(0);
}

void Robot::standStill(){
    servo.write(96);
}

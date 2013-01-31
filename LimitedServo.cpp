#include "Castilla.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

LimitedServo::LimitedServo(int pin){
    this->pin=pin;
}

void LimitedServo::begin(){
	//Must be called in setup
    servo.attach(pin);
}

void LimitedServo::setAngle(int angle){
    //this->speed=speed;
    servo.write(angle);
}


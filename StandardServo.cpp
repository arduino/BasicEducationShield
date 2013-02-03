#include "Castilla.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

StandardServo::StandardServo(int pin){
    this->pin=pin;
}

void StandardServo::begin(){
	//Must be called in setup
    servo.attach(pin);
}

void StandardServo::setAngle(int angle){
    //this->speed=speed;
    servo.write(angle);
}



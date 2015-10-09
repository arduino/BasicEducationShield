#include "IntelCTC.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

LED::LED(int pin){
	this->pin=pin;
}
void LED::begin(){
	pinMode(pin,OUTPUT);
}

void LED::on(){
	digitalWrite(pin,HIGH);
}
void LED::off(){
	digitalWrite(pin,LOW);
}
void LED::blink(int speed,int times){
	//If times is set to 0, the LED will blink forever
	for(int i=0;i<times || !times;i++){
		on();
		delay(speed);
		off();
		delay(speed);
	}
}

#include "IntelCTC.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

Wheels::Wheels(int lpin, int rpin){
	this->lpin=lpin;
	this->rpin=rpin;
}

void Wheels::begin(){
	//Must be called in setup
    top = 120;
	low = 60;
    still = 90;

    fromL = still;
    fromR = still;
    toL = still;
    toR = still;

    left.attach(lpin);
    delay(1000);
    right.attach(rpin);
}

void Wheels::go(int tl, int tr){
    this->tl=tl;
    this->tr=tr;

     int lSpeed = fromL;
     int rSpeed = fromR;

     for(int i=0; i<(top-low); i++){
       if(lSpeed<tl) lSpeed++;
       else if(lSpeed>tl) lSpeed--;
       if (rSpeed<tr) rSpeed++;
       else if(rSpeed>tr) rSpeed--;

       left.write(lSpeed);
       right.write(rSpeed);
       delay(20);
       if(lSpeed==tl && rSpeed==tr) i=top-low;
     }
     fromL=tl;
     fromR=tr;
}

void Wheels::goForward(){
  toL = low;
  toR = top;
  go(toL, toR);
}

void Wheels::goBackwards(){
  toL = top;
  toR = low;
  go(toL, toR);
}
void Wheels::turnLeft(){
    toL = top;
    toR = top;
    go(toL, toR);
}
void Wheels::turnRight(){
    toL = low;
    toR = low;
    go(toL, toR);
}

void Wheels::standStill(){
  toL = still;
  toR = still;
  go(toL, toR);
}

void Wheels::follow(int d){
    int leftSpeed = constrain(ROBOT_SPEED+d, -100, 100);
    int rightSpeed = constrain(ROBOT_SPEED-d, -100, 100);

    leftSpeed = map(-leftSpeed, -100, 100, 40, 140);
    rightSpeed = map(rightSpeed, -100, 100, 40, 140);

    Serial.print(leftSpeed);
    Serial.print("  ");
    Serial.println(rightSpeed);

    left.write(leftSpeed);
    right.write(rightSpeed);
}




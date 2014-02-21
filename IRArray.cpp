#include "BasicEducationShield.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

IRArray::IRArray(int lpin, int mpin, int rpin){
	this->lpin=lpin;
	this->mpin=mpin;
	this->rpin=rpin;
	sensPins[0] = lpin;
	sensPins[1] = mpin;
	sensPins[2] = rpin;
	for(int i=0; i<3; i++){
      sensorVal[i]=0;
	}
}

int IRArray::readBinary(){
    for(int i=0; i<3; i++){
        toBinary[i]=0;
    }

    bool check = true;
    while(check){
        for(int i=0; i<3; i++){
            sensorVal[i] = constrain(map(analogRead(sensPins[i]), 350, 400, 1, 0), 0, 1);
        }

        for(int i=0; i<3; i++){
            if(sensorVal[i]) toBinary[i]=1;
            else if(!sensorVal[i]&&!sensorVal[i+1]&&!sensorVal[i+2]) check=false; //if all three are 0
        }
    }
    return translateBinary();
}

int IRArray::translateBinary(){
  byte o = (toBinary[2]?1:0)|(toBinary[1]?2:0)|(toBinary[0]?4:0);
  return o;
}
;

#include "BasicEducationShield.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

IRArray::IRArray(int IR1, int IR2, int IR3){
	this->IR1=IR1;
	this->IR2=IR2;
	this->IR3=IR3;
	sensPins[0] = IR1;
	sensPins[1] = IR2;
	sensPins[2] = IR3;
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

int IRArray::readLine(){
    int sum=0;
        for(int i=0; i<3; i++){
        int reading = constrain(analogRead(sensPins[i]), 60, 400);

        sensorVal[i]=map(reading,60,400,0,127);
        sum+=sensorVal[i];
        //Serial.println(sum);
    }
    int vel = 0;
    if(sum>LINE_THRESSHOLD) vel = calculateVelocity(sum);

    return vel;
}

int IRArray::calculateVelocity(int s){
    s/=3;

    int diff = ((sensorVal[0]<<5)-(sensorVal[2]<<5))/s;
    diff = constrain(diff,-100,100);

    int velocity = (diff * KP)/10 + (diff-last_diff)*KD;
     velocity = constrain(velocity, -100, 100);
    //Serial.println(velocity);
    last_diff = diff;

    delay(INTEGRATION_TIME);

    return velocity;
}

#include "IntelCTC.h"
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
	threshold = 380;
}

int IRArray::readBinary(){
    for(int i=0; i<3; i++){
        toBinary[i]=0;
    }

    bool check = true;
    while(check){
        for(int i=0; i<3; i++){
           // sensorVal[i] = constrain(map(analogRead(sensPins[i]), 350, 400, 1, 0), 0, 1);
		   sensorVal[i] = constrain(analogRead(sensPins[i]), 60, 400);
			if(sensorVal[i]<threshold) sensorVal[i]=1;
			else sensorVal[i]=0;
		}

        for(int i=0; i<3; i++){
            if(sensorVal[i]) toBinary[i]=1;
            else if(!sensorVal[0]&&!sensorVal[1]&&!sensorVal[2]) check=false; //if all three are 0
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
    last_diff = diff;

    delay(INTEGRATION_TIME);

    return velocity;
}

void IRArray::test(){
    for(int i=0; i<3; i++) sensorVal[i] = analogRead(sensPins[i]);

    Serial.print("IR1: ");
    Serial.print(sensorVal[0]);
    Serial.print("  IR2: ");
    Serial.print(sensorVal[1]);
    Serial.print("  IR3: ");
    Serial.println(sensorVal[2]);
}
void IRArray::setThreshold(int t){
	threshold=t;
}

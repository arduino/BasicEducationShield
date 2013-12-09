/*  Drawdio
*
*  Make everything(almost) into a music instrument!
*  Inspiration from Jay Siver's DRAWDIO
*
*  http://web.media.mit.edu/~silver/drawdio/
*
*/

#include <CapacitiveSensor.h>
#include "pitches.h"
#include <BasicEducationShield.h>

//Capacitive switch connected between 2 and 3
CapacitiveSwitch me=CapacitiveSwitch(2,3);

//A piezo speaker connected to digital pin 8
Melody speaker=Melody(8);

//The range of capacitive sensor values to be
//mapped to music tones. See example
//"help/CapacitiveSwitchTest" about how to get
//the values
int lowerThreshold=80;
int upperThreshold=900;

//Define the lowest and highest tone. Defined
//in pitches.h
int toneLow=NOTE_C4;
int toneHigh=NOTE_B4;

void setup(){
  //Nothing to do here. Magic?
}
void loop(){
  //Get value of the sensor. If it's smaller
  //than threshold, it'll be 0
  int value=me.getValue(lowerThreshold);

  //map the sensor value to tones. The map()
  //function maps values smaller than lower
  //threshold to the lowest desired value. If
  //you want to keep drawdio quiet when you're
  //not playing, you have to deal with 0 separately
  int pitch;
  if(value>0){
    pitch=map(value,lowerThreshold,upperThreshold,toneLow,toneHigh);
  }else{
    pitch=0;
  }

  //Play the tone to the speaker.
  speaker.playTone(pitch,10);
}

#include <Castilla.h>

//The number of knocks can be recorded
#define MAX_KNOCKS 30

PiezoKnockSensor sensor=PiezoKnockSensor(A0);
Melody speaker=Melody(8);

//An array for remembering the knock pattern
long timer[MAX_KNOCKS];

//If it has started recording
boolean started;

//Used for calculating if you have finished the pattern
long timeoutBase;

//If you stop knocking for the period of timeout, it'll 
//stop recording
long timeout=2000;

//Keep track of the number of knocks you've knocked
int currentKnock;

void setup(){
  Serial.begin(9600);
  //define the threshold and debounce time of the knock 
  //sensor. Threshold defines how hard you need to knock,
  //debounce time prevents the sensor from detecting 
  //false knocks, but also limits how rapid you can knock.
  sensor.config(40,80);
  
  //initializing the values
  started=false;
  timeoutBase=0;
  currentKnock=0;
  clearArray();
  
  //pinMode(8,OUTPUT);
  //digitalWrite(8,LOW);
}
void loop(){
  //Knock sensor waits for a short time and then move on. 
  if(sensor.knocked(10)){
    //If it's the first knock in the round, start recording
    if(!started){
      started=true;
    }
    
    long currentTime=millis();
    //Reset timeout
    timeoutBase=currentTime;
    //Record the knock
    timer[currentKnock]=currentTime;
    currentKnock++;
  }
  if(started){
    //If recording has started and you stop 
    //knocking for the time of "timeout", it'll
    //stop recording and play it back to you.
    if(millis()-timeoutBase>timeout){
      playback();
      //reset the parameters, so a new round begins
      started=false;
      clearArray();
      currentKnock=0;
    }
  }
}
void clearArray(){
  //clean up values in the timer array
  for(int i=0;i<MAX_KNOCKS;i++){
    timer[i]=0;
  }
}
void playback(){
  //Play the knock pattern back to you through the
  //speaker piezo
  for(int i=0;timer[i]!=0;i++){
    //Make a beep sound with tone 200 for 30 milliseconds
    speaker.playTone(200, 30);
    if(timer[i+1]){
      delay(timer[i+1]-timer[i]);
    }
  }
}

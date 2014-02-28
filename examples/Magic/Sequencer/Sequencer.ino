/*
  Sequencer
  Play beats and change the sequence in real time. Basically 
  all you need to become a hiphop artist. That, and rapping 
  skills. But that's another course. 
  
  (c) 2014 Arduino Verkstad
*/


#include "BasicEducationShield.h"

//We need to include the SD library to be able to read from an SD card
#include <SD.h>

//Declare the sound player
Player player=Player();

//There're 4 slots for 4 sequences. We use 4 analog pins
//to read them.
int analog_pins[]={4,3,2,1};
int pin_count=4;

//Template for the music file names.
char filename[]="seq0.wav";

void setup(){
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  // Initialize the sound player. Open the serial monitor to see
  //the sound files found on your micro SD card
  player.begin();

}
void loop(){
  //Loop through 4 pins and play the right sequence accordingly
  for(int i=0;i<pin_count;i++){
    int slot_value=analogRead(analog_pins[i]);
    int sequence=getSeq(slot_value);
    
    //Get the right file name by sequence
    filename[3]='0'+sequence;
    Serial.println(filename);
    //Play the file
    player.play(filename);
  }
  
  //End of one loop
  Serial.println("=======");
}
int getSeq(int analogVal){
  if(analogVal>200 && analogVal<300){  //220 Ohm
   return 1; 
  }else if(analogVal>360 && analogVal<460){  //470 Ohm
   return 2;
  }else if(analogVal>480 && analogVal<580){  //680 Ohm
   return 3;
  }else if(analogVal>600 && analogVal<700){  //1k2 Ohm
   return 4;
  }else{  //No resistor
   return 0; 
  }
}

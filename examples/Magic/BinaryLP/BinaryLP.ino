/*
  Binary LP
  
  (c) 2014 Arduino Verkstad
*/


#include <BasicEducationShield.h>
#include "pitches.h"

//IRArray(left, middle, right);
IRArray ir = IRArray(A1, A2, A3);

int piezo = 8; //Piezo pin
int lastByte = 0; 

void setup(){
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
}

void loop(){
  //Read the binary pattern and get a number from 0 to 7
  int readByte = ir.readBinary(); 
  
  //Play a note depending on the read value
  playNote(readByte);
  
  if(readByte) Serial.println(readByte);
}

void playNote(byte b){
  //If the last note we played is the same as the new note
  //we make a short break so that two notes are distinguished
  if(lastByte==b){
    noTone(piezo);
    delay(20);
  }
  
  //Play a different note depending on the value of b.
  //Check pitches.h to see which notes you can use.
  //In this case the scale is C Major.
  switch (b){
    case 0:
      break;
    case 1:
      tone(piezo, NOTE_C4);
      break;
    case 2:
      tone(piezo, NOTE_D4);
      break;
    case 3:
      tone(piezo, NOTE_E4);
      break;
    case 4:
      tone(piezo, NOTE_F4);
      break;
    case 5:
      tone(piezo, NOTE_G4);
      break;
    case 6:
      tone(piezo, NOTE_A4);
      break;
    case 7:
      tone(piezo, NOTE_B4);
      break;   
  }
  
  //If b is more than 0 we save that value to lastByte
  if(b>0)lastByte = b;
}

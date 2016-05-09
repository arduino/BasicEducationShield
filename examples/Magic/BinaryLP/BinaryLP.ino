/*
  Binary LP
  This sort of works as an LP player. The difference is 
  that instead of using a needle on a plastic disc, 
  we use three IR sensors in a row to read a pattern from 
  a paper disc. 
  
  If you are both musically and digitally inclined, 
  you will have lots of fun creating melodies with this. 
  
  (c) 2014 Arduino LLC
*/


#include <BasicEducationShield.h>
#include "pitches.h"

//IRArray(left, middle, right);
IRArray ir = IRArray(A1, A2, A3);

int piezo = 8; //Piezo pin
int lastReading = 0; 

void setup(){
  pinMode(piezo, OUTPUT);
}

void loop(){
  //Read the binary pattern and get a number from 0 to 7
  int reading = ir.readBinary(); 
  
  //Play a note depending on the read value
  playNote(reading);

}

void playNote(int r){
  //If the last note we played is the same as the new note
  //we make a short break so that two notes are distinguished
  if(lastReading==r){
    noTone(piezo);
    delay(20);
  }
  
  //Play a different note depending on the value of b.
  //Check pitches.h to see which notes you can use.
  //In this case the scale is C Major.
  switch (r){
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
  
  //If r is more than 0 we save that value to lastByte
  if(r>0)lastReading = r;
}

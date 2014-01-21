/*
	Melody
*/
#include <BasicEducationShield.h>

#include "pitches.h"

//8 is the pin the piezo is connected to.
Melody me=Melody(8);

void setup(){
}

void loop(){
  //Defining the notes used in the music. No more than 30.
  int notes[] = {
    NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

  //Duration of each note. should be corresponding to the notes above.
  int noteDurations[] = {
    4, 8, 8, 4,4,4,4,4 };

  //Play the notes defined above
  me.play(8,notes,noteDurations,1.4);

  delay(3000);

  //Make a beep sound
  me.beep();

  delay(3000);
}

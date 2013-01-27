/*	Melody
*
*	For playing sound with a piezo.
*	
*	Connect the red pin of piezo to a digital pin(8 in this example)
*	and the black pin to ground.
*
*/
#include <Castilla.h>

//pitches.h includes the definition of notes. Put it in your sketch
//folder if you want to play music.
#include "pitches.h"

//Declaring the component. 8 is the pin the piezo is connected to.
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
	
  //play(length, notes, duration, speed)
  //	length: number of notes in your music. 
  //	notes: the arry of notes.
  //	noteDuration: the array of note duration
  //	speed: how fast the music plays. No less than 1.0, the bigger the slower
  //
  //Play the notes defined above
  me.play(8,notes,noteDurations,1.4);
  
  delay(3000);
  
  //beep(length)
  //	length: how long the beep goes. Default to 30.
  //
  //Make a beep sound
  me.beep();
  
  delay(3000);
}

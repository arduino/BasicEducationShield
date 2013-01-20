#include <Castilla.h>
#include "pitches.h"

Melody me=Melody(8);

void setup(){
  Serial.begin(9600);
  int melody[] = {
    NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};
  int noteDurations[] = {
    4, 8, 8, 4,4,4,4,4 };
  //me.setMelody(8,melody,noteDurations);
  me.play(8,melody,noteDurations,1);
}
void loop(){
  
}

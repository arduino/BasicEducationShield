#include <CapacitiveSensor.h>
#include <Castilla.h>
#include "pitches.h"

int ledPins[] = {11, 12, 13};  
int pinCount = 3;
VUMeter LEDs;

CapacitiveSwitch foil[3];

int reactTime = 500;
int touch = 0;

Melody piezo = Melody(8); // the piezo connected to digital pin 8



void setup(){
  //if your are using other pins than 2 to 6 you need to configure that here
  LEDs.config(pinCount, ledPins); 
  LEDs.initialize();
  Serial.begin(9600);
  foil[0] = CapacitiveSwitch(5,4);
  foil[1] = CapacitiveSwitch(5,3);
  foil[2] = CapacitiveSwitch(5,2);
  foil[0].config(900);
  foil[1].config(900);
  foil[2].config(900);
  
}

void loop(){
  touch = random(0, 3);
  LEDs.on(touch);
  
  if(foil[touch].pressed(reactTime)){
    LEDs.off(touch);
    
    int melody[] = { NOTE_GS4, NOTE_C5};
    int noteDurations[] = { 8, 8};
    int numberOfNotes = 2;
    piezo.play(numberOfNotes, melody, noteDurations, 1);
    
    delay(random(50, 2000));
  }
  else{
    gameOver();
  }
}

void gameOver(){
  LEDs.fill(pinCount);
  
  int melody[] = { NOTE_E2, NOTE_C2};
  int noteDurations[] = { 2, 1};
  int numberOfNotes = 2;
  piezo.play(numberOfNotes, melody, noteDurations, 1);
  
  LEDs.blinkAll(100, 10);
  LEDs.fill(0);
  delay(random(50, 2000));
}

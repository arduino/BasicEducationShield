#include <CapacitiveSensor.h>
#include <Castilla.h>
#include "pitches.h"

//Define the 3 LEDs
int ledPins[] = {2, 3, 4};  
int pinCount = 3;
VUMeter LEDs;

//There're 3 pads for pressing
CapacitiveSwitch pad[3];

//You have 500 milliseconds to press the pad
int reactTime = 500;

// the piezo connected to digital pin 8
Melody piezo = Melody(8); 



void setup(){
  LEDs.config(pinCount, ledPins); 
  LEDs.begin();
  Serial.begin(9600);
  
  //Configure the pads
  pad[0] = CapacitiveSwitch(13,12);
  pad[1] = CapacitiveSwitch(13,11);
  pad[2] = CapacitiveSwitch(13,10);
  pad[0].config(900);
  pad[1].config(900);
  pad[2].config(900);
  
}

void loop(){    
  //Wait for a random time before each turn begins
  delay(random(50, 2000));
  
  //pick a target between the 3 pads
  int target = random(0, 3);
  //Light up the LED
  LEDs.on(target);
  
  //If the pad corresponding to the LED is pressed
  if(pad[target].pressed(reactTime)){
    LEDs.off(target);
    
	//Play the winning sound
    int melody[] = { NOTE_GS4, NOTE_C5};
    int noteDurations[] = { 8, 8};
    int numberOfNotes = 2;
    piezo.play(numberOfNotes, melody, noteDurations, 1);
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
}
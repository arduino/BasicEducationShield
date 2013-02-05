/*  SoundWave
*
*  SoundWave is a library for playing
*  .wav files from SD card for Arduino.
*
*/
#include <Castilla.h>

//We need this library for playing sound
#include <SoundWave.h>

//Declare the sound player
SoundWave player;

float multiplier=0.8;

void setup(){
  //Initialize the sound player
  player.begin();
}

void loop(){
  //play(filename)
  //  filename: filename of the sound stored in SD card
  //		must be a .wav file    
  //
  //Play the file named "0.wav" on SD card
  player.play("0.wav");
  
  //Stop the program from going further while the sound is
  //Playing. It's necessary to have this loop here
  while(player.isplaying){
	
    //setSampleRate(SampleRate)
    //  SampleRate: how fast the sound is played. Normally
    //    	it's based on original sample rate, 
    //		thus "player.dwSamplesPerSec*multiplier."
    //
    //		"multiplier" is a float point number, 
    //          typically between 0.5 and 2
    //
    //Change the sample rate during playback. Make it sounds
    //funny. It's not necessary for playing a sound.
    player.setSampleRate(player.dwSamplesPerSec*multiplier);

    delay(30);
  }
}

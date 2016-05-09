/*  Player
  You can play a sound from an SD card using the Player class.
  The sound file need to be 8bit, uncompressed WAV. Follow this
  tutorial to record and prepare your sound correctly: 
  http://cuartielles.com/LLC/en/Reference/PrepareWavSound
  
  Or use one of the .wav files in the BoomBox example. 
  
  (c) 2014 Arduino LLC
*/

#include <BasicEducationShield.h>

//We need to include the SD library to be able to read from an SD card
#include <SD.h>


Player player=Player();

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
  delay(1000);
}

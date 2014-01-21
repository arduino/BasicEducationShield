/*  
  Player
*/

#include <BasicEducationShield.h>
#include <SD.h>

Player player=Player();

void setup(){
  //Initialize the sound player
  player.begin();
}

void loop(){

  //Play the file named "0.wav" on SD card
  player.play("0.wav");
  delay(1000);
}

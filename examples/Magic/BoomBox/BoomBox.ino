/*
*Time to practice your DJ skills with the magic BoomBox! 
*Record some wav sound, save them in the SD card, 
*and you have a fun instrument for messing around with sound. 
*Bring it to a party next time and you’ll be the super star!
*/

#include <Castilla.h>

//We need this library for playing sound
#include <SoundWave.h>

//Declare the sound player
SoundWave player;

//Declare 4 buttons. The sound player will
//always take pin 3 and 11, so don't use them
Button b0=Button(4);
Button b1=Button(5);
Button b2=Button(6);

void setup(){
  Serial.begin(9600);
  //Initialize the sound player
  player.begin();
}
void loop(){
  //Play a different sound according to which 
  //button has been pressed
  switch(getInput()){
    case 0:
      player.play("0.wav");
    case 1:
      player.play("1.wav");
    case 2:
      player.play("2.wav");
  }
  
  //Keep the program waiting while the sound is 
  //being played, otherwise there'll be no sound!
  while(player.isplaying){
    
  }
}

//Wait for either of the 3 buttons to be pressed
int getInput(){
  while(true){
    if (b0.pressed(10))
      return 0;
    else if (b1.pressed(10))
      return 1;
    else if (b2.pressed(10))
      return 2;
  }
}

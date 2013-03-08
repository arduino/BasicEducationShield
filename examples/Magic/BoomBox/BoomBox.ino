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

//Declare a button group with 3 buttons. The 
//sound player secrectly takes pin 3 and 11,
//so don't use them
ButtonGroup bg;
int buttons[]={4,5,6};
//There're 3 buttons in the button group.
int buttonsCount=3;

void setup(){
  Serial.begin(9600);
  //Initialize the sound player
  player.begin();
  //Initialize the button group. 
  bg.begin(buttonsCount,buttons);

}
void loop(){
  //Wait for one of the buttons to be pressed.
  //According to which button is pressed, it 
  //returns either 0, 1 or 2
  int pressedButton=bg.pressed();
  
  //Play a different sound according to the
  //button pressed.
  switch(pressedButton){
    case 0:
      player.play("0.wav");
      break;
    case 1:
      player.play("1.wav");
      break;
    case 2:
      player.play("2.wav");
      break;
  }
  
  //Keep the program waiting while the sound is 
  //being played, otherwise there'll be no sound!
  while(player.isplaying){
    
  }
}



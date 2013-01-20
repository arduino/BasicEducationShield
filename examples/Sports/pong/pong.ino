/*
Description

*/


#include <Castilla.h>
/*
An array of pin numbers to which LEDs are attached
the defaults are 2 to 6 but you can choose any of the digital pins
just remember to leave digital pin 9 and 10 for the buttons
*/
int ledPins[] = {2, 3, 4, 5, 6};  
int pinCount = 5;
VUMeter vuMeter; 

Button button1 = Button(9, HIGH); //the button connected to digital pin 9
Button button2 = Button(10, HIGH); //the button connected to digital pin 10

int ledTime = 100; //determines how fast the LEDs will switch
int pressTime = 200; //determines how long time a player has to press the button

void setup(){
  //if your are using other pins than 2 to 6 you need to configure that here
  vuMeter.config(pinCount, ledPins); 
  
  vuMeter.initialize(); //does the same as pinMode, LEDs are outputs
  button1.initialize(); //does the same as pinMode, buttons are inputs
  button2.initialize(); //does the same as pinMode, buttons are inputs
  
  vuMeter.scrollLeft(ledTime, 1); //The game starts by scrolling the LEDs to the left
}

void loop(){
  /*
  if button1 is pressed within the press time, the game will continue
  by scrolling the LEDs to the right
  else if button1 is not pressed, the program will jump to gameOver()
  */
  if(button1.pressed(pressTime)){
    vuMeter.scrollRight(ledTime, 1);
  }
  else{
    gameOver();
  }
  
  /*
  if button2 is pressed within the press time, the game will continue
  by scrolling the LEDs to the left
  else if button2 is not pressed, the program will jump to gameOver()
  */
  if(button2.pressed(pressTime)){
    vuMeter.scrollLeft(ledTime, 1);
  }
  else{
    gameOver();
  }
}

/*
When a player doesn't press the right button within the right time it is game over.
Inside the function gameOver() you can decide how the LEDs should blink.
Use vuMeter.blink(LED,delayTime,numberOfBlinks) to make one specific LED blink
Use vuMeter.blinkAll(delayTime,numberOfBlinks) to make all LEDs blink
*/
void gameOver(){
  vuMeter.blinkAll(100,10);
  
  vuMeter.scrollLeft(ledTime, 1);//this starts the game again
}


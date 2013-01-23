/*
Racing

Run as fast as you can in this game. Tap two sensors
with your hands repeatedly, and you can see the progress
through the scoreboard made of a line of LEDs. When you
finally made it to the end, all LEDs on the scoreboard
will start blinking for your victory. 
*/
#include <CapacitiveSensor.h>
#include <Castilla.h>

/*
An array of pin numbers to which LEDs are attached
the defaults are 2 to 6 but you can choose any of the digital pins
just remember to leave digital pin 9 and 10 for the buttons
*/
int ledPins[] = {2, 3, 4, 5, 6};  
int pinCount = 5;
VUMeter scoreBoard;

//Configure the capacitive sensors
int capacitiveSensorThreshold=900;
CapacitiveSwitch leftFoot=CapacitiveSwitch(4,3);
CapacitiveSwitch rightFoot=CapacitiveSwitch(4,2);

int score;
boolean win;

void setup(){
  //initializing the game, set up all the components
  //and variables
  score=0;
  win=false;
  
  //Connect scoreboard
  scoreBoard.config(pinCount,ledPins);
  scoreBoard.initialize();
  
  //initialize left and right foot
  leftFoot.config(capacitiveSensorThreshold);
  rightFoot.config(capacitiveSensorThreshold);
}
void loop(){
  //Wait for the left foot to be pressed
  leftFoot.pressed();
  //Wait for the right foot to be pressed
  rightFoot.pressed();
  //After both feet are pressed, add one point
  score=score+1;
  //When you get 100 points, you win
  if(score>100){
    win=true;
  }
  //Every 20 points light up a led
  scoreBoard.fill(score/20);
  //if you win, blink all leds for celebration
  if(win){
    scoreBoard.blinkAll(100,4);
    //and reset the game
    win=false;
    score=0;
  }
  
}

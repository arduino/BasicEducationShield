#include <CapacitiveSensor.h>
#include <Castilla.h>

VUMeter scoreBoard;

CapacitiveSwitch leftFoot=CapacitiveSwitch(4,3);
CapacitiveSwitch rightFoot=CapacitiveSwitch(4,2);

int score;
boolean win;

void setup(){
  //initializing the game, set up all the components
  //and variables
  Serial.begin(9600);
  score=0;
  win=false;
  
  //Connect scoreboard
  int pins[]={9,10,11,12,13};
  scoreBoard.config(5,pins);
  scoreBoard.initialize();
  
  //initialize left and right foot
  leftFoot.config(900);
  rightFoot.config(900);
}
void loop(){
  if(!win){
    //Wait for the left foot to be pressed
    leftFoot.pressed();
    //Wait for the right foot to be pressed
    rightFoot.pressed();
    //if both feet are pressed, add one point
    score=score+1;
    Serial.println(score);
    //When you get 100 points, you win
    if(score>100){
      win=true;
    }
    //Every 20 points light up a led
    scoreBoard.fill(score/20);
  }else{
    //if you win, blink all leds for celebration
    scoreBoard.blinkAll(100,4);
    //and reset the game
    win=false;
    score=0;
  }
  
}

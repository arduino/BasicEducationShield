boolean[][] recordArray = new boolean[30][3];
int hypPointer;

//w and h of page (A4 proportions)
int w = 595;
int h = 841;

//have a line every "changeDegree" degree
int changeDegree = 30;

int strokeColor = 0;

// button placement parameters
int buttonPosition=300;
int buttonWidth=100;
int buttonHeight=50;
int topLimit = -(buttonPosition-(buttonHeight/2));
int bottomLimit = -(buttonPosition+(buttonHeight/2));
int leftLimit = -buttonWidth/2;
int rightLimit = buttonWidth/2;

float Hypotenuse;
float newX,newY;
int rotateValue;

int arrayCounter = 0;
ArrayList<recordMarkers> recordData;



boolean drawMark;
boolean record = false;

import processing.pdf.*;



void setup(){
  
  size(w,h);
  
  for(int i=0;i<30;i++){
    for(int j=0;j<3;j++){
      recordArray[i][j] = false;
    }
  }
  
  println(recordArray[1][1]);
      
  
  //  Deletes existing record.pdf file, if any
  String fileName = sketchPath("record.pdf");
  File file = sketchFile(fileName);
  
  // Checks if file exists
  if (file.exists()){
    println("The file exists"); 
  }
  else{
    println("The file doesn't exist");
  }
  //
  
  System.gc(); // the key to success
  
  boolean success = file.delete();
  
  if (success) { 
    println("The file was deleted");
  }
  //
  
  recordData = new ArrayList<recordMarkers>();

}

void draw() {
  
  background(255);

// Calculates new coordinates based new origin
  newX = mouseX-w/2; 
  newY = -(mouseY-h/2);
//


// Starts record if Save PDF button is selected  
  if(record){
  beginRecord(PDF, "record.pdf"); 
  }
//

// Must place these here because beginRecord resets translate and mode to CORNER
  translate(w/2,h/2);  // Moves origin to center of frame
  ellipseMode(CENTER);
  rectMode(CENTER);
//

  redrawBackgroundImage();  // Draws the background circular record disc
 
  redrawButton();  // Draws the "Press to save as PDF" button

  calculateHypotenuse();  // Calculates the distance of the cursor from the translated center 
  
  measureAngle();
  
  drawMarkers();

// Stops record after one frame and exits
  if(record){
    endRecord(); 
    record=false;
    exit();
  }
//  
    
} // end draw()


//*********************************************************************************
//
// Activates when mouse is clicked
//
// Checks if PDF save button is clicked or if marker is placed on record
//
//*********************************************************************************
void mouseClicked() {
  if(newY<topLimit && newY>bottomLimit && newX>= leftLimit && newX<=rightLimit){
    record=true;
  }
  
  if(drawMark)recordArray[rotateValue/12][hypPointer] = !recordArray[rotateValue/12][hypPointer]; // Reverses current marking
  
}  // end mouseClicked()


//*********************************************************************************
//
// Draws recordMarker matrix
//
// Checks matrix and places a mark if true
//
//*********************************************************************************
void drawMarkers(){
  fill(0);
  for(int i=0;i<30;i++){
    if(recordArray[i][0]){
      rotate(radians(i*12));
      rect(68, 0, 24,7);
      rotate(-radians(i*12));
    }
    if(recordArray[i][1]){
      rotate(radians(i*12));
      rect(104, 0, 24,13);
      rotate(-radians(i*12));
    }
    if(recordArray[i][2]){
      rotate(radians(i*12));
      rect(141, 0, 24,18);
      rotate(-radians(i*12));
    }
  }
}
      

//*********************************************************************************
//
// Measures angle of mouse to new center
//
// Calculates the angle and adjusts it to mathematic degree system
//
//*********************************************************************************
void measureAngle(){
  if (newX != 0){
    if(newX>0 && newY>=0){
       rotateValue = 360-round(degrees(atan(newY/newX))/12)*12;
    }
    if(newX<0 && newY>0){
      rotateValue = 180 + -round(degrees(atan(newY/newX))/12)*12;
    }
    if(newX<0 && newY<0){
      rotateValue = 180-round(degrees(atan(newY/newX))/12)*12;
    }
    if(newX>0 && newY<0){
      rotateValue = -round(degrees(atan(newY/newX))/12)*12;
    }
  }
  else{
    if (newY>0){
      rotateValue = 270;
    }
    else{
      rotateValue = 90;
    }
  }
  if(rotateValue==360)rotateValue=0;
}



//*********************************************************************************
//
// Calculates the distance of the cursor from the translated center
//
// Calculates the distance from the center and adjusts so that the box will only draw
//   within the white rings
//
//*********************************************************************************
void calculateHypotenuse(){
  
  Hypotenuse=sqrt(sq(newX)+sq(newY));  // Calculates "hypotenuse"/radius from XY location

  if (Hypotenuse>306/2 || Hypotenuse<113/2){
    drawMark=false;
  }
  else{
    drawMark=true;
  }

  if(Hypotenuse>=258/2){
    Hypotenuse=306/2;
  }
  else{
    if(Hypotenuse>=186/2){
      Hypotenuse=233/2;
    }
    else{
      if(Hypotenuse>=113/2||Hypotenuse<113/2){
        Hypotenuse=161/2;
      }
    }   
  }
  Hypotenuse=Hypotenuse-12;
 
  if (Hypotenuse == 141)hypPointer=2;
  if (Hypotenuse == 104)hypPointer=1;
  if (Hypotenuse == 68)hypPointer=0;
   
} // end calculateHypotenuse()



//*********************************************************************************
//
// Draws the "Press to save as PDF" button
//
// Draws the button and changes the color with hover over
//
//*********************************************************************************
void redrawButton(){
  
  //  Calcuates if mouse is hovering over button and changes the fill accordingly
  if(newY<topLimit && newY>bottomLimit && newX>= leftLimit && newX<=rightLimit){
      fill(0);
    }
    else{
      fill(100);
    }
  //
  
  rect(0,300,buttonWidth,buttonHeight); // Draws rectangular button
  
  // Draws the text on the button
  fill(255);
  textAlign(CENTER,CENTER);
  text("Press here",0,283);
  text("to save as",0,298);
  text("PDF file",0,313);
  //
  
}  //end redrawButton()



//*********************************************************************************
//
// Draws the background circular record disc
//
// Draws the gray and white circles successively to produce ring pattern
//
//*********************************************************************************

void redrawBackgroundImage() {

  noStroke();
  
  fill(200);
  ellipse(0, 0, 354, 354);
  
  fill(255);
  ellipse(0, 0, 306, 306);  
  
  fill(200);
  ellipse(0, 0, 258, 258);  
  fill(255);
  ellipse(0, 0, 233, 233);
  
  fill(200);
  ellipse(0, 0, 186, 186);

  fill(255);
  ellipse(0, 0, 161, 161);
  
  fill(200);
  ellipse(0, 0, 113, 113);
 
 stroke(200);
 for(int i=0;i<30;i++){
   rotate(radians(i*12));
   line(50,0,175,0);
   rotate(-radians(i*12));
 } 

 stroke(strokeColor);
 strokeWeight(1);
 ellipse(0, 0, 101, 101);

 
  
  for(int j=360;j>=changeDegree;j=j-changeDegree){
    rotate(radians(changeDegree)); 
    line(0,0,50,0);
  }
  noStroke();
  fill(255);
  ellipse(0, 0, 74, 74);
  
}  //end redrawBackgroundImage()

class recordMarkers{
  float markerAngle;
  float markerHypotenuse;
}

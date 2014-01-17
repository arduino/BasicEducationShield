#include "BasicEducationShield.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

Player::Player(){
	//this->pin=pin;
	//this->pressedValue=pressedValue;
}
void Player::begin(){
	//Must be called in setup
	initPlayer();
	initSD();
}

void Player::play(char* name) {
    this->name=name;
    int count=0;

  // open wave file from sdcard
  File myFile = SD.open(name);
  if (!myFile) {
    // if the file didn't open, print an error and stop
    Serial.println("error opening test.wav");
    while (true);
  }

  const int S=512; // Number of samples to read in block
  byte buffer[S];

  Serial.print("Playing");
  // until the file is not finished
  int header = 128;
  byte data = 0;
  while (myFile.available()) {
    // read from the file into buffer
    //myFile.read(buffer, sizeof(buffer));
    data = myFile.read();
    header--;

    if (header <= 0) {
      header = 0;
      analogWrite(3, data);
      delayMicroseconds(40);
    }

    // Prepare samples
    // Dump the whole song to the serial port
    //Serial.write(buffer, sizeof(buffer));

    // Every 100 block print a '.'
    count++;
    if (count == 1000) {
      Serial.print(".");
      count = 0;
    }
  }
  myFile.close();

  Serial.println("End of file. Thank you for listening!");

}

void Player::initPlayer() {
    // set the PWM on pin 3 to 31250
    TCCR2B = TCCR2B & 0b11111000 | 0x01;
}

void Player::initSD() {
  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(10, OUTPUT);

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  root = SD.open("/");

  printDirectory(root, 0);

  Serial.println("done!");
}
void Player::printDirectory(File dir, int numTabs) {
   while(true) {

     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       //Serial.println("**nomorefiles**");
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}


#include <SoundWave.h>
#include <Arduino.h>

#define error(msg) Serial.println(msg)

//------------------------------------------------------------------------------
/** create an instance of WaveHC. */
SoundWave::SoundWave():WaveHC() {
}
//------------------------------------------------------------------------------

/**
 * Initialize the thing, the speaker pin is number 3
 *
 */
void SoundWave::begin() {
  if (!card.init()) {         //play with 8 MHz spi (default faster!)  
    error("Card init. failed!");  // Something went wrong, lets print out why
  }

  // enable optimize read - some cards may timeout. Disable if you're having problems
  card.partialBlockRead(true);
  
  // Now we will look for a FAT partition!
  uint8_t part;
  for (part = 0; part < 5; part++) {   // we have up to 5 slots to look in
    if (vol.init(card, part)) 
      break;                           // we found one, lets bail
  }
  if (part == 5) {                     // if we ended up not finding one  :(
    error("No valid FAT partition!");  // Something went wrong, lets print out why
  }

    // Try to open the root directory
  if (!root.openRoot(vol)) {
    error("Can't open root dir!");      // Something went wrong,
  }
  
  pinMode(3, OUTPUT);
  
  
}

void SoundWave::play(char * fileName) {
  if(!file.open(root,fileName)) error("open by name fail");
  if(!create(file))error("create fail");
  WaveHC::play();
  //while(isplaying);
  //Serial.println(fileName);
}

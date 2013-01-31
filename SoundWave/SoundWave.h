/*
 This library is a simplification of WaveHC's library for Ladyada's Wave Shield library.
*/
#ifndef SoundWave_h
#define SoundWave_h
#include <WaveHC.h>

class SoundWave : public WaveHC {
public:
  SoundWave();
  void begin();
  void play(char * fileName);

private:
  SdReader card;
  FatVolume vol;
  FatReader root;
  FatReader file;
};

#endif

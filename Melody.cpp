#include "BasicEducationShield.h"
#include "pitches.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

Melody::Melody(int pin){
	this->pin=pin;
	/*
	for(int i=0;i<LENGTH;i++){
		notes[i]=-1;
		duration[i]=0;
	}*/
}
void Melody::play(int length, int notes[],int duration[],float speed){
	//Play the melody passed directly to this function. Saving memory
	//and avoiding variable scope problems.
	//length is the number of notes.
	//speed is a float bigger than 1. The bigger it is, the slower
	//sound it makes.
	for(int i=0;i<length && notes[i]!=-1 ;i++){
		tone(pin,notes[i],1000/duration[i]);
		int pauseBetweenNotes = 1000/duration[i]*speed;
		delay(pauseBetweenNotes);
		noTone(8);
	}
}
void Melody::beep(int note, int length){
	//Make a beep sound
	int notes[]={note};
	int duration[]={1000/length};
	play(1,notes,duration,1);
}
void Melody::playTone(int note,int length){
	//Play a certain tone. Much more flexible than defined notes.
	tone(pin,note,length+5);
	delay(length);
}

void Melody::effect_win(){
	int melody[] = { NOTE_C5, NOTE_G4,NOTE_G4, NOTE_A4, NOTE_G4, 0, NOTE_B4, NOTE_C5};
	int noteDurations[] = { 4, 8, 8, 4,4,4,4,4 };
	int numberOfNotes = 8;
	this->play(numberOfNotes, melody, noteDurations, 1);
}
void Melody::effect_gameover(){
	int melody[] = { NOTE_E2, NOTE_C2};
	int noteDurations[] = { 2, 1};
	int numberOfNotes = 2;
	this->play(numberOfNotes, melody, noteDurations, 1);
}
void Melody::effect_score(){
    int melody[] = { NOTE_GS4, NOTE_C5};
    int noteDurations[] = { 8, 8};
    int numberOfNotes = 2;
    this->play(numberOfNotes, melody, noteDurations, 1);
}

/*
void Melody::setMelody(int length, int notes[],int duration[]){
	this->length=length;
	for(int i=0;i<length;i++){
		this->notes[i]=notes[i];
		this->duration[i]=1000/duration[i];
	}
}

void Melody::play(){
	for(int i=0;i<length && notes[i]!=-1 ;i++){
		Serial.print(notes[i]);
		Serial.print("\t");
		Serial.println(duration[i]);

		tone(pin,notes[i],duration[i]);
		int pauseBetweenNotes = duration[i];
		delay(pauseBetweenNotes);
		noTone(8);
	}
}

void Melody::setNote(int index,int note){
	notes[index]=note;
}
int Melody::getNote(int index){
	return notes[index];
}
void Melody::setDuration(int index, int duration){
	this->duration[index]=duration;
}
int Melody::getDuration(int index){
	return duration[index];
}
*/

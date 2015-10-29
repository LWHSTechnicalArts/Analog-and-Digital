// Simple WAV file player example
//
// Requires the audio shield:
//   http://www.pjrc.com/store/teensy3_audio.html
//
// Data files to put on your SD card can be downloaded here:
//   http://www.pjrc.com/teensy/td_libs_AudioDataFiles.html
//
// This example code is in the public domain.  
//modified 10-15 by A.Kleindolph

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playWav1;       //xy=154,78
AudioOutputI2S           i2s1;           //xy=334,89
AudioConnection          patchCord1(playWav1, 0, i2s1, 0);
AudioConnection          patchCord2(playWav1, 1, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=240,153
// GUItool: end automatically generated code

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(100);

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);

  SPI.setMOSI(7);
  SPI.setSCK(14);
  if (!(SD.begin(10))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
}

void loop() {

  Serial.print(digitalRead(0));
  Serial.print(digitalRead(1));
  Serial.print(digitalRead(2));
  Serial.print(digitalRead(3));
  Serial.println();
  
  if (digitalRead(0) == LOW) {
    playFile("jawharp.wav");
  }
  if (digitalRead(1) == LOW) {
    playFile("flamenco.wav");
  }
  if (digitalRead(2) == LOW) {
    playFile("powermet.wav");
  }
  if (digitalRead(3) == LOW) {
    playFile("gamelan.wav");
  }
}

void playFile(const char *filename)
{
  //Serial.print("Playing file: ");
  //Serial.println(filename);
  playWav1.play(filename);    //Start playing the file.  This sketch continues to run while the file plays.
  delay(5);   // A brief delay for the library read WAV info
}

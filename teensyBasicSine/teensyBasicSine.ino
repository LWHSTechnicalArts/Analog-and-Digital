#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
//#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=262,298
AudioOutputI2S           i2s1;           //xy=533,302
AudioConnection          patchCord1(sine1, 0, i2s1, 0);
AudioConnection          patchCord2(sine1, 0, i2s1, 1);
// GUItool: end automatically generated code

void setup() {
  AudioMemory(2);   // required to play audio
}

void loop() {
  sine1.frequency(100);   // set sine frequency
  sine1.amplitude(0.5);   // set sine volume
  Serial.println(sine1.processorUsage());   //see how much audio memory the sine is using
}

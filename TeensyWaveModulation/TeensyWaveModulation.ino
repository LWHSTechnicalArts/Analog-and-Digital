
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=137,157
AudioSynthWaveform       waveform2;      //xy=140,230
AudioEffectMultiply      multiply1;      //xy=326,184
AudioOutputI2S           i2s1;           //xy=583,184
AudioConnection          patchCord1(waveform1, 0, multiply1, 0);
AudioConnection          patchCord2(waveform2, 0, multiply1, 1);
AudioConnection          patchCord3(multiply1, 0, i2s1, 0);
AudioConnection          patchCord4(multiply1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=306,95
// GUItool: end automatically generated code

void setup() {
  AudioMemory(10);   // required to play audio
  pinMode(0, INPUT_PULLUP);
  sgtl5000_1.enable();     //enable audio shield
  sgtl5000_1.volume(0.5);  //set overall volume
  waveform1.begin(0.4, 100, WAVEFORM_SQUARE);
  waveform2.begin(0.4, 100, WAVEFORM_TRIANGLE);
}

void loop() {
  waveform1.frequency(100);
  
  for (float i = 80; i < 130; i += 0.1) {
    waveform2.frequency(i);
    delay(50);
  }
  for (float i = 130; i > 80; i -= 0.1) {
    waveform2.frequency(i);
    delay(50);
  }
}

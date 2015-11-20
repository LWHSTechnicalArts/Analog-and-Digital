#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=144,277
AudioMixer4              mixer1;         //xy=474,339
AudioEffectFade          fade1;          //xy=610,338
AudioOutputI2S           i2s1;           //xy=745,337
AudioConnection          patchCord1(waveform1, 0, mixer1, 0);
AudioConnection          patchCord2(mixer1, fade1);
AudioConnection          patchCord3(fade1, 0, i2s1, 0);
AudioConnection          patchCord4(fade1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=472,181
// GUItool: end automatically generated code

void setup() {
  AudioMemory(10);   // required to play audio
  sgtl5000_1.enable();     //enable audio shield
  sgtl5000_1.volume(0.5);  //set overall volume
  waveform1.begin(0.3, 100, WAVEFORM_SQUARE);
}

void loop() {
  fade1.fadeIn(1000);
  delay(1000);
  waveform1.frequency(100);
  fade1.fadeOut(1000);
  delay(1000);

}




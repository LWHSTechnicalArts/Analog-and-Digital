#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine2;          //xy=156,317
AudioSynthWaveformSine   sine1;          //xy=157,260
AudioSynthWaveformSine   sine3;          //xy=157,372
AudioSynthWaveformSine   sine4;          //xy=158,429
AudioMixer4              mixer1;         //xy=369,339
AudioOutputI2S           i2s1;           //xy=530,336
AudioConnection          patchCord1(sine2, 0, mixer1, 1);
AudioConnection          patchCord2(sine1, 0, mixer1, 0);
AudioConnection          patchCord3(sine3, 0, mixer1, 2);
AudioConnection          patchCord4(sine4, 0, mixer1, 3);
AudioConnection          patchCord5(mixer1, 0, i2s1, 0);
AudioConnection          patchCord6(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=370,179
// GUItool: end automatically generated code

int waveOne = 0;
int waveTwo = 0;
int waveThree = 0;
int waveFour = 0;

void setup() {
  AudioMemory(10);   // required to play audio
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  sgtl5000_1.enable();     //enable audio shield
  sgtl5000_1.volume(0.6);  //set overall volume

  sine1.frequency(0);   // set sine frequency
  sine1.amplitude(0.6);   // set sine volume

  sine2.frequency(0);   // set sine frequency
  sine1.amplitude(0.6);   // set sine volume

  sine1.frequency(0);   // set sine frequency
  sine1.amplitude(0.6);   // set sine volume
}

void loop() {
  if (digitalRead(0) == LOW) {
    waveOne = 260;
  } else {
    waveOne = 0;
  }
  if (digitalRead(1) == LOW) {
    waveTwo = 360;
  } else {
    waveTwo = 0;
  }
  if (digitalRead(2) == LOW) {
    waveThree = 420;
  } else {
    waveThree = 0;
  }

   if (digitalRead(3) == LOW) {
    waveThree = 440;
  } else {
    waveFour = 0;
  }
  sine1.frequency(waveOne);   // set sine frequency
  sine2.frequency(waveTwo);   // set sine frequency
  sine3.frequency(waveThree);   // set sine frequency
  sine4.frequency(waveFour);   // set sine frequency

  Serial.print(digitalRead(0));
  Serial.print(digitalRead(1));
  Serial.print(digitalRead(2));
  Serial.print(digitalRead(3));


}

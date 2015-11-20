#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=163,151
AudioSynthWaveform       waveform2;      //xy=164,199
AudioSynthWaveform       waveform3;      //xy=165,250
AudioSynthWaveform       waveform4;      //xy=166,299
AudioMixer4              mixer1;         //xy=354,212
AudioOutputI2S           i2s1;           //xy=541,215
AudioConnection          patchCord1(waveform1, 0, mixer1, 0);
AudioConnection          patchCord2(waveform2, 0, mixer1, 1);
AudioConnection          patchCord3(waveform3, 0, mixer1, 2);
AudioConnection          patchCord4(waveform4, 0, mixer1, 3);
AudioConnection          patchCord5(mixer1, 0, i2s1, 0);
AudioConnection          patchCord6(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=346,95
// GUItool: end automatically generated code

void setup() {
  pinMode(0, INPUT_PULLUP);

  AudioMemory(10);   // required to play audio
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);


  sgtl5000_1.enable();     //enable audio shield
  sgtl5000_1.volume(0.5);  //set overall volume

  waveform1.begin(0.4, 0, WAVEFORM_SQUARE);
  waveform2.begin(0.4, 0, WAVEFORM_TRIANGLE);
  waveform3.begin(0.4, 0, WAVEFORM_SINE);
  waveform4.begin(0.4, 0, WAVEFORM_SAWTOOTH);
}

void loop() {
  if (digitalRead(0) == LOW || digitalRead(1) == LOW || digitalRead(2) == LOW || digitalRead(3) == LOW) {
    ascend();
  }
  waveform1.frequency(0);
  waveform2.frequency(0);
  waveform3.frequency(0);
  waveform4.frequency(0);
  //delay(100);
}

void ascend() {
  for (int i = 200; i < 400; i += 50) {
    if (digitalRead(0) == LOW) {
      waveform1.frequency(i - 50);
    }
    if (digitalRead(1) == LOW) {
      waveform2.frequency(i + 100);
      waveform3.frequency(i - 100);
    }
    if (digitalRead(3) == LOW) {
      waveform4.frequency(i);
    }

    if (digitalRead(2) == LOW) {
      waveform3.frequency(i * 2);
    }
    delay(100);
  }
}

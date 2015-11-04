
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=64,154
AudioEffectChorus        chorus1;        //xy=219,160
AudioEffectFlange        flange1;        //xy=268,242
AudioMixer4              mixer1;         //xy=412,245
AudioOutputI2S           i2s1;           //xy=589,187
AudioConnection          patchCord1(waveform1, chorus1);
AudioConnection          patchCord2(chorus1, flange1);
AudioConnection          patchCord3(flange1, 0, mixer1, 0);
AudioConnection          patchCord4(mixer1, 0, i2s1, 0);
AudioConnection          patchCord5(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=346,95
// GUItool: end automatically generated code

// Number of samples in each delay line
#define CHORUS_DELAY_LENGTH (4*AUDIO_BLOCK_SAMPLES)
#define FLANGE_DELAY_LENGTH (2*AUDIO_BLOCK_SAMPLES)
// Allocate the delay lines for channel
short l_delayline[CHORUS_DELAY_LENGTH];
short l_delaylineF[FLANGE_DELAY_LENGTH];

int s_idx = FLANGE_DELAY_LENGTH / 16;
int s_depth = FLANGE_DELAY_LENGTH / 4;
double s_freq = .15;

int up = 0;

void setup() {
  AudioMemory(30);   // required to play audio
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);


  sgtl5000_1.enable();     //enable audio shield
  sgtl5000_1.volume(0.5);  //set overall volume

  waveform1.begin(0.4, 0, WAVEFORM_TRIANGLE);
  chorus1.begin(l_delayline, CHORUS_DELAY_LENGTH, 2);
  flange1.begin(l_delayline, FLANGE_DELAY_LENGTH, s_idx, s_depth, s_freq);
}

void loop() {
  if (digitalRead(0) == LOW) {
    change();
  }
  if (digitalRead(1) == LOW) {
    up += 2;
  }
  if (digitalRead(2) == LOW) {
    up -= 2;
  }
  if (digitalRead(0)==HIGH){
  waveform1.frequency(0);
  }

}

void change() {
  if (digitalRead(0) == LOW) {
    waveform1.frequency(100 + up);
    delay(150);
  }

  Serial.println(AudioProcessorUsageMax());
}

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav1;     //xy=106,133
AudioEffectDelay         delay1;         //xy=263,195
AudioMixer4              mixer1;         //xy=425,187
AudioOutputI2S           i2s1;           //xy=585,186
AudioConnection          patchCord1(playSdWav1, 0, delay1, 0);
AudioConnection          patchCord2(delay1, 0, mixer1, 0);
AudioConnection          patchCord3(delay1, 1, mixer1, 1);
AudioConnection          patchCord4(delay1, 2, mixer1, 2);
AudioConnection          patchCord5(delay1, 3, mixer1, 3);
AudioConnection          patchCord6(mixer1, 0, i2s1, 0);
AudioConnection          patchCord7(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=429,85
// GUItool: end automatically generated code


void setup() {
  // put your setup code here, to run once:
  AudioMemory(120);   // required to play audio
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);

  sgtl5000_1.enable();     //enable audio shield
  sgtl5000_1.volume(0.5);  //set overall volume




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
  if (digitalRead(0) == LOW) {    //delay on
    delay1.delay(0, 10);
    delay1.delay(1, 50);
    delay1.delay(2, 250);
    delay1.delay(3, 325);
    playSdWav1.play("jawharp.wav");
  }
  if (digitalRead(1) == LOW) {     //delay off
    delay1.delay(0, 0);
    playSdWav1.play("jawharp.wav");
  }
}

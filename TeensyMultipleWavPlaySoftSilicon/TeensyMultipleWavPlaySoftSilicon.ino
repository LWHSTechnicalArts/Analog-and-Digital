#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav3;     //xy=221,284
AudioPlaySdWav           playSdWav2;     //xy=226,214
AudioPlaySdWav           playSdWav1;     //xy=231,138
AudioMixer4              mixer1;         //xy=419,238
AudioOutputI2S           i2s1;           //xy=580,237
AudioConnection          patchCord1(playSdWav3, 0, mixer1, 2);
AudioConnection          patchCord2(playSdWav2, 0, mixer1, 1);
AudioConnection          patchCord3(playSdWav1, 0, mixer1, 0);
AudioConnection          patchCord4(mixer1, 0, i2s1, 0);
AudioConnection          patchCord5(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=386,55
// GUItool: end automatically generated code

void setup() {
  // put your setup code here, to run once:
  AudioMemory(120);   // required to play audio
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  pinMode(15, OUTPUT);

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
  digitalWrite(15, HIGH);
  delay(500);
  digitalWrite(15, LOW);
}

void loop() {
  digitalWrite(15, LOW);
  // put your main code here, to run repeatedly:
  if (digitalRead(0) == LOW) {
    digitalWrite(15, HIGH);
    playSdWav1.play("jawharp.wav");
    Serial.print(digitalRead(0));
    delay(300);
  }
  if (digitalRead(1) == LOW) {
    playSdWav2.play("flamenco.wav");
  }
  if (digitalRead(2) == LOW) {
    playSdWav3.play("powermet.wav");
  }
  if (digitalRead(3) == LOW) {
    playSdWav3.play("b.wav");
  }
}

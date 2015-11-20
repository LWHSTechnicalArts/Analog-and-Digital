#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=262,298
AudioOutputI2S           i2s1;           //xy=533,302
AudioConnection          patchCord1(sine1, 0, i2s1, 0);
AudioConnection          patchCord2(sine1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=445,227
// GUItool: end automatically generated code

void setup() {
  AudioMemory(2);   // required to play audio
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);

  sgtl5000_1.enable();     //enable audio shield
  sgtl5000_1.volume(0.5);  //set overall volume

  sine1.frequency(0);   // set sine frequency
  sine1.amplitude(0.5);   // set sine volume
}

void loop() {
  if (digitalRead(0) == LOW) {
    sine1.frequency(100);   // set sine frequency
    sine1.amplitude(0.5);   // set sine volume
    delay(50);
  }
  if (digitalRead(1) == LOW) {
    sine1.frequency(200);   // set sine frequency
    sine1.amplitude(0.5);   // set sine volume
    delay(50);
  }
  if (digitalRead(2) == LOW) {
    sine1.frequency(300);   // set sine frequency
    sine1.amplitude(0.5);   // set sine volume
    delay(50);
  }
  sine1.frequency(0);   // set sine frequency
  Serial.print(digitalRead(0));
  Serial.println(sine1.processorUsage());   //see how much audio memory the sine is using
}

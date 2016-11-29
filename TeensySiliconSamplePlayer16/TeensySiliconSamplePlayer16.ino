/***************************************************
  This is a test example for the Adafruit Trellis w/HT16K33

  Designed specifically to work with the Adafruit Trellis
  ----> https://www.adafruit.com/products/1616
  ----> https://www.adafruit.com/products/1611

  These displays use I2C to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "Adafruit_Trellis.h"

/***************************************************
  This example shows reading buttons and setting/clearing buttons in a loop
  "momentary" mode has the LED light up only when a button is pressed
  "latching" mode lets you turn the LED on/off when pressed

  Up to 8 matrices can be used but this example will show 4 or 1
 ****************************************************/

#define MOMENTARY 0
#define LATCHING 1
// set the mode here
#define MODE MOMENTARY


Adafruit_Trellis matrix0 = Adafruit_Trellis();

// uncomment the below to add 3 more matrices
/*
  Adafruit_Trellis matrix1 = Adafruit_Trellis();
  Adafruit_Trellis matrix2 = Adafruit_Trellis();
  Adafruit_Trellis matrix3 = Adafruit_Trellis();
  // you can add another 4, up to 8
*/

// Just one
Adafruit_TrellisSet trellis =  Adafruit_TrellisSet(&matrix0);
// or use the below to select 4, up to 8 can be passed in
//Adafruit_TrellisSet trellis =  Adafruit_TrellisSet(&matrix0, &matrix1, &matrix2, &matrix3);

// set to however many you're working with here, up to 8
#define NUMTRELLIS 1

#define numKeys (NUMTRELLIS * 16)

// Connect Trellis Vin to 5V and Ground to ground.
// Connect the INT wire to pin #A2 (can change later!)
#define INTPIN A2
// Connect I2C SDA pin to your Arduino SDA line
// Connect I2C SCL pin to your Arduino SCL line
// All Trellises share the SDA, SCL and INT pin!
// Even 8 tiles use only 3 wires max

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
  Serial.begin(9600);
  Serial.println("Trellis Demo");

  AudioMemory(120);   // required to play audio

  // INT pin requires a pullup
  pinMode(INTPIN, INPUT);
  digitalWrite(INTPIN, HIGH);

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
  // begin() with the addresses of each panel in order
  // I find it easiest if the addresses are in order
  trellis.begin(0x70);  // only one
  // trellis.begin(0x70, 0x71, 0x72, 0x73);  // or four!

  // light up all the LEDs in order
  for (uint8_t i = 0; i < numKeys; i++) {
    trellis.setLED(i);
    trellis.writeDisplay();
    delay(50);
  }
  // then turn them off
  for (uint8_t i = 0; i < numKeys; i++) {
    trellis.clrLED(i);
    trellis.writeDisplay();
    delay(50);
  }
}


void loop() {
  delay(30); // 30ms delay is required, dont remove me!

  // If a button was just pressed or released...
  if (trellis.readSwitches()) {
    // go through every button
    for (uint8_t i = 0; i < numKeys; i++) {
      // if it was pressed, turn it on
      if (trellis.justPressed(i)) {
        Serial.print("v"); Serial.println(i);
        trellis.setLED(i);
        playSample(i);
      }
    }
    trellis.writeDisplay();
  }
  clearLeds();
}
void playSample(int i) {
  char *samples[] = {"jawharp.wav", "flamenco.wav", "powermet.wav"};
  switch (i) {
    case (0):
      if (playSdWav1.isPlaying() == false) {
        playSdWav1.play(samples[i]);
      } else {
        playSdWav1.stop();
      }
      break;
    case (1):
      if (playSdWav2.isPlaying() == false) {
        playSdWav2.play(samples[i]);
      } else {
        playSdWav2.stop();
      }
      break;
    case (2):
      if (playSdWav3.isPlaying() == false) {
        playSdWav3.play(samples[i]);
      } else {
        playSdWav3.stop();
      }
      break;
  }
}

void clearLeds() {
  if (playSdWav1.isPlaying() == false) {
    trellis.clrLED(0);
    trellis.writeDisplay();
  }
  if (playSdWav2.isPlaying() == false) {
    trellis.clrLED(1);
    trellis.writeDisplay();
  }
  if (playSdWav3.isPlaying() == false) {
    trellis.clrLED(2);
    trellis.writeDisplay();
  }
  // tell the trellis to set the LEDs we requested
  trellis.writeDisplay();
}



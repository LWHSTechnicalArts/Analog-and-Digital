#include "Adafruit_VL53L0X.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=285,293
AudioOutputI2S           i2s1;           //xy=568,303
AudioConnection          patchCord1(sine1, 0, i2s1, 0);
AudioConnection          patchCord2(sine1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=551,178
// GUItool: end automatically generated code


Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);

  AudioMemory(2);   // required to play audio

  sgtl5000_1.enable();          //enable audio shield
  sgtl5000_1.volume(0.7);   //set overall volume

  sine1.amplitude(0.5);          // set sine amplitude

  delay(200);
  // wait until serial port opens for native USB devices
//  while (! Serial) {
//    delay(1);
//  }

  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
  // power
  Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }
  for (int i =0; i < 50; i+=5) {
    sine1.frequency((measure.RangeMilliMeter * 3) + i); // set sine frequency
    delay(5);
  }
}

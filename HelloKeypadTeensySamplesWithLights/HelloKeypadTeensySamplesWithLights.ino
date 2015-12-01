#include <Keypad.h>

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

//teensy lights hookup
int pins[8]= {15,16,17,18,19,20,21,22};

int lightcols[4] = {15, 16, 17, 18};
int lightrows[4] = {19, 20, 21, 22};

//keypad
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'#', '0', '*', 'D'}
};
byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 6, 5, 4}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  AudioMemory(120);   // required to play audio
  Serial.begin(9600);

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

  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // set up cols and rows
  for (int i = 0; i <= 3; i++) {
    digitalWrite(lightcols[i], LOW);
  }

  for (int i = 0; i <= 3; i++) {
    digitalWrite(lightrows[i], LOW);
  }

    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightrows[0], LOW);
    delay(1000);
    digitalWrite(lightcols[0], LOW);
    digitalWrite(lightrows[0], HIGH);
    delay(1000); 
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {
    Serial.println(key);
  }

  if (key == '1') {
    playSdWav1.play("jawharp.wav");
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightrows[0], LOW);
    delay(200);
    digitalWrite(lightcols[0], LOW);
    digitalWrite(lightrows[0], HIGH);
  }
  if (key == '2') {
    playSdWav2.play("flamenco.wav");
  }
  if (key == '3') {
    playSdWav3.play("powermet.wav");
  }
}

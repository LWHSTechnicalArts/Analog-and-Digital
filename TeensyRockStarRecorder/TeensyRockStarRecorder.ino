// Record sound as raw data to a SD card, and play it back.
//
// Requires the audio shield:
//   http://www.pjrc.com/store/teensy3_audio.html
//
// Three pushbuttons need to be connected:
//   Record Button: pin 0 to GND
//   Stop Button:   pin 1 to GND
//   Play Button:   pin 2 to GND
//
// This example code is in the public domain.

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Bounce.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=157,239
AudioPlaySdRaw           playSdRaw1;     //xy=159,319
AudioEffectDelay         delay1;         //xy=312,320
AudioRecordQueue         queue1;         //xy=459,243
AudioOutputI2S           i2s1;           //xy=462,293
AudioConnection          patchCord1(i2s2, 0, queue1, 0);
AudioConnection          patchCord2(playSdRaw1, delay1);
AudioConnection          patchCord3(delay1, 1, i2s1, 0);
AudioConnection          patchCord4(delay1, 2, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=317,176
// GUItool: end automatically generated code


// Bounce objects to easily and reliably read the buttons
Bounce buttonRecord = Bounce(0, 8);
Bounce buttonStop =   Bounce(1, 8);  // 8 = 8 ms debounce time
Bounce buttonPlay =   Bounce(2, 8);

// which input on the audio shield will be used?
//const int myInput = AUDIO_INPUT_LINEIN;
const int myInput = AUDIO_INPUT_MIC;

// Remember which mode we're doing
int mode = 0;  // 0=stopped, 1=recording, 2=playing

// The file where data is recorded
File voice;

void setup() {
  // Configure the pushbutton pins
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);

  // Audio connections require memory, and the record queue
  // uses this memory to buffer incoming audio.
  AudioMemory(120);

  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(0.5);

  // Initialize the SD card
  SPI.setMOSI(7);
  SPI.setSCK(14);
  if (!(SD.begin(10))) {
    // stop here if no SD card, but print a message
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
}


void loop() {
  // First, read the buttons
  buttonRecord.update();
  buttonStop.update();
  buttonPlay.update();

  // Respond to button presses
  if (buttonRecord.fallingEdge()) {
    Serial.println("Record Button Press");
    if (mode == 2) stopPlaying();
    if (mode == 0) startRecording();
  }
  if (buttonStop.fallingEdge()) {
    Serial.println("Stop Button Press");
    if (mode == 1) stopRecording();
    if (mode == 2) stopPlaying();
  }
  if (buttonPlay.fallingEdge()) {
    Serial.println("Play Button Press");
    if (mode == 1) stopRecording();
    if (mode == 0) startPlaying();
  }

  // If we're playing or recording, carry on...
  if (mode == 1) {
    continueRecording();
  }
  if (mode == 2) {
    continuePlaying();
  }
}


void startRecording() {
  Serial.println("startRecording");
  if (SD.exists("RECORD.RAW")) {
    // The SD library writes new data to the end of the
    // file, so to start a new recording, the old file
    // must be deleted before new data is written.
    SD.remove("RECORD.RAW");
  }
  voice = SD.open("RECORD.RAW", FILE_WRITE);
  if (voice) {
    queue1.begin();
    mode = 1;
  }
}

void continueRecording() {
  if (queue1.available() >= 2) {
    byte buffer[512];
    // Fetch 2 blocks from the audio library and copy
    // into a 512 byte buffer.  The Arduino SD library
    // is most efficient when full 512 byte sector size
    // writes are used.
    memcpy(buffer, queue1.readBuffer(), 256);
    queue1.freeBuffer();
    memcpy(buffer + 256, queue1.readBuffer(), 256);
    queue1.freeBuffer();
    // write all 512 bytes to the SD card
    elapsedMicros usec = 0;
    voice.write(buffer, 512);
    // Uncomment these lines to see how long SD writes
    // are taking.  A pair of audio blocks arrives every
    // 5802 microseconds, so hopefully most of the writes
    // take well under 5802 us.  Some will take more, as
    // the SD library also must write to the FAT tables
    // and the SD card controller manages media erase and
    // wear leveling.  The queue1 object can buffer
    // approximately 301700 us of audio, to allow time
    // for occasional high SD card latency, as long as
    // the average write time is under 5802 us.
    //Serial.print("SD write, us=");
    //Serial.println(usec);
  }
}

void stopRecording() {
  Serial.println("stopRecording");
  queue1.end();
  if (mode == 1) {
    while (queue1.available() > 0) {
      voice.write((byte*)queue1.readBuffer(), 256);
      queue1.freeBuffer();
    }
    voice.close();
  }
  mode = 0;
}

void startPlaying() {
  Serial.println("startPlaying");
  delay1.delay(1, 100);
  delay1.delay(2, 250);
  playSdRaw1.play("RECORD.RAW");
  mode = 2;
}

void continuePlaying() {
  if (!playSdRaw1.isPlaying()) {
    playSdRaw1.stop();
    mode = 0;
  }
}

void stopPlaying() {
  Serial.println("stopPlaying");
  if (mode == 2) playSdRaw1.stop();
  mode = 0;
}



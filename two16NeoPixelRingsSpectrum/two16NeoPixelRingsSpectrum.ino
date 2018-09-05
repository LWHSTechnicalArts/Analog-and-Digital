/* Based on Adafruit_NeoMatrix example for two 16 LED neopixel rings.
  and
  SparkFun Spectrum Shield Demo
  Toni Klopfenstein @ SparkFun Electronics
  February 2015
  https://github.com/sparkfun/Spectrum_Shield
  Modified by A.Kleindolph 9-2018
*/
#include <Adafruit_NeoPixel.h>

//Declare Spectrum Shield pin connections
#define STROBE 4
#define RESET 5
#define DC_One A0

//declare matrix shield data pin
#define lowPIN 12
#define highPIN 11

//declare neopixel matrix configuration
Adafruit_NeoPixel lowRing = Adafruit_NeoPixel(16, lowPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel highRing = Adafruit_NeoPixel(16, highPIN, NEO_GRB + NEO_KHZ800);

//Define spectrum variables
int freq_amp;
int Frequencies_One[7];
int i;

void setup() {
  Serial.begin(57600);

  //matrix setup
  lowRing.begin();
  lowRing.setBrightness(80);

  highRing.begin();
  highRing.setBrightness(80);

  //Set spectrum Shield pin configurations
  pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_One, INPUT);
  digitalWrite(STROBE, HIGH);
  digitalWrite(RESET, HIGH);

  //Initialize Spectrum Analyzers
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, HIGH);
  delay(1);
  digitalWrite(STROBE, HIGH);
  delay(1);
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, LOW);
}


/**************************Main Function Loop*****************************/
void loop() {
  for (int i = 0; i <= lowRing.numPixels(); i++) {
    lowRing.setPixelColor(i, 0, 0, 0);
    highRing.setPixelColor(i, 0, 0, 0);
  }
  lowRing.show();
  highRing.show();
  Read_Frequencies();     //read function
}


/*******************Pull frequencies from Spectrum Shield********************/
void Read_Frequencies() {

  //Read frequencies for each band
  digitalWrite(RESET, LOW);
  delay(1);
  for (freq_amp = 0; freq_amp <= 6; freq_amp++)   //cycle through 7 frequencies
  {
    Frequencies_One[freq_amp] = ((analogRead(DC_One) + analogRead(DC_One)) / 2);   //average two readings
    digitalWrite(STROBE, HIGH);
    digitalWrite(STROBE, LOW);

    Serial.print (Frequencies_One[1]);
    Serial.print ("    ");

    if (Frequencies_One[0] > 70) {                                //read lowest freq and display (filter noise)
      for (int i = 0; i <= Frequencies_One[1] / 25; i++) {
        lowRing.setPixelColor(i, 0, 255, 255);
      }
    }
    if (Frequencies_One[6] > 70) {
      for (int i = 0; i <= Frequencies_One[6] / 25; i++) {       //read highest freq and display (filter noise)
        highRing.setPixelColor(i, 255, 0, 255);
      }
    }
  }
  lowRing.show();
  highRing.show();
  Serial.println();
  digitalWrite(RESET, HIGH);
  delay(1);
}


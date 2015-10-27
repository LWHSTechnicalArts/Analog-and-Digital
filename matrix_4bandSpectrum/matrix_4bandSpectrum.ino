// Based on Adafruit_NeoMatrix example for single NeoPixel Shield. Modified by A.Kleindolph 10-2015

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

//Declare Spectrum Shield pin connections
#define STROBE 4
#define RESET 5
#define DC_One A0

//declare matrix shield data pin
#define PIN 12

//declare neopixel matrix configuration
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
                            NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
                            NEO_GRB            + NEO_KHZ800);

//color array
const uint16_t colors[] = {
  matrix.Color(255, 255, 0), matrix.Color(255, 255, 255), matrix.Color(255, 0, 127), matrix.Color(255, 0, 255)
};


//Define spectrum variables
int freq_amp;
int Frequencies_One[7];
int i;

void setup() {
  delay(500);
  Serial.begin(57600);

  //matrix setup
  matrix.begin();
  matrix.setBrightness(40);

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
  matrix.fillScreen(0);   //clear screen
  Read_Frequencies();     //read function
  matrix.show();          //display pixels
}


/*******************Pull frequencies from Spectrum Shield********************/
void Read_Frequencies() {
  
  //Read frequencies for each band
  digitalWrite(RESET, LOW);
  delay(1);
  for (freq_amp = 0; freq_amp < 7; freq_amp++)
  {
    Frequencies_One[freq_amp] = ((analogRead(DC_One) + analogRead(DC_One)) / 2);   //average two readings
    digitalWrite(STROBE, HIGH);
    digitalWrite(STROBE, LOW);

    Serial.print (Frequencies_One[0]);
    Serial.print ("    ");
    if (Frequencies_One[1] > 80) {
      matrix.drawLine(0, 0, 0, Frequencies_One[1] / 100, colors[0]);
      matrix.drawLine(1, 0, 1, Frequencies_One[1] / 100, colors[0]);
      matrix.drawLine(2, 0, 2, Frequencies_One[2] / 100, colors[1]);
      matrix.drawLine(3, 0, 3, Frequencies_One[2] / 100, colors[1]);
      matrix.drawLine(4, 0, 4, Frequencies_One[3] / 100, colors[2]);
      matrix.drawLine(5, 0, 5, Frequencies_One[3] / 100, colors[2]);
      matrix.drawLine(6, 0, 6, Frequencies_One[4] / 100, colors[3]);
      matrix.drawLine(7, 0, 7, Frequencies_One[4] / 100, colors[3]);
    }
    else
    {
      matrix.fillScreen(0);
    }
  }
Serial.println();
digitalWrite(RESET, HIGH);
delay(1);
}


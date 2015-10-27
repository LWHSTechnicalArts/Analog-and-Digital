/****************************************************************************** 
SparkFun Spectrum Shield Demo
Toni Klopfenstein @ SparkFun Electronics
February 2015
https://github.com/sparkfun/Spectrum_Shield

The Spectrum Shield code is based off of the original demo sketch by Ben Moyes @Bliptronics.  
This sketch is available in the Spectrum Shield repository. 

Development environment specifics:
Developed in Arduino 1.6.

Modified for serial output only on 10-2015 by A.Kleindolph
*********************************************************************************/

//Declare Spectrum Shield pin connections
#define STROBE 4
#define RESET 5
#define DC_One A0
#define DC_Two A1 


//Define spectrum variables
int freq_amp;
int Frequencies_One[7];
int Frequencies_Two[7]; 
int i;

/********************Setup Loop*************************/
void setup() {
  Serial.begin(9600);
  
  //Set spectrum Shield pin configurations
  pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_One, INPUT);
  pinMode(DC_Two, INPUT);  
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
  
  Read_Frequencies();
  Print_Frequencies();
  delay(100);
 
}


/*******************Pull frquencies from Spectrum Shield********************/
void Read_Frequencies(){
  //Read frequencies for each band
  for (freq_amp = 0; freq_amp<7; freq_amp++)
  {
    Frequencies_One[freq_amp] = ((analogRead(DC_One) + analogRead(DC_One)+analogRead(DC_One)) / 3);
    digitalWrite(STROBE, HIGH);
    digitalWrite(STROBE, LOW);
  }
}

void Print_Frequencies(){
   for( i= 0; i<7; i++)
   {
    Serial.print(Frequencies_One[i]);
    Serial.print(" ");
   }
   Serial.println();
}

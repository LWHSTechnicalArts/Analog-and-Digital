//teensy pin hookups
int pins[8]= {15,16,17,18,19,20,21,13};

int lightcols[4] = {15, 16, 17, 18};
int lightrows[4] = {19, 20, 21, 13};

int delayTime = 100;

void setup() {
  // sets the pins as output
  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // set up cols and rows
  for (int i = 0; i <= 3; i++) {
    digitalWrite(lightcols[i], HIGH);
  }

  for (int i = 0; i <= 3; i++) {
    digitalWrite(lightrows[i], HIGH);
  }

}

void loop() {
   //1,4
    digitalWrite(lightrows[0], HIGH);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], LOW);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
    //1,3
    digitalWrite(lightrows[0], HIGH);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], LOW);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
    //1,2
    digitalWrite(lightrows[0], HIGH);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], LOW);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
    //1,1
    digitalWrite(lightrows[0], HIGH);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], LOW);
    delay(delayTime);
    //2,1
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], HIGH);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], LOW);
    delay(delayTime);
     //2,2
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], HIGH);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], LOW);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
    //2,3
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], HIGH);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], LOW);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
     //2,4
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], HIGH);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], LOW);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
    //3,4
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], HIGH);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], LOW);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
    //3,3
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], HIGH);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], LOW);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
     //3,2
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], HIGH);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], LOW);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
      //3,1
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], HIGH);
    digitalWrite(lightrows[3], LOW);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], LOW);
    delay(delayTime);
      //4,1
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], HIGH);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], LOW);
    delay(delayTime);
        //4,2
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], HIGH);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], LOW);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
          //4,3
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], HIGH);
    digitalWrite(lightcols[0], HIGH);
    digitalWrite(lightcols[1], LOW);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
             //4,4
    digitalWrite(lightrows[0], LOW);
    digitalWrite(lightrows[1], LOW);
    digitalWrite(lightrows[2], LOW);
    digitalWrite(lightrows[3], HIGH);
    digitalWrite(lightcols[0], LOW);
    digitalWrite(lightcols[1], HIGH);
    digitalWrite(lightcols[2], HIGH);
    digitalWrite(lightcols[3], HIGH);
    delay(delayTime);
    
    
}



byte col = 0;
byte leds[4][4];

//teensy pin hookups
int pins[8]= {15,16,17,18,19,20,21,22};

int cols[4] = {15, 16, 17, 18};
int rows[4] = {19, 20, 21, 22};

void setup() {
  // sets the pins as output
  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // set up cols and rows
  for (int i = 0; i <= 3; i++) {
    digitalWrite(cols[i], LOW);
  }

  for (int i = 0; i <= 3; i++) {
    digitalWrite(rows[i], LOW);
  }

}

void loop() {

    digitalWrite(cols[0], HIGH);
    digitalWrite(rows[0], LOW);
    delay(100);
    digitalWrite(cols[0], LOW);
    digitalWrite(rows[0], HIGH);
    delay(100); 
}



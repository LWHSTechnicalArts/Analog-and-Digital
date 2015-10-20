
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  Serial.print("I've been running for "); Serial.print(millis()); Serial.println(" mS");
}




String message = "I have been running for ";
String unit = " mS";

void setup() {
  Serial.begin(9600);    // initialize serial communication at 9600 bits per second:
}

void loop() {
  Serial.println(message + millis() + unit);  //serial print the time in milliSed the arduino has been running
}




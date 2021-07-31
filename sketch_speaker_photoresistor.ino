/*
* Speaker sketch with photoresistor
*/
const int outputPin = 9; // Speaker connected to digital pin 9
const int sensorPin = A0; // connect sensor to analog input 0
const int low = 200;
const int high = 800;
const int minDuration = 1; // 1 ms on, 1 ms off (500 Hz)
const int maxDuration = 10; // 10 ms on, 10 ms off (50 Hz)

void setup()
{
  pinMode(outputPin, OUTPUT); // enable output on the led pin
}

void loop()
{
  int sensorReading = analogRead(sensorPin); // read the analog input
  int delayval = map(sensorReading, low, high, minDuration, maxDuration);
  delayval = constrain(delayval, minDuration, maxDuration);
  digitalWrite(outputPin, HIGH); // set the pin on
  delay(delayval); // delay is dependent on light level
  digitalWrite(outputPin, LOW); // set the pin off
  delay(delayval);
}

// To load the computer use the USB-cable of Arduino.
// To let things work use the Adapter.

int solenoidPin = 7;

void setup()
{
  pinMode(solenoidPin, OUTPUT);
}

void loop()
{
  digitalWrite(solenoidPin, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  digitalWrite(solenoidPin, LOW);
  delay(2000); // Wait for 1000 millisecond(s)
}

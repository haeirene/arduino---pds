#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/* Pins explained:
 * GND = ground
 * VCC = 5V
 * SDA = data pin = A4
 * SCL = clock = A5
*/

// communication 0x27, 16 characters on 2 lines
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  // Turn on the blacklight and print a message.
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Neerslag in de ");
  lcd.setCursor(0, 1);
  lcd.print("herfst van 2021");

  delay(1000);
}

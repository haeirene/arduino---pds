#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Potentiometer
const int potentioYearPin = A0;

// Buttons - general
const int debounceDelay = 50; // ms
unsigned long lastDebounceTime = 0; //timestamp

// Buttons - pins
const int btnPinWinter = 13;
const int btnPinSpring = 10;
const int btnPinSummer = 9;
const int btnPinAutumn = 7;

// Buttons - previous states
int btnWinterPrevState = HIGH;
int btnSpringPrevState = HIGH;
int btnSummerPrevState = HIGH;
int btnAutumnPrevState = HIGH;

// Data
int year = 0;

String currentSeason = "winter";

/* Pins explained:
 * GND = ground
 * VCC = 5V
 * SDA = data pin = A4
 * SCL = clock = A5
*/

// communication 0x27, 16 characters on 2 lines
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  pinMode(potentioYearPin, INPUT);
  
  pinMode(btnWinterPrevState, INPUT_PULLUP);
  pinMode(btnSpringPrevState, INPUT_PULLUP);
  pinMode(btnSummerPrevState, INPUT_PULLUP);
  pinMode(btnAutumnPrevState, INPUT_PULLUP);
  
  lcd.begin();
  // Turn on the blacklight and print a message.
}

void loop() {
  // Seasons
  debounceButtons();
}

void debounceButtons(){
  // Buttons - current state
  int btnWinterCurrentState;
  int btnSpringCurrentState;
  int btnSummerCurrentState;
  int btnAutumnCurrentState;
  
  btnWinterCurrentState = digitalRead(btnPinWinter);
  btnSpringCurrentState = digitalRead(btnPinSpring);
  btnSummerCurrentState = digitalRead(btnPinSummer);
  btnAutumnCurrentState = digitalRead(btnPinAutumn);

  if ((btnWinterPrevState == HIGH) && (btnWinterCurrentState == LOW)){
    currentSeason = "winter";
  }
  else if ((btnSpringPrevState == HIGH) && (btnSpringCurrentState == LOW)){
    currentSeason = "lente";
  }
  else if ((btnSummerPrevState == HIGH) && (btnSummerCurrentState == LOW)){
    currentSeason = "zomer";
  }
  else if ((btnAutumnPrevState == HIGH) && (btnAutumnCurrentState == LOW)){
    currentSeason = "herfst";
  }
  
  //Serial.println(currentSeason);
  
  // Remember the previous state for next loop()
  btnWinterPrevState = btnWinterCurrentState;
  btnSpringPrevState = btnSpringCurrentState;
  btnSummerPrevState = btnSummerCurrentState;
  btnAutumnPrevState = btnAutumnCurrentState;
  
  delay(500);
  showData();
}

void showData(){
  //map(value, fromLow, fromHigh, toLow, toHigh)
  year = map(analogRead(potentioYearPin), 0, 1023, 1833, 2020);
  delay(1000);
  
  lcd.setCursor(0, 0);
  lcd.print("Neerslag in de ");
  
  lcd.setCursor(0, 1);
  Serial.println(currentSeason);
  lcd.print(currentSeason);

  lcd.setCursor(8, 1);
  lcd.print(" - ");

  lcd.setCursor(11, 1);
  Serial.println(year);
  lcd.print(year);
}

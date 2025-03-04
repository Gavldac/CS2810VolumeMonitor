#include <LiquidCrystal.h>

const int vo = 3; // VO is the contrast of the LCD screen and can be controlled with PWM
const int rs = A4;
const int e = A5;
const int d4 = 2;
const int d5 = 4;
const int d6 = 7;
const int d7 = 8;

// int contrast = 0;

// LCD initialization
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600); // Just tomake sure things are explicitly set

  pinMode(vo, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialize the LCD with a size of 16x2 (columns x rows)
  lcd.begin(16, 2); // The 16 and 2 refer to 16 columns and 2 rows
  lcd.setCursor(0, 0);        // Set cursor to top-left corner

  analogWrite(vo, 120);

  lcd.print("Hello, World!"); // Print the message
}
void loop()
{
  // contrast += 20;
  // if (contrast > 255) contrast = 0;
  // analogWrite(vo, contrast);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}

/*
#include <LiquidCrystal.h>

// Define the LCD screen pins
const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;

// Create an instance of the LiquidCrystal library
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define the time variables
int hours = 0;
int minutes = 2;
int seconds = 0;

void setup() {
  // Initialize the LCD screen
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Simple Clock");
}

void loop() {
  // Update the time variables
  seconds++;
  if (seconds >= 60) {
    seconds = 0;
    minutes++;
  }
  if (minutes >= 60) {
    minutes = 0;
    hours++;
  }
  if (hours >= 24) {
    hours = 0;
  }

  // Display the time on the LCD screen
  lcd.setCursor(0, 1); // Move to the second line
  lcd.print("Time: ");
  if (hours < 10) lcd.print("0"); // Add leading zero
  lcd.print(hours);
  lcd.print(":");
  if (minutes < 10) lcd.print("0"); // Add leading zero
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0"); // Add leading zero
  lcd.print(seconds);

  // Wait for 1 second before updating the time again
  delay(1000);
}
*/
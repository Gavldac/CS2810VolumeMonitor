#include <LiquidCrystal.h>

const int vo = 3; // VO is the contrast of the LCD screen and can be controlled with PWM output
const int rs = 13;
const int e = 12;
const int d4 = 2;
const int d5 = 4;
const int d6 = 7;
const int d7 = 8;

// Microphone will need to be grounded and use one of the Analog inputs. - suggested to use A0

const int mic = A0;

// Pins 9, 10, and 11 can be used for the LED signaling: 0-255 for birightness

// int contrast = 0;

// LCD initialization
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600); // Just tomake sure things are explicitly set

  pinMode(vo, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialize the LCD with a size of 16x2 (columns x rows)
  lcd.begin(16, 2); //  16 columns and 2 rows on the display

  analogWrite(vo, 120); // sets the LCD contrast (0-255)
}
void loop()
{
  // This just blinks the onboard Uno LED to show it's running the code
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  lcd.setCursor(0, 0); // Set LCD cursor to top-left corner to write
  lcd.print("Put detected"); 
  lcd.setCursor(0,1); // Move the cursor to the next row down
  lcd.print("volume here");
}

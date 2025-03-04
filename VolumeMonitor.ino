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
  lcd.begin(16, 2); //  16 columns and 2 rows on the display
  lcd.setCursor(0, 0); // Set LCD cursor to top-left corner to write

  analogWrite(vo, 120); // sets the LCD contrast (0-255)

  lcd.print("Hello, World!"); 
}
void loop()
{
  // contrast += 20;
  // if (contrast > 255) contrast = 0;
  // analogWrite(vo, contrast);// testing for adjusting LCD contrast 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}

#include <LiquidCrystal.h>

// LCD pin assignments (confirmed from your setup)
const int vo = 3;
const int rs = 13;
const int e = 12;
const int d4 = 2;
const int d5 = 4;
const int d6 = 7;
const int d7 = 8;

// Microphone on analog pin A0
const int mic = A0;

// LED pins based on your reserved setup
const int greenLED = 9;
const int yellowLED = 10;
const int redLED = 11;

// LCD initialization
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

int timer = 0;

void setup() {
  Serial.begin(9600);

  pinMode(vo, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // Set LED pins to output
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // LCD setup
  lcd.begin(16, 2);
  analogWrite(vo, 120);  // Adjust contrast
  lcd.setCursor(0, 0);
  lcd.print("Noise Detector");
  delay(2000);
  lcd.clear();
}

void loop() {
  timer = timer % 10;
  int noise = analogRead(mic);  // Read the mic input (0-1023)
  Serial.println(noise);        // Output for debugging

  // Display the value on the LCD
  // Updates 2x a second
  if (timer%5 == 0){
  lcd.setCursor(0, 0);
  lcd.print("Noise Level:     ");
  lcd.setCursor(0, 1);
  lcd.print("Value: ");
  lcd.print(noise);
  }

  // Control LEDs based on noise level
  if (noise < 200) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  } else if (noise < 400) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  } else {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);
  }

  // Blink built-in LED to show code is running
  // digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  timer++;
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(200);
}

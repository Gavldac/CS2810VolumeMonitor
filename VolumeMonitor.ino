#include <LiquidCrystal.h>

// LCD pin assignments (confirmed from your setup)

const int vo = 3; // VO is the contrast of the LCD screen and can be controlled with PWM output
const int rs = 13;
const int e = 12;
const int d4 = 2;
const int d5 = 4;
const int d6 = 7;
const int d7 = 8;

// Microphone on analog pin A0
const int mic = A0;
unsigned int noise;

// LED pins based on your reserved setup
const int greenLED = 9;
const int yellowLED = 10;
const int redLED = 11;
// LCD initialization
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600);

  pinMode(vo, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // Set LED pins to output
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // LCD setup
  lcd.begin(16, 2);
  analogWrite(vo, 100); // Adjust contrast
  lcd.setCursor(0, 0);
  lcd.print("Noise Detector");
  delay(2000);
  // lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Noise Level:   ");
}

void loop()
{
  unsigned long startTimer = millis();
  unsigned int peakValue = 0;
  unsigned int inMax = 0;    // Starts at 0 and is increased
  unsigned int inMin = 600; // Starts at max and is reduced

  // loop to just listen for 100ms and find the peak value
  while (millis() - startTimer < 100)
  {
    // Read the mic input (0-1023)
    noise = analogRead(mic); // Read the mic input (0-1023)
    if (noise < 1024)        // this throws out extreme peaks that often just bad reads
    {
      inMax = max(inMax, noise);
      inMin = min(inMin, noise);
    }
  }
  // Another option to determine a min value would be to use the startup loop to listen
  // for one second and use that to find the difference of the peak detected.
  // Would likely require input verification "inMin = max(0,inMin);" to avoid less than 0 issues.
  peakValue = inMax - inMin; // Calculate the differnce between the max and min values

  Serial.println(peakValue); // Serial output for debugging

  // Display the value on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Noise Level:    ");
  lcd.setCursor(0, 1);
  lcd.print("Value:          ");
  lcd.setCursor(8,1);
  lcd.print(peakValue);

  // Control LEDs based on noise level
  if (peakValue < 150)
  {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }
  else if (peakValue >= 350)
  {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);
    delay(500); // Delay for 1/2 second to make sure output is seen
  }
  else 
  { // Default middle case does not need a if() since we have already checked for
    // being below or above a threshold already.
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  delay(100); // Delay for 0.1 seconds to finish writing to LCD and LED output

 
}

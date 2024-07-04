#include <LiquidCrystal.h>  // Include LiquidCrystal library for LCD
#include <Keypad.h>         // Include Keypad library for keypad

const byte ROWS = 4;  // Number of rows in the keypad
const byte COLS = 4;  // Number of columns in the keypad
char keys[ROWS][COLS] = {
  { '7', '8', '9', 'A' },
  { '4', '5', '6', 'B' },
  { '1', '2', '3', 'C' },
  { '*', '0', '#', 'D' }
};  // Keypad layout definition

byte rowPins[ROWS] = { 2, 3, 4, 5 };   // Pins connected to keypad rows
byte colPins[COLS] = { 7, 8, 9, 10 };  // Pins connected to keypad columns
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#define redLED 13    // Pin connected to the red LED
#define greenLED 12  // Pin connected to the green LED
#define blueLED 11   // Pin connected to the blue LED

const int rs = 12, en = 11, d4 = 6, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // LCD pin connections (adjust as needed)

int temperature = 28;  // Initial temperature value (replace with sensor reading)
char pressedKey;       // Stores the pressed key

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  lcd.begin(16, 2);     // Initialize LCD with 16 columns and 2 rows
  lcd.clear();          // Clear LCD display
  lcd.print("Temp: ");  // Display "Temp:" message on LCD
  lcd.setCursor(5, 0);  // Set cursor position for temperature value
}

void loop() {
  pressedKey = keypad.getKey();  // Check for pressed key

  // Declare tempString inside the loop function
  String tempString = "";

  if (pressedKey) {
    // Check if a number key is pressed
    if (isdigit(pressedKey)) {
      // Add the pressed number to tempString
      tempString += pressedKey;
      // Update LCD to display the current input (optional)
      lcd.setCursor(5, 0);
      lcd.print("     ");  // Clear previous input (more spaces for longer numbers)
      lcd.print(tempString);
    } else if (pressedKey == 'C') {
      // Handle 'C' for clearing the input
      tempString = "";
      lcd.setCursor(5, 0);
      lcd.print("     ");
    } else if (pressedKey == '#') {
      // Handle '#' to confirm and convert the string to an integer
      temperature = atoi(tempString.c_str());
      tempString = "";  // Clear the temporary string
      lcd.setCursor(5, 0);
      lcd.print("  ");  // Clear previous input (less space for final value)
      lcd.print(temperature);
    }
  }

  // Determine LED state based on temperature
  if (temperature >= 25 && temperature <= 30) {
    // Normal temperature (green LED)
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
    lcd.print("  Normal");  // Display "Normal" on LCD (second line)
  } else if (temperature < 25) {
    // Cold temperature (red LED)
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
    lcd.print("     Cold");  // Display "Cold" on LCD (second line)
  } else {
    // Hot temperature (blue LED)
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
    lcd.print("     Hot");  // Display "Hot" on LCD (second line)
  }

  lcd.setCursor(0, 1);  // Set cursor for status message (optional)
  // lcd.print("Status message");  // Uncomment for additional messages

  delay(1000);  // Delay between checks (adjust as needed)
}

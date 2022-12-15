#include <LiquidCrystal.h> // LCD Display
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);  // Initialize an LCD object with parameters: (RS, E, D4, D5, D6, D7)

byte _2[8] = { // Array of bytes, B stands for binary formatter and the five numbers are the pixels
  B00000,
  B00000,
  B00000,
  B01100,
  B10010,
  B00100,
  B01000,
  B11110
};

byte _3[8] = {
  B00000,
  B00000,
  B00000,
  B11110,
  B00100,
  B11110,
  B00010,
  B11100
};

void setup() {
  Serial.begin(9600); // For data testing

  lcd.createChar(0, _2); // Create a custom character
  lcd.createChar(1, _3);
  lcd.begin(16, 2);  // Initializes the LCD screen, specifying the dimensions (width, height) of the display
  lcd.print("CO");
  lcd.write(byte(0));
}

void loop() {
  int MQ3_value = analogRead(A1);
  int MQ7_value = analogRead(A2);
  int MQ135_value = analogRead(A3);
  // Serial.println("CO2 Level (PPM): ");
  Serial.println("MQ3: " + String(MQ3_value));
  Serial.println("MQ7: " + String(MQ7_value));
  Serial.println("MQ135: " + String(MQ135_value));
  delay(2000);

  lcd.setCursor(0, 0);
  lcd.write("CO");
  lcd.write(byte(0));  // Display the custom character 0
  lcd.scrollDisplayLeft();
  delay(500);

}
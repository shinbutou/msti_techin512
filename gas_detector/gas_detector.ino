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

  // byte _3[8] = {
  //   B00000,
  //   B00000,
  //   B00000,
  //   B11110,
  //   B00100,
  //   B11110,
  //   B00010,
  //   B11100
  // };

const int buzzer = 3;

void setup() {
  // Serial.begin(9600); // For data testing

  lcd.createChar(0, _2); // Create a custom character
  lcd.createChar(1, _3);
  lcd.begin(16, 2);  // Initializes the LCD screen, specifying the dimensions (width, height) of the display
}

void loop() {
  int MQ3_value = analogRead(A1);
  int MQ7_value = analogRead(A2);
  int MQ135_value = analogRead(A3);

  if (MQ135_value > 150 || MQ7_value > 300 || MQ3_value > 500) {
    beep(1000);
  }

  // Serial output
  // Serial.println("MQ3: " + String(MQ3_value));
  // Serial.println("MQ7: " + String(MQ7_value));
  // Serial.println("MQ135: " + String(MQ135_value));

  // LCD Output
  lcd.setCursor(0, 0);
  lcd.write("CO");
  lcd.write(byte(0));  // Display the custom character 0
  lcd.print(":");
  lcd.setCursor(4, 0);
  lcd.print(MQ135_value);

  lcd.setCursor(0, 1);
  lcd.write("CO");
  lcd.print(" :");
  lcd.setCursor(4, 1);
  lcd.print(MQ7_value);

  lcd.setCursor(8, 0);
  lcd.write("HOP:");
  lcd.setCursor(12, 0);
  lcd.print(MQ3_value);

  lcd.setCursor(8, 1);
  lcd.write("(ppm)");

  delay(1000);
  lcd.clear();
}

void beep(int time) {
  analogWrite(buzzer, 220);
  delay(time);
  analogWrite(buzzer, 0);
}
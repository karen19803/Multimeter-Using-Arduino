#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD library with the I2C address
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

// Define the pins for different measurements
const int voltagePin = A3;   // Analog pin for voltage measurement
const int currentPin = A0;   // Analog pin for current measurement
const int resistorPin = A2;  // Analog pin for resistance measurement

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight(); // Turn on the backlight

  // Print a message to the LCD
  lcd.print("Ohm  Volt  Curr");
}

void loop() {
  // Measure voltage
  float voltage_value3 = analogRead(voltagePin);
  float temp_V = voltage_value3 * (5.0 / 1023.0);
  float Vin = 11 * temp_V;

  // Measure current
  float voltage_value0 = analogRead(currentPin);
  float voltage_value1 = analogRead(A1);
  float current_value = abs((voltage_value0 - voltage_value1) * (5.0 / 1023.0));

  // Measure resistance
  float voltage_value2 = analogRead(resistorPin);
  float Rx = (1100.0 / (voltage_value2 * (5.0 / 1023.0))) - 220.0;

  // Display measurements on LCD
  lcd.setCursor(0, 1);
  lcd.print("V:");
  lcd.print(Vin, 2); // Print with 2 decimal places
  lcd.print("V    ");

  lcd.setCursor(6, 1);
  lcd.print("I:");
  lcd.print(current_value, 2); // Print with 2 decimal places
  lcd.print("mA    ");

  lcd.setCursor(12, 1);
  lcd.print("R:");
  lcd.print(Rx, 2); // Print with 2 decimal places
  lcd.print(" Ohm   ");

  delay(1000); // Delay for one second before taking another measurement
}


// Auto Centre Character for Arduino LCD Displays.
// An example of using LiquidCrystal_I2C library to demonstrate the feature.
// Please Note: This automation only help to center x axis, user still have to manually input y axis.
// Please Note: This feature does not prevent overflow of characters in the given screen width.

// Written by ac3ali3n
// Last Update: 30.01.2025

// Have FUN!!!!

#include <LiquidCrystal_I2C.h>

#define LCD_ADDS 0x27
#define SCREEN_WIDTH 16
#define SCREEN_HEIGHT 2

LiquidCrystal_I2C lcd(LCD_ADDS, SCREEN_WIDTH, SCREEN_HEIGHT);  // You can use any of your own display, please refer to your own display's initialization.

void setup() {
  lcd.init();
  lcd.backlight();
  drawCentrelcd("demo", 0);  // Simply call the function with your text and y axis
  drawCentrelcd("DEMO", 1);
  delay(2000);
  lcd.clear();
}

void loop() {
  testA();
}

// Calculation function (val <=length of taxt value, sw <=screen width)
int16_t centrecountlcd(int16_t val, int16_t sw) {
  int16_t v = (sw - val) / 2;
  return v;
}

// This function included the typical LiquidCrystal_I2C setCursor and print functions. This helps to minimise the recalls line for each setCursor and print.
void drawCentrelcd(const char* val, int16_t y) {
  int16_t x = centrecountlcd(strlen(val), 16);
  lcd.setCursor(x, y);
  lcd.print(String(val));
}

void testA() {
  // Testing Demo
  for (int t = 0; t < 11; t++) {
    delay(1000);
    lcd.clear();
    const char* n;
    const char* e;
    switch (t) {
      case 0:
        n = "";
        e = "";
        break;
      case 1:
        n = "a";
        e = "A";
        break;
      case 2:
        n = "ab";
        e = "AB";
        break;
      case 3:
        n = "abc";
        e = "ABC";
        break;
      case 4:
        n = "abcd";
        e = "ABCD";
        break;
      case 5:
        n = "abcde";
        e = "ABCDE";
        break;
      case 6:
        n = "abcdef";
        e = "ABCDEF";
        break;
      case 7:
        n = "abcdefg";
        e = "ABCDEFG";
        break;
      case 8:
        n = "abcdefgh";
        e = "ABCDEFGH";
        break;
      case 9:
        n = "abcdefghi";
        e = "ABCDEFGHI";
        break;
      case 10:
        n = "abcdefghij";
        e = "ABCDEFGHIJ";
        break;
    }
    drawCentrelcd(n, 0);
    drawCentrelcd(e, 1);
  }
}

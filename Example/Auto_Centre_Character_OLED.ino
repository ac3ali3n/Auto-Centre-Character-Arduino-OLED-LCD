
// Auto Centre Character for Arduino OLED Displays.
// An example of using Adafruit libraries to demonstrate the feature.
// Please Note: This automation only help to center x axis, user still have to manually input y axis.
// Please Note: This feature does not prevent overflow of characters in the given screen width.

// Written by ac3ali3n
// Last Update: 30.01.2025

// Have FUN!!!!

#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define OLED_ADDS 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // You can use any of your own display, please refer to your own display's initialization.

void setup() {
  display.begin(OLED_ADDS, true);
  display.setTextColor(1);
  display.setTextWrap(false);
  display.clearDisplay();
  drawCentre5pt("Demo", 2);  // Simply call the function with your text and y axis
  drawCentre10pt("Demo", 15); // different font size
  drawCentre15pt("Demo", 35); // for demonstrations
  display.display();
  delay(2000);
  display.clearDisplay();
  testA();
}

void loop() {
  testB();
}

// Any used of custom font should be referred to its pixel length (pt) + gap (r).
// An example word "AM" size 5x7 shown below. There are two gaps in column 6 and column 12.
// For symmetry concerned, column 12 should be removed as there is no gap at the left of the first character.
//--------------0 123456789/10/11/12
//--------------1 ||.|||.|||.|
//--------------2 |.|.||..|..|
//--------------3 .|||.|.|.|.|
//--------------4 .|||.|.|.|.|
//--------------5 .....|.|.|.|
//--------------6 .|||.|.|||.|
//--------------7 .|||.|.|||.|

// Calculation function (val <=length of taxt value, sw <=screen width, pt <=text pixel, r <=the gap in between two characters)
int16_t centrecount(int16_t val, int16_t sw, int16_t pt, int16_t r) {
  int16_t v = (sw - ((val * (pt + r)) - r)) / 2;
  return v;  //-------------------------^ this r removes the gap from the last character
}

// The following list of sizes are for the default font used in Adafruit library.
// Each of the list has included the typical Adafruit setTextSize, setCursor and print functions. This helps to minimise the recalls line for each setCursor and print.
// Text size 1 5x7 (with 1px gap)
void drawCentre5pt(const char* val, int16_t y) {
  int16_t x = centrecount(strlen(val), SCREEN_WIDTH, 5, 1);
  display.setTextSize(1);
  display.setCursor(x, y);
  display.print(String(val));
}

// Text size 2 10x14 (with 2px gap)
void drawCentre10pt(const char* val, int16_t y) {
  int16_t x = centrecount(strlen(val), SCREEN_WIDTH, 10, 2);
  display.setTextSize(2);
  display.setCursor(x, y);
  display.print(String(val));
}

// Text size 3 15x21 (with 3px gap)
void drawCentre15pt(const char* val, int16_t y) {
  int16_t x = centrecount(strlen(val), SCREEN_WIDTH, 15, 3);
  display.setTextSize(3);
  display.setCursor(x, y);
  display.print(String(val));
}

void testA() {
  // Testing Demo
  for (int t = 0; t < 14; t++) {
    delay(200);
    display.clearDisplay();
    const char* h;
    const char* i;
    const char* j;
    switch (t) {
      case 0:
        h = "";
        i = "";
        j = "";
        break;
      case 1:
        h = "a";
        i = "A";
        j = "1";
        break;
      case 2:
        h = "ab";
        i = "AB";
        j = "12";
        break;
      case 3:
        h = "abc";
        i = "ABC";
        j = "123";
        break;
      case 4:
        h = "abcd";
        i = "ABCD";
        j = "1234";
        break;
      case 5:
        h = "abcde";
        i = "ABCDE";
        j = "12345";
        break;
      case 6:
        h = "abcdef";
        i = "ABCDEF";
        j = "123456";
        break;
      case 7:
        h = "abcdefg";
        i = "ABCDEFG";
        j = "1234567";
        break;
      case 8:
        h = "abcdefgh";
        i = "ABCDEFGH";
        j = "12345678";
        break;
      case 9:
        h = "abcdefghi";
        i = "ABCDEFGHI";
        j = "123456789";
        break;
      case 10:
        h = "abcdefghij";
        i = "ABCDEFGHIJ";
        j = "1234567890";
        break;
      case 11:
        h = "abcdefghijk";
        i = "ABCDEFGHIJK";
        j = "12345678901";
        break;
      case 12:
        h = "abcdefghijkl";
        i = "ABCDEFGHIJKL";
        j = "123456789012";
        break;
      case 13:
        h = "abcdefghijklm";
        i = "ABCDEFGHIJKLM";
        j = "1234567890123";
        break;
    }
    drawCentre5pt(h, 2);
    drawCentre10pt(i, 15);
    drawCentre15pt(j, 35);
    display.display();
  }
}

void testB() {
  // Typical Application DEMO
  for (int t = 0; t < 18; t++) {
    delay(1000);
    display.clearDisplay();
    const char* o;
    const char* p;
    const char* e;
    const char* g;
    switch (t) {
      case 1:
        o = "Connecting WiFi SSID:";
        p = "My_Home_WiFi";
        e = " ";
        g = "Typical Application";
        break;
      case 2:
        o = "Connecting WiFi SSID:";
        p = "My_Home_WiFi";
        e = ".";
        g = "Typical Application";
        break;
      case 3:
        o = "Connecting WiFi SSID:";
        p = "My_Home_WiFi";
        e = "..";
        g = "Typical Application";
        break;
      case 4:
        o = "Connecting WiFi SSID:";
        p = "My_Home_WiFi";
        e = "...";
        g = "Typical Application";
        break;
      case 5:
        o = "Connecting WiFi SSID:";
        p = "My_Home_WiFi";
        e = "....";
        g = "Typical Application";
        break;
      case 6:
        o = "Connecting WiFi SSID:";
        p = "My_Home_WiFi";
        e = "....";
        g = "Typical Application";
        break;
      case 7:
        o = "Connecting WiFi SSID:";
        p = "My_Home_WiFi";
        e = "......";
        g = "Typical Application";
        break;
      case 8:
        o = "Connecting WiFi SSID:";
        p = "My_Home_WiFi";
        e = ".......";
        g = "Typical Application";
        break;
      case 9:
        o = "Connecting WiFi SSID:";
        p = "My_Home_WiFi";
        e = "........";
        g = "Typical Application";
        break;
      case 10:
        o = "Connecting WiFi SSID:";
        p = "My_Home_WiFi";
        e = "Connected";
        g = "Typical Application";
        break;
      case 11:
        o = "Connecting WiFi SSID:";
        p = "NETA35RTB";
        e = " ";
        g = "Typical Application";
        break;
      case 12:
        o = "Connecting WiFi SSID:";
        p = "NETA35RTB";
        e = ".";
        g = "Typical Application";
        break;
      case 13:
        o = "Connecting WiFi SSID:";
        p = "NETA35RTB";
        e = "..";
        g = "Typical Application";
        break;
      case 14:
        o = "Connecting WiFi SSID:";
        p = "NETA35RTB";
        e = "...";
        g = "Typical Application";
        break;
      case 15:
        o = "Connecting WiFi SSID:";
        p = "NETA35RTB";
        e = "....";
        g = "Typical Application";
        break;
      case 16:
        o = "Connecting WiFi SSID:";
        p = "NETA35RTB";
        e = ".....";
        g = "Typical Application";
        break;
      case 17:
        o = "Connecting WiFi SSID:";
        p = "NETA35RTB";
        e = "Connected";
        g = "Typical Application";
        break;
    }
    drawCentre5pt(o, 2);
    drawCentre5pt(p, 15);
    drawCentre5pt(e, 28);
    drawCentre5pt(g, 50);
    display.display();
  }
}

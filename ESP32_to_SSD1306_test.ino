// Wemos D1 mini ESP32 SSD1306 display test
// 2024.02.06
// Jay Teramoto

#include <Wire.h>
#include <Adafruit_GFX.h> //https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SSD1306.h> //https://github.com/adafruit/Adafruit_SSD1306

// OLED1306
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

double    lat=35.123456789;
double    lng=194.0123456789;

uint16_t   year=2024;
uint8_t    month=2;
uint8_t    day=6;
uint8_t    hour=9;
uint8_t    minute=34;
uint8_t    second=59;

uint8_t    rssi=255;
uint16_t   count=123;

void setup()
{
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  oled.clearDisplay();
}

void loop()
{
  char sz[32];

  oled.clearDisplay();
  oled.setTextSize(2);             
  oled.setTextColor(WHITE);

  oled.setCursor(0,0);      
  sprintf(sz, "%10.6f", lat);  
  oled.print(sz);

  oled.setCursor(0,18);
  sprintf(sz, "%10.6f", lng);  
  oled.print(sz);

  oled.setTextSize(1);             
  oled.setCursor(0,40);
  sprintf(sz, "%04d/%02d/%02d %02d:%02d:%02d", year, month, day, hour, minute, second);
  oled.print(sz);

  oled.setCursor(0,54);
  sprintf(sz, "RSSI:%3d COUNT:%6d", rssi, count);
  oled.print(sz);

//  oled.print(F("ABCDEFGHIJABCDEFGHIJ"));
  oled.display();
  delay(10);
}

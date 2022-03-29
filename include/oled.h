#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C

struct Oled : public Adafruit_SSD1306 {
  Oled() : Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {}

  void setup();
  void base();
  void clear();

  void update(byte channels[]);

  void on_pressed();
  void on_released();
};

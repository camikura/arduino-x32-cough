#include <oled.h>

void Oled::setup() { begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); }

void Oled::base() {
  setRotation(2);
  setTextSize(2);
  setTextColor(SSD1306_BLACK, SSD1306_WHITE);  // Draw 'inverse' text
  setCursor(0, 0);
  print("485test");
  setCursor(80, 16);
  print("v1.0");
  setTextColor(SSD1306_WHITE);
  setCursor(0, 48);
  print("Server");
}

void Oled::clear() {
  clearDisplay();
  base();
  display();
}

void Oled::update(byte channels[]) {
  clearDisplay();
  setTextColor(SSD1306_WHITE);
  setTextSize(2);  // Draw 2X-scale text
  for (uint8_t i = 0; i < 4; i++) {
    if (channels[i] != 0) {
      setCursor(0, i * 16);
      print("pressed #");
      print(channels[i]);
    }
  }
  display();
}

void Oled::on_pressed() {
  clearDisplay();
  base();

  setCursor(44, 48);
  setTextColor(SSD1306_WHITE);
  setTextSize(2);  // Draw 2X-scale text
  print("pressed");
  display();
}

void Oled::on_released() {
  clearDisplay();
  base();

  setCursor(32, 48);
  setTextColor(SSD1306_WHITE);
  setTextSize(2);  // Draw 2X-scale text
  print("released");
  display();
}

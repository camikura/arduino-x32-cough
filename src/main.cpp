#include <FlexiTimer2.h>
#include <header.h>

volatile bool led = 0x00;
#define PIN_LED1 4
#define PIN_485 7

volatile byte data = 0x00;
byte channels[] = {0x00, 0x00, 0x00, 0x00};

void setup() {
  Serial.begin(9600);
  Serial1.begin(31250);      // 485
  pinMode(PIN_485, OUTPUT);  // 485 Enable

  oled = Oled();
  oled.setup();
  oled.clear();

  pinMode(PIN_LED1, OUTPUT);

  digitalWrite(PIN_485, 1);

  FlexiTimer2::set(50, broadcast);
  FlexiTimer2::start();
}

void loop() {}

void broadcast() {
  digitalWrite(PIN_485, 1);
  Serial1.write(0xf0);
  Serial1.flush();
  digitalWrite(PIN_485, 0);
}

void serialEvent1() {
  while (Serial1.available()) {
    byte data = (byte)Serial1.read();
    if (data > 0x80) {
      int ch = data - 0x80;
      Serial.print("pressed #");
      Serial.print(ch, DEC);
      Serial.print(" ");
      Serial.println(millis());

      for (uint8_t i = 0; i < 3; i++) {
        channels[i] = channels[i + 1];
      }
      channels[3] = ch;

      oled.update(channels);
    }
  }
}

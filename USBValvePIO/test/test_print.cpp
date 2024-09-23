#include "Arduino.h"
#include <SPI.h>
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define I2C_ADDRESS 0x3C  // 0X3C+SA0 - 0x3C or 0x3D
#define RST_PIN -1        // Define proper RST_PIN if required.
#define OLED_WIDTH  128
#define OLED_HEIGHT 64    // 64 or 32 depending on the OLED

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, RST_PIN);



void setup() {
    Serial.begin(9600);

    display.begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Hello, World!");
    display.setCursor(0, 10);
    display.println("Hello, World!");
    display.setCursor(0, 20);
    display.println("Hello, World!");
    display.setCursor(0, 30);
    display.println("Hello, World!");
    display.setCursor(0, 40);
    display.println("Hello, World!");
    display.setCursor(0, 50);
    display.println("Hello, World!");
    display.display();
}

void loop() {
    Serial.println("Hello, World!");
    delay(1000);
}
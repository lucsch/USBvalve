#ifndef USBVALVEPIO_USBVALVE_H
#define USBVALVEPIO_USBVALVE_H

#include "Arduino.h"
#include <pio_usb.h>
#include "Adafruit_TinyUSB.h"
#include <XxHash_arduino.h>
#include <pico/stdlib.h>

// Uncomment the following to compile for the RP2040 based TFT round display
// https://www.raspberrypi.com/news/how-to-build-your-own-raspberry-pi-watch/
//#define PIWATCH
#if defined(PIWATCH)

#include <Arduino_GFX_Library.h>
#include "background.h"

#else

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// LED Pin. If solid GREEN everything is OK, otherwise it will be put OFF
#define LED_PIN   25

#endif

void msc_flush_callback(void);
int32_t msc_read_callback(uint32_t lba, void* buffer, uint32_t bufsize);
int32_t msc_write_callback(uint32_t lba, uint8_t* buffer, uint32_t bufsize);
void cls(void);
void printout(const char *str);
void swreset();
void hexDump(unsigned char* data, size_t size);
static void process_kbd_report(hid_keyboard_report_t const* report);
static void process_mouse_report(hid_mouse_report_t const* report);
static void check_special_key(uint8_t code);
void cursor_movement(int8_t x, int8_t y, int8_t wheel);

#endif //USBVALVEPIO_USBVALVE_H

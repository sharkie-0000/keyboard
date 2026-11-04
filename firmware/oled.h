#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include "config.h"

static U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C oled(U8G2_R0, U8X8_PIN_NONE);

inline void oledBegin() {
  Wire.setSDA(OLED_SDA_PIN);
  Wire.setSCL(OLED_SCL_PIN);
  Wire.begin();
  oled.begin();
  oled.setI2CAddress(OLED_I2C_ADDRESS << 1);
  oled.clearBuffer();
  oled.setFont(u8g2_font_6x12_tf);
  oled.drawStr(0, 12, "Custom Keyboard");
  oled.drawStr(0, 27, "RP2040 Ready");
  oled.sendBuffer();
}

inline void oledUpdate() {
  static uint32_t lastUpdate = 0;
  if (millis() - lastUpdate < 250) return;
  lastUpdate = millis();

  oled.clearBuffer();
  oled.setFont(u8g2_font_6x12_tf);
  oled.drawStr(0, 12, "Custom Keyboard");
  oled.setCursor(0, 28);
  oled.print("Uptime ");
  oled.print(millis() / 1000);
  oled.print("s");
  oled.sendBuffer();
}

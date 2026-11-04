#include <Arduino.h>
#include <Keyboard.h>
#include "config.h"
#include "switches.h"
#include "oled.h"
#include "encoder.h"

void setup() {
  switchesBegin();
  oledBegin();
  encoderBegin();
  Keyboard.begin();
}

void loop() {
  switchesScan();
  encoderUpdate();
  oledUpdate();
}

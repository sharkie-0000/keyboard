#pragma once

#include <Arduino.h>
#include "config.h"

inline void encoderBegin() {
  if (ENCODER_A_PIN < 0 || ENCODER_B_PIN < 0 || ENCODER_SW_PIN < 0) return;
  pinMode(ENCODER_A_PIN, INPUT_PULLUP);
  pinMode(ENCODER_B_PIN, INPUT_PULLUP);
  pinMode(ENCODER_SW_PIN, INPUT_PULLUP);
}

inline void encoderUpdate() {
}

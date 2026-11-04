#pragma once

#include <Arduino.h>
#include <Keyboard.h>
#include "config.h"

static const uint8_t KEYMAP[MATRIX_ROWS][MATRIX_COLS] = {
  {KEY_ESC, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', KEY_BACKSPACE},
  {KEY_TAB, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\'},
  {KEY_CAPS_LOCK, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', KEY_RETURN, 0},
  {KEY_LEFT_SHIFT, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', KEY_RIGHT_SHIFT, 0, 0},
  {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_LEFT_ALT, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', KEY_RIGHT_ALT, KEY_RIGHT_GUI, KEY_RIGHT_CTRL}
};

static bool keyState[MATRIX_ROWS][MATRIX_COLS] = {};
static bool stableState[MATRIX_ROWS][MATRIX_COLS] = {};
static uint32_t lastChange[MATRIX_ROWS][MATRIX_COLS] = {};
static const uint16_t DEBOUNCE_MS = 8;

inline void switchesBegin() {
  for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
    pinMode(ROW_PINS[r], OUTPUT);
    digitalWrite(ROW_PINS[r], HIGH);
  }
  for (uint8_t c = 0; c < MATRIX_COLS; c++) {
    pinMode(COL_PINS[c], INPUT_PULLUP);
  }
}

inline void switchesScan() {
  uint32_t now = millis();

  for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
    digitalWrite(ROW_PINS[r], LOW);
    delayMicroseconds(5);

    for (uint8_t c = 0; c < MATRIX_COLS; c++) {
      bool pressed = digitalRead(COL_PINS[c]) == LOW;

      if (pressed != keyState[r][c]) {
        keyState[r][c] = pressed;
        lastChange[r][c] = now;
      }

      if ((now - lastChange[r][c]) >= DEBOUNCE_MS && stableState[r][c] != keyState[r][c]) {
        stableState[r][c] = keyState[r][c];
        uint8_t key = KEYMAP[r][c];

        if (key != 0) {
          if (stableState[r][c]) Keyboard.press(key);
          else Keyboard.release(key);
        }
      }
    }

    digitalWrite(ROW_PINS[r], HIGH);
  }
}

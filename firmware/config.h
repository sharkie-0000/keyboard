#pragma once

#include <Arduino.h>

static const uint8_t ROW_PINS[5] = {0, 1, 2, 3, 4};
static const uint8_t COL_PINS[14] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

static const uint8_t OLED_SDA_PIN = 22;
static const uint8_t OLED_SCL_PIN = 21;
static const uint8_t OLED_I2C_ADDRESS = 0x3C;

static const int8_t ENCODER_A_PIN = -1;
static const int8_t ENCODER_B_PIN = -1;
static const int8_t ENCODER_SW_PIN = -1;

static const uint8_t MATRIX_ROWS = 5;
static const uint8_t MATRIX_COLS = 14;

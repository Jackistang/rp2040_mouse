/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// -----------------------------------------------------
// NOTE: THIS HEADER IS ALSO INCLUDED BY ASSEMBLER SO
//       SHOULD ONLY CONSIST OF PREPROCESSOR DIRECTIVES
// -----------------------------------------------------

// This header may be included by other board headers as "boards/pico.h"

#ifndef _BOARDS_GAMEKIT_RP2040_H
#define _BOARDS_GAMEKIT_RP2040_H

// For board detection
#define GAMEKIT_RP2040

// --- BOARD SPECIFIC ---
#ifndef GAMEKIT_RP2040_LED
#define GAMEKIT_RP2040_LED 4
#endif

#ifndef GAMEKIT_RP2040_BUTTON_B
#define GAMEKIT_RP2040_BUTTON_B 5
#endif

#ifndef GAMEKIT_RP2040_BUTTON_A
#define GAMEKIT_RP2040_BUTTON_A 6
#endif

#ifndef GAMEKIT_RP2040_LCD_RESET
#define GAMEKIT_RP2040_LCD_RESET 0
#endif

#ifndef GAMEKIT_RP2040_LCD_DC
#define GAMEKIT_RP2040_LCD_DC 1
#endif

#ifndef GAMEKIT_RP2040_LCD_SCK
#define GAMEKIT_RP2040_LCD_SCK 2
#endif

#ifndef GAMEKIT_RP2040_LCD_SDA
#define GAMEKIT_RP2040_LCD_SDA 3
#endif

#ifndef GAMEKIT_RP2040_IMU_INT
#define GAMEKIT_RP2040_IMU_INT 9
#endif

#ifndef GAMEKIT_RP2040_I2C_1_SDA
#define GAMEKIT_RP2040_I2C_1_SDA 10
#endif

#ifndef GAMEKIT_RP2040_I2C_1_SCL
#define GAMEKIT_RP2040_I2C_1_SCL 11
#endif

#ifndef GAMEKIT_RP2040_BUZZER
#define GAMEKIT_RP2040_BUZZER 23
#endif

#ifndef GAMEKIT_RP2040_IR_TX
#define GAMEKIT_RP2040_IR_TX 24
#endif

#ifndef GAMEKIT_RP2040_IR_RX
#define GAMEKIT_RP2040_IR_RX 25
#endif

#ifndef GAMEKIT_RP2040_JOY_X
#define GAMEKIT_RP2040_JOY_X 28
#endif

#ifndef GAMEKIT_RP2040_JOY_Y
#define GAMEKIT_RP2040_JOY_Y 29
#endif

// --- UART ---
#ifndef PICO_DEFAULT_UART
#define PICO_DEFAULT_UART 0
#endif
#ifndef PICO_DEFAULT_UART_TX_PIN
#define PICO_DEFAULT_UART_TX_PIN 12
#endif
#ifndef PICO_DEFAULT_UART_RX_PIN
#define PICO_DEFAULT_UART_RX_PIN 13
#endif

// --- LED ---
#ifndef PICO_DEFAULT_LED_PIN
#define PICO_DEFAULT_LED_PIN GAMEKIT_RP2040_LED
#endif
// no PICO_DEFAULT_WS2812_PIN

// --- I2C ---
#ifndef PICO_DEFAULT_I2C
#define PICO_DEFAULT_I2C 0
#endif
#ifndef PICO_DEFAULT_I2C_SDA_PIN
#define PICO_DEFAULT_I2C_SDA_PIN 16
#endif
#ifndef PICO_DEFAULT_I2C_SCL_PIN
#define PICO_DEFAULT_I2C_SCL_PIN 17
#endif

// --- SPI ---  SPI0 for st7789
// #ifndef PICO_DEFAULT_SPI
// #define PICO_DEFAULT_SPI 0
// #endif
// #ifndef PICO_DEFAULT_SPI_SCK_PIN
// #define PICO_DEFAULT_SPI_SCK_PIN 18
// #endif
// #ifndef PICO_DEFAULT_SPI_TX_PIN
// #define PICO_DEFAULT_SPI_TX_PIN 19
// #endif
// #ifndef PICO_DEFAULT_SPI_RX_PIN
// #define PICO_DEFAULT_SPI_RX_PIN 16
// #endif
// #ifndef PICO_DEFAULT_SPI_CSN_PIN
// #define PICO_DEFAULT_SPI_CSN_PIN 17
#endif

// --- FLASH ---

#define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1

#ifndef PICO_FLASH_SPI_CLKDIV
#define PICO_FLASH_SPI_CLKDIV 2
#endif

#ifndef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (2 * 1024 * 1024)
#endif

// Drive high to force power supply into PWM mode (lower ripple on 3V3 at light loads)
#define PICO_SMPS_MODE_PIN 23

#ifndef PICO_RP2040_B0_SUPPORTED
#define PICO_RP2040_B0_SUPPORTED 1
#endif

#endif

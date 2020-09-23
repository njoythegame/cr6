/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * CREALITY (STM32F103) board pin assignments
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#endif

#if HOTENDS > 1 || E_STEPPERS > 1
  #error "CREALITY supports up to 1 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_NAME "CREALITY"

//
// EEPROM
//
/* I2C */
// #define I2C_EEPROM
// #define E2END 0x3FFF   // 16Kb (24c16)
  #define IIC_BL24CXX_EEPROM                      // EEPROM on I2C-0 used only for display settings
  #if ENABLED(IIC_BL24CXX_EEPROM)
    #define IIC_EEPROM_SDA                  PA11
    #define IIC_EEPROM_SCL                  PA12
    #define MARLIN_EEPROM_SIZE 0x800              // 2Kb (24C16)
  #else
    #define SDCARD_EEPROM_EMULATION               // SD EEPROM until all EEPROM is BL24CXX
    #define MARLIN_EEPROM_SIZE 0x800              // 2Kb
  #endif


/* SPI */
//#define SPI_EEPROM  // EEPROM on SPI-0
//#define SPI_CHAN_EEPROM1        ?
//#define SPI_EEPROM1_CS          ?
// 2K EEPROM
//#define SPI_EEPROM2_CS          ?
// 32Mb FLASH
//#define SPI_FLASH_CS            ?

/* FLASH */
// Enable EEPROM Emulation for this board
// This setting should probably be in configuration.h
// but it is literally the only board which uses it.
//#define FLASH_EEPROM_EMULATION


//
// Limit Switches
//
#define X_MIN_PIN          PC4
// #define X_MAX_PIN          PA7
#define Y_MIN_PIN          PC5
#ifdef BLTOUCH
  #define Z_MIN_PIN        PB1  // BLTouch IN PIN
  #define SERVO0_PIN       PB0  // BLTouch OUT PIN
#elif ENABLED(FIX_MOUNTED_PROBE)
  #define Z_MIN_PIN        PA4
  #define COM_PIN          PA5
#else
  #define Z_MIN_PIN        PA7
#endif

//
// Steppers
//
#define X_ENABLE_PIN        PC3
#define X_STEP_PIN          PB8
#define X_DIR_PIN           PB7

#define Y_ENABLE_PIN        PC3
#define Y_STEP_PIN          PB6
#define Y_DIR_PIN           PB5

#define Z_ENABLE_PIN        PC3
#define Z_STEP_PIN          PB4
#define Z_DIR_PIN           PB3

#define E0_ENABLE_PIN       PC3
#define E0_STEP_PIN         PC2
#define E0_DIR_PIN          PB9

#if HAS_TMC220x

  //
  // TMC2208 mode
  //
  // #define TMC2208_STANDALONE

  #define X_HARDWARE_SERIAL  MSerial2
  #define Y_HARDWARE_SERIAL  MSerial2
  #define Z_HARDWARE_SERIAL  MSerial2
  #define E0_HARDWARE_SERIAL MSerial2

  //
  // TMC2208 Software serial
  //
  // #define HAVE_SW_SERIAL

  // Reduce baud rate to improve software serial reliability
  // #define TMC_BAUD_RATE 19200

#endif

//
// Release PB4 (Z_STEP_PIN) from JTAG NRST role
//
#define DISABLE_DEBUG

//
// Temperature Sensors
//
#define TEMP_0_PIN         PB1   // TH1
#define TEMP_BED_PIN       PB0   // TB1

//
// Heaters / Fans
/*certification*/
// #define HEATER_0_PIN       PB14  // HEATER1
// #define HEATER_BED_PIN     PB13  // HOT BED

// #define FAN_PIN            PB15  // FAN
// #define FAN_SOFT_PWM

#define HEATER_0_PIN       PA1   // HEATER1
#define HEATER_BED_PIN     PA2   // HOT BED

#define FAN_PIN            PA0   // FAN
#define FAN_SOFT_PWM


/* RET6 12864 LCD */
// #define LCD_PINS_RS        PB12
// #define LCD_PINS_ENABLE    PB15
// #define LCD_PINS_D4        PB13

// #define BTN_ENC            PB2
// #define BTN_EN1            PB10
// #define BTN_EN2            PB14

// #define BEEPER_PIN         PC6


/* VET6 12864 LCD */
// #define LCD_PINS_RS        PA4
// #define LCD_PINS_ENABLE    PA7
// #define LCD_PINS_D4        PA5

// #define BTN_ENC            PC5  
// #define BTN_EN1            PB10
// #define BTN_EN2            PA6


/* RET6 DWIN ENCODER LCD */
// #define BTN_ENC            PB14  
// #define BTN_EN1            PB15
// #define BTN_EN2            PB12

// #define BEEPER_PIN         PB13


/* VET6 DWIN ENCODER LCD */
// #define BTN_ENC            PA6
// #define BTN_EN1            PA7
// #define BTN_EN2            PA4

// #define BEEPER_PIN         PA5


/* SD card detect */
#define SD_DETECT_PIN      PC7

#define LED_CONTROL_PIN    PA6
#define CHECK_MATWEIAL     PA7
// #define OPTO_SWITCH_PIN    PB2   // certification
#define OPTO_SWITCH_PIN    PC6

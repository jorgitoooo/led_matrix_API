#ifndef __CONSTS_H__
#define __CONSTS_H__

// TYPE DEFINITIONS
typedef unsigned  char uc;
typedef   signed  char sc;
typedef unsigned short us;

// DEFUALT PORT
#define LED_MATRIX_PORT PORTB

// ADDRESSES FOR MAX7219
#define NO_OP      0x00
#define DIG_0      0x01
#define DIG_1      0x02
#define DIG_2      0x03
#define DIG_3      0x04
#define DIG_4      0x05
#define DIG_5      0x06
#define DIG_6      0x07
#define DIG_7      0x08
#define DECODE_MODE_REG_ADDR 0x09
#define INTENSITY_REG_ADDR   0x0A
#define SCAN_LIMIT_REG_ADDR  0x0B
#define SHUTDOWN_REG_ADDR    0x0C
#define DISPLAY_TST_REG_ADDR 0x0F

// DECODE MODES
#define NO_DECODE  0x00
#define ALL_DIGITS 0xFF

// INTENSITIES
#define INTENSITY_LOW  0x00
#define INTENSITY_MID  0x07
#define INTENSITY_HIGH 0x0F

// SCAN LIMITS
#define SCAN_LOW_NIB 0x03
#define SCAN_BYTE    0x07

// SHUTDOWN MODES
#define SHUTDOWN_MODE        0x00
#define SHUTDOWN_NORMAL_MODE 0x01

// DISPLAY TEST MODES
#define DISP_NORMAL_MODE 0x00
#define DISP_TEST_MODE   0x01

// BITS USED
// - Bits used on an Atmega1284
#define DATA_BIT      0x01
#define LOAD_BIT      0x02
#define CLK_BIT       0x04

// DATA OPERATIONS
// - Port B used on an Atmega1284
#define DATA_LOW()    (LED_MATRIX_PORT &= ~DATA_BIT)
#define DATA_HIGH()   (LED_MATRIX_PORT |=  DATA_BIT)
#define CLK_LOW()     (LED_MATRIX_PORT &= ~CLK_BIT)
#define CLK_HIGH()    (LED_MATRIX_PORT |=  CLK_BIT)
#define LOAD_LOW()    (LED_MATRIX_PORT &= ~LOAD_BIT)
#define LOAD_HIGH()   (LED_MATRIX_PORT |=  LOAD_BIT)

#endif

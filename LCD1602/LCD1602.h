/*
 * LCD 16 x 2 pinout
 * 1 -  Ground
 * 2 -  VCC (+3.3 to +5V)
 * 3 -  Contrast adjustment (VO)
 * 4 -  Register Select (RS). RS=0: Command, RS=1: Data
 * 5 -  Read/Write (R/W). R/W=0: Write, R/W=1: Read (This pin is optional due to the fact that most of the time you will only want to write to it and not read. Therefore, in general use, this pin will be permanently connected directly to ground.)
 * 6 -  Clock (Enable). Falling edge triggered
 * 7 -  Bit 0 (Not used in 4-bit operation)
 * 8 -  Bit 1 (Not used in 4-bit operation)
 * 9 -  Bit 2 (Not used in 4-bit operation)
 * 10 - Bit 3 (Not used in 4-bit operation)
 * 11 - Bit 4
 * 12 - Bit 5
 * 13 - Bit 6
 * 14 - Bit 7
 * 15 - Backlight Anode (+) (If applicable)
 * 16 - Backlight Cathode (-) (If applicable)
 */

#ifndef LCD1602_H
#define LCD1602_H

#include "stm32f0xx.h"
#include "../Delay/Delay.h"

#define GPIO_PORT		GPIOC
#define GPIO_ODR 		GPIO_PORT->ODR
#define GPIO_MODER 	GPIO_PORT->MODER

#define LCD_RS_PIN			12
#define LCD_RS			(1 << LCD_RS_PIN)
#define LCD_RW_PIN			11
#define LCD_RW			(1 << LCD_RW_PIN)
#define LCD_E_PIN				10
#define LCD_E			(1 << LCD_E_PIN)
#define LCD_D4_PIN			9
#define LCD_D4			(1 << LCD_D4_PIN)
#define LCD_D5_PIN			8
#define LCD_D5			(1 << LCD_D5_PIN) 
#define LCD_D6_PIN			7
#define LCD_D6			(1 << LCD_D6_PIN)
#define LCD_D7_PIN			6
#define LCD_D7			(1 << LCD_D7_PIN)

void SetPins(uint16_t pins);
void ResetPins(uint16_t pins);

void LCDSendChar(uint8_t ch);
void LCDSendCommand(uint8_t cmd);
void LCDInit(void);
void LCDClear(void);
void LCDHome(void);
void LCDString(uint8_t* str, uint8_t bytes);
void LCDGoToXY(uint8_t x, uint8_t y);
void LCDDefineChar(const uint8_t *,uint8_t);
void LCDShiftRight(uint8_t n);
void LCDShiftLeft(uint8_t n);
void LCDCursorOn(void);
void LCDCursorOnBlink(void);
void LCDCursorOff(void);
void LCDBlank(void);
void LCDVisible(void);
void LCDCursorLeft(uint8_t n);
void LCDCursorRight(uint8_t n);

#endif //LCD1602_H

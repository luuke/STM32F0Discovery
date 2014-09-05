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

#define LCD_RS_PORT	GPIOC 	//define MCU pin connected to LCD RS
#define LCD_RS_PIN	12 	//define MCU pin connected to LCD RS

#define LCD_RW_PORT	GPIOC 	//define MCU pin connected to LCD RW
#define LCD_RW_PIN	11 	//define MCU pin connected to LCD RW

#define LCD_E_PORT	GPIOC	//define MCU pin connected to LCD E
#define LCD_E_PIN	10	//define MCU pin connected to LCD E

#define LCD_D4_PORT	GPIOC	//define MCU pin connected to LCD D3
#define LCD_D4_PIN	9	//define MCU pin connected to LCD D3
#define LCD_D5_PORT	GPIOC	//define MCU pin connected to LCD D4
#define LCD_D5_PIN	8	//define MCU pin connected to LCD D4
#define LCD_D6_PORT	GPIOC	//define MCU pin connected to LCD D5
#define LCD_D6_PIN	7	//define MCU pin connected to LCD D5
#define LCD_D7_PORT	GPIOC	//define MCU pin connected to LCD D6
#define LCD_D7_PIN	6	//define MCU pin connected to LCD D6

#define LDPORT GPIOC	//define MCU port connected to LCD data pins
#define LCPORT GPIOC	//define MCU port connected to LCD control pins
#define LDMODER GPIOC->MODER	//define MCU direction register for port connected to LCD data pins
#define LCMODER GPIOC->MODER	//define MCU direction register for port connected to LCD control pins

/* Implementation does NOT contain R/W pin!!! */

//Done
void LCDInit(void);			                            //Initializes LCD

//Not yet implemented
void LCDSendChar(uint8_t);		                        //forms data ready to send to 74HC164
void LCDsendCommand(uint8_t);	                        //forms data ready to send to 74HC164
void LCDclr(void);				                        //Clears LCD
void LCDhome(void);			                            //LCD cursor home
void LCDstring(uint8_t*, uint8_t);	                    //Outputs string to LCD
void LCDGotoXY(uint8_t, uint8_t);	                    //Cursor to X Y position
void CopyStringtoLCD(const uint8_t*, uint8_t, uint8_t); //copies flash string to LCD at x,y
void LCDdefinechar(const uint8_t *,uint8_t);            //write char to LCD CGRAM 
void LCDshiftRight(uint8_t);	                        //shift by n characters Right
void LCDshiftLeft(uint8_t);	                            //shift by n characters Left
void LCDcursorOn(void);		                            //Underline cursor ON
void LCDcursorOnBlink(void);	                        //Underline blinking cursor ON
void LCDcursorOFF(void);		                        //Cursor OFF
void LCDblank(void);		 	                        //LCD blank but not cleared
void LCDvisible(void);			                        //LCD visible
void LCDcursorLeft(uint8_t);	                        //Shift cursor left by n
void LCDcursorRight(uint8_t);	                        //shif cursor right by n

#endif //LCD1602_H

#include "LCD1602.h"

/*
#define LCD_RS_PIN	12 	//define MCU pin connected to LCD RS
#define LCD_RW_PIN	11 	//define MCU pin connected to LCD RW
#define LCD_E_PIN		10		//define MCU pin connected to LCD E
#define LCD_D4_PIN	9		//define MCU pin connected to LCD D3
#define LCD_D5_PIN	8		//define MCU pin connected to LCD D4
#define LCD_D6_PIN	7		//define MCU pin connected to LCD D5
#define LCD_D7_PIN	6	
*/

void SetPins(uint16_t pins)
{
	// Usefull only for 4-bit mode
	// Pins value: | - | RS | RW | E | DB7 | DB6 | DB5 | DB4 |
	GPIOC->ODR |= pins;
}

void ResetPins(uint16_t pins)
{
	GPIOC->ODR &= ~pins;
}

void LCDInit(void)
{
	Delay_ms(100);
	ResetPins(LCD_RS | LCD_RW | LCD_E | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	//GPIOC->BSRR |= GPIO_BSRR_BR_6
	//				|	GPIO_BSRR_BR_7
	//				|	GPIO_BSRR_BR_8
	//				|	GPIO_BSRR_BR_9
	//				|	GPIO_BSRR_BR_10
	//				|	GPIO_BSRR_BR_11
	//				|	GPIO_BSRR_BR_12;
	GPIOC->MODER |= GPIO_MODER_MODER6_0
					|	 GPIO_MODER_MODER7_0
					|	 GPIO_MODER_MODER8_0
					|	 GPIO_MODER_MODER9_0
					|	 GPIO_MODER_MODER10_0
					|	 GPIO_MODER_MODER11_0
					|	 GPIO_MODER_MODER12_0;
	SetPins(LCD_RS | LCD_E | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	
	//--------- Write 0x03 -----------
	ResetPins(LCD_D7 | LCD_D6 | LCD_RS);	
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(5);
	
	//--------- Write 0x03 -----------
	SetPins(LCD_E);
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);
	
	//--------- Write 0x03 -----------
	SetPins(LCD_E);
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);
	
	//--------- Enable Four Bit Mode ----------
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BS_8
					|	GPIO_BSRR_BR_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);
	
	//---------- Set Interface Length ----------
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BS_8
					|	GPIO_BSRR_BR_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BS_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BR_8
					|	GPIO_BSRR_BR_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);
	
	//---------- Turn off the Display ----------
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BR_8
					|	GPIO_BSRR_BR_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BS_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BR_8
					|	GPIO_BSRR_BR_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);
	
	//------------ Clear the Display -----------
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BR_8
					|	GPIO_BSRR_BR_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BR_8
					|	GPIO_BSRR_BS_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);
	
	//-------- Set Cursor Move Direction --------
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BR_8
					|	GPIO_BSRR_BR_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BS_7
					|	GPIO_BSRR_BS_8
					|	GPIO_BSRR_BR_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);	
	
	//---------- Enable Display/Cursor ----------
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BR_8
					|	GPIO_BSRR_BR_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BS_6
					|	GPIO_BSRR_BS_7
					|	GPIO_BSRR_BS_8
					|	GPIO_BSRR_BS_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);		
}

void LCDSendChar(uint8_t ch)
{
	//4 MSB bits
	ResetPins(LCD_RS | LCD_E | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	SetPins(LCD_RS);	
	GPIOC->ODR |= (((ch>>4)&0x01)<<LCD_D4_PIN) | (((ch>>5)&0x01)<<LCD_D5_PIN) | (((ch>>6)&0x01)<<LCD_D6_PIN) | (((ch>>7)&0x01)<<LCD_D7_PIN);	
	SetPins(LCD_E);
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);		
	//4 LSB bits
	ResetPins(LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	GPIOC->ODR |= (((ch)&0x01)<<9) | (((ch>>1)&0x01)<<8) | (((ch>>2)&0x01)<<7) | (((ch>>3)&0x01)<<6);
	SetPins(LCD_E);	
	Delay_ms(1);
	ResetPins(LCD_E);	
	Delay_ms(1);		
}

void LCDSendCommand(uint8_t cmd)
{
	//4 MSB bits
	ResetPins(LCD_RS | LCD_E | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	GPIOC->ODR |= (((cmd>>4)&0x01)<<LCD_D4_PIN) | (((cmd>>5)&0x01)<<LCD_D5_PIN) | (((cmd>>6)&0x01)<<LCD_D6_PIN) | (((cmd>>7)&0x01)<<LCD_D7_PIN);	
	SetPins(LCD_E);
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);		
	//4 LSB bits
	ResetPins(LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	GPIOC->ODR |= (((cmd)&0x01)<<9) | (((cmd>>1)&0x01)<<8) | (((cmd>>2)&0x01)<<7) | (((cmd>>3)&0x01)<<6);
	SetPins(LCD_E);	
	Delay_ms(1);
	ResetPins(LCD_E);	
	Delay_ms(1);	
}

void LCDClear(void)
{
	LCDSendCommand(0x01);
}

void LCDHome(void)
{
	LCDSendCommand(0x02);
}

void LCDString(uint8_t* data, uint8_t nBytes)	
{
	register uint8_t i;

	// check to make sure we have a good pointer
	if (!data) return;

	// print data
	for(i=0; i<nBytes; i++)
	{
		LCDSendChar(data[i]);
	}
}

void LCDGoToXY(uint8_t x, uint8_t y)	
{
#define LCD_DDRAM               7	//set DD RAM address

#define LCD_LINE0_DDRAMADDR		0x00
#define LCD_LINE1_DDRAMADDR		0x40
#define LCD_LINE2_DDRAMADDR		0x14
#define LCD_LINE3_DDRAMADDR		0x54

	register uint8_t DDRAMAddr;
	// remap lines into proper order
	switch(y)
	{
	case 0:  DDRAMAddr = LCD_LINE0_DDRAMADDR + x; break;
	case 1:  DDRAMAddr = LCD_LINE1_DDRAMADDR + x; break;
	case 2:  DDRAMAddr = LCD_LINE2_DDRAMADDR + x; break;
	case 3:  DDRAMAddr = LCD_LINE3_DDRAMADDR + x; break;
	default: DDRAMAddr = LCD_LINE0_DDRAMADDR + x;
	}
	// set data address
	LCDSendCommand(1<<LCD_DDRAM | DDRAMAddr);	
} 

void LCDShiftLeft(uint8_t n)	
{
	uint8_t i;

	for (i=0;i<n;i++)
	{
		LCDSendCommand(0x1E);
	}
}

void LCDShiftRight(uint8_t n)	
{
uint8_t i;

	for (i=0;i<n;i++)
	{
		LCDSendCommand(0x18);
	}
}

//displays LCD cursor
void LCDCursorOn(void) 
{
	LCDSendCommand(0x0E);
}

//displays LCD blinking cursor
void LCDCursorOnBlink(void)	
{
	LCDSendCommand(0x0F);
}

//Turns OFF cursor
void LCDCursorOff(void)	
{
	LCDSendCommand(0x0C);
}

//Blanks LCD
void LCDBlank(void)		
{
	LCDSendCommand(0x08);
}

//Shows LCD
void LCDVisible(void)		
{
	LCDSendCommand(0x0C);
}

//Moves cursor by n poisitions left
void LCDCursorLeft(uint8_t n)	
{
	uint8_t i;

	for (i=0;i<n;i++)
	{
		LCDSendCommand(0x10);
	}
}

//Moves cursor by n poisitions left
void LCDCursorRight(uint8_t n)	
{
	uint8_t i;

	for (i=0;i<n;i++)
	{
		LCDSendCommand(0x14);
	}
}

//Copies string from flash memory to LCD at x y position
//void CopyStringToLCD(const uint8_t *FlashLoc, uint8_t x, uint8_t y)
//{
//	uint8_t i;
//	LCDGotoXY(x,y);
//	for(i=0;(uint8_t)pgm_read_byte(&FlashLoc[i]);i++)
//	{
//		LCDSendChar((uint8_t)pgm_read_byte(&FlashLoc[i]));
//	}
//}

//defines char symbol in CGRAM
//void LCDdefinechar(const uint8_t *pc, uint8_t code)
//{
//	uint8_t a;
//	uint16_t i;
//	a=(code<<3)|0x40;
//	for (i=0; i<8; i++){
//		LCDsendCommand(a++);
//		LCDsendChar((uint8_t)pgm_read_byte(&pc[i]));
//		}
//}

	

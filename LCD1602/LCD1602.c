#include "LCD1602.h"

void SetPins(uint16_t pins)
{
	GPIO_ODR |= pins;
}

void ResetPins(uint16_t pins)
{
	GPIO_ODR &= ~pins;
}

void SetPinsToOutputMode()
{
	GPIO_MODER |= (1 << (2 * LCD_RS_PIN)) 
					| (1 << (2 * LCD_RW_PIN)) 
					| (1 << (2 * LCD_E_PIN)) 
					| (1 << (2 * LCD_D7_PIN)) 
					| (1 << (2 * LCD_D6_PIN)) 
					| (1 << (2 * LCD_D5_PIN)) 
					| (1 << (2 * LCD_D4_PIN));
}

void LCDInit(void)
{
	Delay_ms(100);
	ResetPins(LCD_RS | LCD_RW | LCD_E | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	SetPinsToOutputMode();
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
	ResetPins(LCD_RS | LCD_D7 | LCD_D6 | LCD_D4);
	SetPins(LCD_E | LCD_D5);	
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);
	
	//---------- Set Interface Length ----------
	ResetPins(LCD_RS | LCD_D7 | LCD_D6 | LCD_D4);
	SetPins(LCD_E | LCD_D5);	
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);
	ResetPins(LCD_RS | LCD_D6 | LCD_D5 | LCD_D4);
	SetPins(LCD_E | LCD_D7);	
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);
	
	//---------- Turn off the Display ----------
	ResetPins(LCD_RS | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	SetPins(LCD_E);		
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);
	ResetPins(LCD_RS | LCD_D6 | LCD_D5 | LCD_D4);
	SetPins(LCD_E | LCD_D7);
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);
	
	//------------ Clear the Display -----------
	ResetPins(LCD_RS | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	SetPins(LCD_E);		
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);
	ResetPins(LCD_RS | LCD_D7 | LCD_D6 | LCD_D5);
	SetPins(LCD_E | LCD_D4);	
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);
	
	//-------- Set Cursor Move Direction --------
	ResetPins(LCD_RS | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	SetPins(LCD_E);		
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);
	ResetPins(LCD_RS | LCD_D7 | LCD_D4);
	SetPins(LCD_E | LCD_D6 | LCD_D5);		
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);	
	
	//---------- Enable Display/Cursor ----------
	ResetPins(LCD_RS | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	SetPins(LCD_E);		
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);
	ResetPins(LCD_RS);
	SetPins(LCD_E | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);		
}

void LCDSendChar(uint8_t ch)
{
	//4 MSB bits
	ResetPins(LCD_RS | LCD_E | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	SetPins(LCD_RS);	
	SetPins((((ch>>7)&0x01)*LCD_D7) | (((ch>>6)&0x01)*LCD_D6) | (((ch>>5)&0x01)*LCD_D5) | ((ch>>4)&0x01)*LCD_D4);
	SetPins(LCD_E);
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);		
	//4 LSB bits
	ResetPins(LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	SetPins((((ch>>3)&0x01)*LCD_D7) | (((ch>>2)&0x01)*LCD_D6) | (((ch>>1)&0x01)*LCD_D5) | ((ch)&0x01)*LCD_D4);
	SetPins(LCD_E);	
	Delay_ms(1);
	ResetPins(LCD_E);	
	Delay_ms(1);		
}

void LCDSendCommand(uint8_t cmd)
{
	//4 MSB bits
	ResetPins(LCD_RS | LCD_E | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	SetPins((((cmd>>7)&0x01)*LCD_D7) | (((cmd>>6)&0x01)*LCD_D6) | (((cmd>>5)&0x01)*LCD_D5) | ((cmd>>4)&0x01)*LCD_D4);
	SetPins(LCD_E);
	Delay_ms(1);
	ResetPins(LCD_E);
	Delay_ms(1);		
	//4 LSB bits
	ResetPins(LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4);
	SetPins((((cmd>>3)&0x01)*LCD_D7) | (((cmd>>2)&0x01)*LCD_D6) | (((cmd>>1)&0x01)*LCD_D5) | ((cmd)&0x01)*LCD_D4);
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

void LCDString(uint8_t* str, uint8_t bytes)	
{
	register uint8_t i;

	// check to make sure we have a good pointer
	if (!str) return;

	// print data
	for(i = 0; i < bytes; i++)
	{
		LCDSendChar(str[i]);
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

	for (i = 0; i < n; i++)
	{
		LCDSendCommand(0x1E);
	}
}

void LCDShiftRight(uint8_t n)	
{
	uint8_t i;

	for (i = 0; i < n; i++)
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

	for (i = 0; i < n; i++)
	{
		LCDSendCommand(0x10);
	}
}

//Moves cursor by n poisitions left
void LCDCursorRight(uint8_t n)	
{
	uint8_t i;

	for (i = 0; i < n; i++)
	{
		LCDSendCommand(0x14);
	}
}


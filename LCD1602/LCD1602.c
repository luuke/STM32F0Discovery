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

void LCDInit(void)
{
	Delay_ms(100);
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BR_8
					|	GPIO_BSRR_BR_9
					|	GPIO_BSRR_BR_10
					|	GPIO_BSRR_BR_11
					|	GPIO_BSRR_BR_12;
	GPIOC->MODER |= GPIO_MODER_MODER6_0
					|	 GPIO_MODER_MODER7_0
					|	 GPIO_MODER_MODER8_0
					|	 GPIO_MODER_MODER9_0
					|	 GPIO_MODER_MODER10_0
					|	 GPIO_MODER_MODER11_0
					|	 GPIO_MODER_MODER12_0;
	GPIOC->BSRR |= GPIO_BSRR_BS_6
					|	GPIO_BSRR_BS_7
					|	GPIO_BSRR_BS_8
					|	GPIO_BSRR_BS_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BS_12;				
	
	//--------- Write 0x03 -----------
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BS_8
					|	GPIO_BSRR_BS_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(5);
	
	//--------- Write 0x03 -----------
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BS_8
					|	GPIO_BSRR_BS_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
	Delay_ms(1);
	
	//--------- Write 0x03 -----------
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BS_8
					|	GPIO_BSRR_BS_9
					|	GPIO_BSRR_BS_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10;
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
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BR_8
					|	GPIO_BSRR_BR_9;
	GPIOC->ODR |= (((ch>>4)&0x01)<<9)
					|	(((ch>>5)&0x01)<<8)
					|	(((ch>>6)&0x01)<<7)
					|	(((ch>>7)&0x01)<<6);
	GPIOC->BSRR |= GPIO_BSRR_BS_10
					|	GPIO_BSRR_BS_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);		
	//4 LSB bits
	GPIOC->BSRR |= GPIO_BSRR_BR_6
					|	GPIO_BSRR_BR_7
					|	GPIO_BSRR_BR_8
					|	GPIO_BSRR_BR_9;
	GPIOC->ODR |= (((ch)&0x01)<<9)
					|	(((ch>>1)&0x01)<<8)
					|	(((ch>>2)&0x01)<<7)
					|	(((ch>>3)&0x01)<<6);
	GPIOC->BSRR |= GPIO_BSRR_BS_10
					|	GPIO_BSRR_BS_12;		
	Delay_ms(1);
	GPIOC->BSRR |= GPIO_BSRR_BR_10
					|	GPIO_BSRR_BR_12;		
	Delay_ms(1);		
}

/*******************************************************************************/
/*					             PROPOX                                        */
/*                           www.propox.com                                    */
/*                                                                             */
/* Program demonsturj¹cy dzia³anie wyœwietlacza LCD 16x2.                      */
/* This program show how to use LCD 16x2 with atmega familly microcontroller.  */
/*******************************************************************************/
// wewnetrzny zegar 1MHz (internal oscillator 1MHz)
// PD0 - R/S
// PD1 - E
// PD2 - D4
// PD3 - D5
// PD4 - D6
// PD5 - D7

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "char_code.h"
#include "LCD_lib.h"


const uint8_t  name[] = "PROPOX";
const uint8_t  website[] = "www.propox.com";

const uint8_t backslash[] PROGMEM= 
{
0b00000000,
0b00010101,
0b00001110,
0b00010101,
0b00001110,
0b00010101,
0b00000000,
0b00000000
};

void delay_200ms(void)
{
	_delay_ms(200);
}



int main(void)
{
uint8_t x;
uint8_t y;
uint8_t j;


LCDinit();
LCDcursorOFF();
LCDdefinechar(backslash,0);


LCDGotoXY(0,1);
LCDsendChar(0x00);
LCDstring(website,14);
LCDsendChar(0x00);


	while(1)
	{
		for(x=0;x<11;x++){
			LCDGotoXY(0,0);
			for(j=0;j<x;j++){
				LCDsendChar(space);
			}
			LCDGotoXY(x,0);
			LCDstring(name,6);
			LCDsendChar(space);
			delay_200ms();
		}

		for(y=9;y>0;y--){
			LCDGotoXY(y,0);
			LCDstring(name,6);
			for(j=y+6;j<16;j++){
				LCDsendChar(space);
			}
			delay_200ms();
		}	
	}
	
return 0;
}

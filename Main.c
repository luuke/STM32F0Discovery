#include "stm32f0xx.h"
#include "Delay/Delay.h"
#include "LCD1602/LCD1602.h"

void GPIOInit()
{
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	
}

int main()
{
	GPIOInit();
	LCDInit();
	//LCDCursorOff();
	LCDGoToXY(8,1);
	LCDSendChar('A');
	Delay_ms(200);
	LCDVisible();
	while(1)
	{
		LCDShiftLeft(1);
		Delay_ms(1000);
		LCDSendChar('A');
		Delay_ms(125);
	}
}

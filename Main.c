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
	while(1)
	{
		LCDSendChar('A');
	}
}

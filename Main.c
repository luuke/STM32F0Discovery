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
	LCDHome();
	LCDString("TEMP:26,7*C",11);
	LCDGoToXY(0,1);
	LCDString("HUM:79%",7);
	while(1)
	{
	}
}

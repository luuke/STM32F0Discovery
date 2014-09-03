#include "stm32f0xx.h"

//volatile int i = 0;



void Delay_us(int microseconds)
{
	int i;
	uint32_t tmp = 0;
	SysTick->LOAD = 48;
	SysTick->VAL = 0;
	SysTick->CTRL &= 0xFFFFFFF8;
	SysTick->CTRL |= 0x00000005;
	for(i = 0; i < microseconds; i++)
	{
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)){};
	}
	SysTick->CTRL &= 0xFFFFFFF8;
}

void Delay_ms(int miliseconds)
{
	int i;
	uint32_t tmp;
	SysTick->LOAD = 48000;
	SysTick->VAL = 0;
	SysTick->CTRL &= 0xFFFFFFF8;
	SysTick->CTRL |= 0x00000005;
	for(i = 0; i < miliseconds; i++)
	{
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)){};
	}
	SysTick->CTRL &= 0xFFFFFFF8;
}



void GPIOInit()
{
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER8_0 | GPIO_MODER_MODER9_0;
}

int main()
{
	GPIOInit();
	
	while(1)
	{
		GPIOC->BSRR = GPIO_BSRR_BS_8;	
		Delay_ms(500);
		GPIOC->BSRR = GPIO_BSRR_BR_8;
		Delay_ms(500);
	}
}

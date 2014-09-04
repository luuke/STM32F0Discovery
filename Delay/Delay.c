#include "Delay.h"

void Delay_us(int microseconds)
{
	int i;
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

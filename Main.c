#include "stm32f0xx.h"
#include "Delay/Delay.h"
#include "LCD1602/LCD1602.h"

int conversionResult;
float result;

void ADC1_COMP_IRQHandler(void)
{
	if(ADC1->ISR & ADC_ISR_EOC)
	{
		conversionResult = ADC1->DR;
		result = conversionResult * 0.07;
		
	}
}

void GPIOInit()
{
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN | RCC_AHBENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODER0; //analog mode
}

void ADCInit()
{
	RCC->APB2ENR |= RCC_APB2ENR_ADCEN;

	//Calibration
	ADC1->CR |= ADC_CR_ADCAL;
	while((ADC1->CR & ADC_CR_ADCAL) != 0) { }
	
	//Enable ADC
	ADC1->CR |= ADC_CR_ADEN;
	while((ADC1->ISR & ADC_ISR_ADRDY) == 0) { }
	
	//Select channel
	ADC1->CHSELR |= ADC_CHSELR_CHSEL8;
	
	//Continuous mode
	ADC1->CFGR1 |= ADC_CFGR1_CONT;
	
	//Sampling time
	ADC1->SMPR |= ADC_SMPR1_SMPR;
	
	//Enable End of Conversion interrupt
	ADC1->IER = ADC_IER_EOCIE;
	NVIC_EnableIRQ(ADC1_COMP_IRQn);
	
	//Start
	ADC1->CR |= ADC_CR_ADSTART;	
}

int main()
{
	GPIOInit();
	LCDInit();
	LCDHome();
	LCDString("TEMP:26,7*C",11);
	LCDGoToXY(0,1);
	LCDString("HUM:79%",7);
	ADCInit();
	while(1)
	{
	}
}

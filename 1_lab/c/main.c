#include "stm32f10x.h"

uint32_t cycles = 100000;

void delay();

int main(void)
{
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	GPIOC->CRH = 0;
	GPIOC->CRH |= GPIO_CRH_MODE8_1;
	GPIOA->CRL = 0;
	GPIOA->CRL |= GPIO_CRL_CNF0_1;
	
	
	
	while(1){
		GPIOC->BSRR |= GPIO_BSRR_BS8;
			if (GPIOA->IDR & GPIO_IDR_IDR0){
					cycles -= 50000;
				if (cycles < 10000){
					cycles = 200000;
				}
			}
			delay();
			GPIOC->BSRR |= GPIO_BSRR_BR8;
			delay();
	}
}
	
void delay() {
	uint32_t i;
	for (i = 0; i < cycles; i++);
}	
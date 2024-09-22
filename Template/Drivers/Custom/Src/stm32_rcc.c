/*
@author - github: Anhconstant
- MCU : stm32f103c8
PERIPHERAL : RCC
*/

#ifndef __RCC_C__
#define __RCC_C__

/*  path to file include    */

#include "stm32_rcc.h"

/*  Function start    */
void Clock_Enable( uint32_t* Periph){
	switch ((uint32_t) Periph)
	{
	case (uint32_t)(GPIOA):
		RCC->APB2ENR    |=  RCC_APB2ENR_IOPAEN 	;
		break;
	case (uint32_t)(GPIOB):
		RCC->APB2ENR    |=  RCC_APB2ENR_IOPBEN	;
		break;
	case (uint32_t)(GPIOC):
		RCC->APB2ENR    |=  RCC_APB2ENR_IOPCEN 	;
		break;
	case (uint32_t)(GPIOD):
		RCC->APB2ENR    |=  RCC_APB2ENR_IOPDEN 	;
		break;
	case (uint32_t)(GPIOE):
		RCC->APB2ENR    |=  RCC_APB2ENR_IOPEEN 	;
		break;
	case (uint32_t)(TIM2):
		RCC->APB1ENR	|=	RCC_APB1ENR_TIM2EN	;
		break;
	case (uint32_t)(TIM3):
		RCC->APB1ENR	|=	RCC_APB1ENR_TIM2EN	;
		break;
	case (uint32_t)(TIM4):
		RCC->APB1ENR	|=	RCC_APB1ENR_TIM2EN	;
		break;
	}

}
void Clock_Enable_GPIOA(void){
    RCC->APB2ENR    |=  RCC_APB2ENR_IOPAEN 	;
}

void Clock_Enable_GPIOB(void){
    RCC->APB2ENR    |=  RCC_APB2ENR_IOPBEN	;
}

void Clock_Enable_GPIOC(void){
    RCC->APB2ENR    |=  RCC_APB2ENR_IOPCEN 	;
}

void Clock_Enable_GPIOD(void){
    RCC->APB2ENR    |=  RCC_APB2ENR_IOPDEN 	;
}

void Clock_Enable_GPIOE(void){
    RCC->APB2ENR    |=  RCC_APB2ENR_IOPEEN 	;
}

void Clock_Enable_TIM2(void){
	RCC->APB1ENR	|=	RCC_APB1ENR_TIM2EN	;
}

void Clock_Enable_TIM3(void){
	RCC->APB1ENR	|=	RCC_APB1ENR_TIM3EN	;
}

void Clock_Enable_TIM4(void){
	RCC->APB1ENR	|=	RCC_APB1ENR_TIM4EN	;
}

void Clock_Enable_USART1(void){
	RCC->APB2ENR		|= RCC_APB2ENR_USART1EN	;
}

void Clock_Enable_USART2(void){
	RCC->APB1ENR		|= RCC_APB1ENR_USART2EN	;
}

void Clock_Enable_USART3(void){
	RCC->APB1ENR		|= RCC_APB1ENR_USART3EN	;
}

// void Clock_Enable_TIM5(void){
// 	RCC->APB1ENR	|=	RCC_APB1ENR_TIM5EN	;
// }
// void Clock_Enable_TIM6(void){
// 	RCC->APB1ENR	|=	RCC_APB1ENR_TIM6EN	;
// }
// void Clock_Enable_TIM7(void){
// 	RCC->APB1ENR	|=	RCC_APB1ENR_TIM7EN	;
// }
// void Clock_Enable_TIM12(void){
// 	RCC->APB1ENR	|=	RCC_APB1ENR_TIM12EN	;
// }
// void Clock_Enable_TIM13(void){
// 	RCC->APB1ENR	|=	RCC_APB1ENR_TIM13EN	;
// }
// void Clock_Enable_TIM14(void){
// 	RCC->APB1ENR	|=	RCC_APB1ENR_TIM14EN	;
// }


void Clock_48mhz(void){
#ifdef USE_HSI_CLOCK
	FLASH->ACR 	|= FLASH_ACR_PRFTBE		;
	FLASH->ACR 	|= FLASH_ACR_LATENCY_2	;

	RCC->CR 	|= RCC_CR_HSION			;
	volatile int counter = 20	;
	while((!(RCC->CR&RCC_CR_HSIRDY))&& counter){
		counter--	;
	}
	RCC->CFGR	|= RCC_CFGR_PLLSRC_HSI_Div2	;
	RCC->CFGR	|= RCC_CFGR_PLLMULL12		;
	RCC->CR		|= RCC_CR_PLLON				;

	counter = 20	;
	while((!(RCC->CR&RCC_CR_PLLRDY))&&counter){
		counter--	;
	}
	RCC->CFGR	|= RCC_CFGR_SW_PLL			;

	counter = 20	;
	while((!(RCC->CFGR&RCC_CFGR_SWS_PLL))&&counter){
		counter--	;
	}
	RCC->CFGR	|= RCC_CFGR_MCO_SYSCLK	;
	RCC->CFGR	|= RCC_CFGR_HPRE_0		;
	RCC->CFGR	|= RCC_CFGR_PPRE1_DIV2	;
	RCC->CFGR	|= RCC_CFGR_PPRE2_0		;
	RCC->CFGR	|= RCC_CFGR_ADCPRE_DIV4	;
	RCC->CFGR	|= RCC_CFGR_USBPRE		;
#endif
}


// void Clock_64mhz(void){
// 		/*Clock 64Mhz with HSI clock 8mhz	*/
// 
void Clock_72mhz(void){
	/*Clock 72Mhz with HSE crystal 8mhz	*/
 	FLASH->ACR 	|= FLASH_ACR_PRFTBE		;
	FLASH->ACR 	|= FLASH_ACR_LATENCY_2	;
	RCC->CR		|= RCC_CR_HSEON			;

	volatile int counter = 20	;
	while((!(RCC->CR&RCC_CR_HSERDY))&& counter){
		counter--	;
	}
	RCC->CFGR	|= RCC_CFGR_PLLSRC_HSE	;
	RCC->CFGR	|= RCC_CFGR_PLLMULL9	;
	RCC->CR		|= RCC_CR_PLLON			;
	counter = 20	;
	while((!(RCC->CR&RCC_CR_PLLRDY))&&counter){
		counter--	;
	}
	RCC->CFGR	|= RCC_CFGR_SW_PLL		;
	counter = 20	;
	while((!(RCC->CFGR&RCC_CFGR_SWS_PLL))&&counter){
		counter--	;
	}
	RCC->CFGR	|= RCC_CFGR_MCO_2		;
	RCC->CFGR	|= RCC_CFGR_HPRE_0		;
	RCC->CFGR	|= RCC_CFGR_PPRE1_DIV2	;
	RCC->CFGR	|= RCC_CFGR_PPRE2_0		;
	RCC->CFGR	|= RCC_CFGR_ADCPRE_DIV6	;
	//RCC->CFGR	|= RCC_CFGR_USBPRE		;	
}

#endif

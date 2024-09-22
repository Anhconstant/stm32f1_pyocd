#include "stm32_main.h"S
int main(void)
{	
	Clock_72mhz();
	Clock_Enable_GPIOB()	;
	GPIO_Init(GPIOB,GPIO_PIN_2,General_Output_PP_2mhz);
	delay_config();
	Systick_Init();
	Clock_Enable_USART1();
	//debug_init();
	while(1) {
		ToggleGPIO(GPIOB,GPIO_PIN_2);
		delay_ms(100);
	}
}

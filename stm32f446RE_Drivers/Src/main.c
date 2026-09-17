/*
 * main.c
 *
 *  Created on: Aug 19, 2026
 *      Author: ariva
 */


#include "stmf446rexx_gpio_driver.h"
void delay(void)
{
	for(uint32_t i=0;i<500000/4;i++);
}
int main(void)
{
	GPIO_Handle_t gpioled;
	gpioled.pGPIOx=GPIOA;
	gpioled.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_5;
	gpioled.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUTPUT;
	gpioled.GPIO_PinConfig.GPIO_Pinspeed=GPIO_SPEED_FAST;
	gpioled.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
	gpioled.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&gpioled);
	while(1)
	{
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		delay();
	}
	return 0;
}

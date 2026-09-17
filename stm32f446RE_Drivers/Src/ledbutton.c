/*
 * ledbutton.c
 *
 *  Created on: Aug 19, 2026
 *      Author: ariva
 */


#include "stmf446rexx_gpio_driver.h"
void delay(void)
{
	for(uint32_t i=0;i<500000/2;i++);
}
int main(void)
{
	GPIO_Handle_t gpioled,gpiobtn;
	gpioled.pGPIOx=GPIOA;
	gpioled.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_5;
	gpioled.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUTPUT;
	gpioled.GPIO_PinConfig.GPIO_Pinspeed=GPIO_SPEED_FAST;
	gpioled.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
	gpioled.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&gpioled);
	gpiobtn.pGPIOx=GPIOC;
	gpiobtn.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_13;
	gpiobtn.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_INPUT;
	gpiobtn.GPIO_PinConfig.GPIO_Pinspeed=GPIO_SPEED_FAST;
	gpiobtn.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&gpiobtn);
	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13)==0)
		{
			delay();
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		}
	}
	return 0;
}

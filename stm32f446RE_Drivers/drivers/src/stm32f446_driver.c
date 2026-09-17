/*
 * stm32f446_driver.c
 *
 *  Created on: Aug 16, 2026
 *      Author: ariva
 */
#include <stdint.h>
#include "stmf446rexx_gpio_driver.h"

//periphiral clock setup
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi==ENABLE)
	{
		if(pGPIOx==GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx==GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx==GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx==GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx==GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx==GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx==GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx==GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}
	else
		if(pGPIOx==GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx==GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx==GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx==GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx==GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx==GPIOF)
		{
			GPIOF_PCLK_DI();
		}
		else if(pGPIOx==GPIOG)
		{
			GPIOG_PCLK_DI();
		}
		else if(pGPIOx==GPIOH)
		{
			GPIOH_PCLK_DI();
		}
}
//Init and Deinit
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
//	enable the periphiral clock
	GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

	//configure the mode of GPIO pin
	uint32_t temp=0;
if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG )
	{
		temp= (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <<2*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)) ;
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << 2*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |= temp;
		temp=0;
		}
else{
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode==GPIO_MODE_IT_FT)
		{
	//		configure FTSR
			EXTI->FTSR |= (1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
//			clear the corrosponding RTSR bit
			EXTI->RTSR &= ~(1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode==GPIO_MODE_IT_RT)
		{
			//		configure RTSR
					EXTI->RTSR |= (1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		//			clear the corrosponding FTSR bit
					EXTI->FTSR &= ~(1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode==GPIO_MODE_IT_FRT)
		{
	//		configure both FTSR and RTSR
			EXTI->RTSR |= (1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	//			clear the corrosponding FTSR bit
			EXTI->FTSR |= (1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}

//		configure the SYSCFG
		uint8_t temp1=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/4;
		uint8_t temp2=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%4;
		uint8_t portcode=GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG->EXTICR[temp1]=(portcode)<<4*(temp2);
//		enable the EXTI interupt delivery usin IMR
		EXTI->IMR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
}


//configuring the speed of the GPIO pin
temp=(pGPIOHandle->GPIO_PinConfig.GPIO_Pinspeed << 2*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->OSPEEDER &= ~(0x3 << 2*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->OSPEEDER |=temp;
temp=0;

//configureing the pupd
temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl<<2*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << 2*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
pGPIOHandle->pGPIOx->PUPDR |=temp;
temp=0;

//configure the optype
temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
pGPIOHandle->pGPIOx->OTYPER |=temp;

//configure the alternate functionality
if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
{
	uint8_t temp1,temp2;
	temp1=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
	temp2=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
	pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF <<(4*temp2));
	SYSCFG_PCLK_EN();
	pGPIOHandle->pGPIOx->AFR[temp1] |= pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4*temp2);
}
}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx==GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx==GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx==GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx==GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx==GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx==GPIOF)
	{
		GPIOF_REG_RESET();
	}
	else if(pGPIOx==GPIOG)
	{
		GPIOG_REG_RESET();
	}
	else if(pGPIOx==GPIOH)
	{
		GPIOH_REG_RESET();
	}
}
//data read and write
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	uint8_t value;
	value=(uint8_t)((pGPIOx->IDR>>PinNumber) & 0x00000001);
	return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value=(uint8_t)(pGPIOx->IDR);
	return value;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t Value)
{
	if(Value==GPIO_PIN_SET)
		pGPIOx->ODR |= (1<<PinNumber);
	else
		pGPIOx->ODR &= ~(1<<PinNumber);
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx , uint16_t Value)
{
	pGPIOx->ODR=Value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR^= (1<<PinNumber);
}
//IRQ configuration and ISR handling
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
	if(EnorDi==ENABLE)
	{
		if(IRQNumber>=31)
		{
//			program ISER0 register
			*(NVIC_ISER0) |= (1 << IRQNumber);
		}
		else if(IRQNumber>=31 && IRQNumber<64)
		{
//			program ISER1 register
			*(NVIC_ISER1) |= (1<<IRQNumber%32);
		}
		else if(IRQNumber>=64 && IRQNumber<96)
		{
//			program ISER2 register
			*(NVIC_ISER2) |= (1<<IRQNumber%64);

		}
	}
	else
		if(IRQNumber>=31)
		{
//			program ICER0 register
			*(NVIC_ICER0) |= (1<<IRQNumber);
		}
		else if(IRQNumber>=31 && IRQNumber<64)
		{
//			program ICER1 register
			*(NVIC_ICER1) |= (1<<IRQNumber%32);
		}
		else if(IRQNumber>=64 && IRQNumber<96)
		{
//			program ICER2 register
			*(NVIC_ICER2) |= (1<<IRQNumber%64);
		}
}
void GPIO_IRQPriorityConfig(uint8_t IRQNumebr,uint8_t IRQPriority)
{
	uint8_t iprx =IRQNumebr/4;
	uint8_t irpx_section=IRQNumebr%4;
	uint8_t shift_amount=irpx_section+(8-NO_PR_BITS_IMPLEMENTED);;
	*(NIVC_IPR_BASEADDR+iprx) |= IRQPriority<<8*(shift_amount);
}
void GPIO_IRQHandling(uint8_t PinNumber)
{
	if(EXTI->PR & (1<<PinNumber))
	{
		EXTI->PR |= (1<<PinNumber);
	}
}

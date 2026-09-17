/*
 * stm32f446xx.h
 *
 *  Created on: Aug 14, 2026
 *      Author: ariva
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_
#include <stdint.h>
//processor specific details
//ISER register addresses
#define NVIC_ISER0				((volatile uint32_t*) 0xE000E100)
#define NVIC_ISER1				((volatile uint32_t*) 0xE000E104)
#define NVIC_ISER2				((volatile uint32_t*) 0xE000E108)
//ICER register addresses
#define NVIC_ICER0				((volatile uint32_t*) 0XE000E180)
#define NVIC_ICER1				((volatile uint32_t*) 0XE000E184)
#define NVIC_ICER2				((volatile uint32_t*) 0XE000E188	)
//priority register addresses
#define NIVC_IPR_BASEADDR		((volatile uint32_t*) 0xE000E400)
#define NO_PR_BITS_IMPLEMENTED 4

#define FLASH_BASEADDR			0x08000000U
#define SRAM1_BASEADDR			0x20000000U
#define SRAM2_BASEADDR			0x2001C000U
#define ROM						0x1FFF0000U
#define SRAM					SRAM1_BASEADDR
#define PERIPH_BASE				0x40000000U
//peripheiral base addressese
#define APB1PERIPH_BASE			0x40000000U
#define APB2PERIPH_BASE			0x40010000U
#define AHB1PERIPH_BASE			0x40020000U
#define AHB2PERIPH_BASE			0x50000000U
//base address of the periphials hanging onn the AHB1 bus
//base address of GPIO pins
#define GPIOA_BASEADDR			(AHB1PERIPH_BASE+0x0000U)
#define GPIOB_BASEADDR			(AHB1PERIPH_BASE+0x0400U)
#define GPIOC_BASEADDR			(AHB1PERIPH_BASE+0x0800U)
#define GPIOD_BASEADDR			(AHB1PERIPH_BASE+0x0C00U)
#define GPIOE_BASEADDR			(AHB1PERIPH_BASE+0x1000U)
#define GPIOF_BASEADDR			(AHB1PERIPH_BASE+0x1400U)
#define GPIOG_BASEADDR			(AHB1PERIPH_BASE+0x1800U)
#define GPIOH_BASEADDR			(AHB1PERIPH_BASE+0x1C00U)
#define RCC_BASEADDR			(AHB1PERIPH_BASE+0x3800)
//base addresses of periphirals hanging on APB1 bus
#define I2C1_BASEADDR			(APB1PERIPH_BASE+0x5400U)
#define I2C2_BASEADDR			(APB1PERIPH_BASE+0x5800U)
#define I2C3_BASEADDR			(APB1PERIPH_BASE+0x5C00U)

#define USART2_BASEADDR			(APB1PERIPH_BASE+0x4400)
#define USART3_BASEADDR			(APB1PERIPH_BASE+0x4800)
#define UART4_BASEADDR			(APB1PERIPH_BASE+0x4C00)
#define UART5_BASEADDR			(APB1PERIPH_BASE+0x5000)

#define SPI2_BASEADDR			(APB1PERIPH_BASE+0x3800)
#define SPI3_BASEADDR			(APB1PERIPH_BASE+0x3C00)
//base addresses of the peripherials hangig on the APB2 bus
#define EXTI_BASEADDR			(APB2PERIPH_BASE+0x3C00)
#define SPI1_BASEADDR			(APB2PERIPH_BASE+0x3000)
#define SYSCFG_BASEADDR			(APB2PERIPH_BASE+0x3800)

#define USART1_BASEADDR			(APB2PERIPH_BASE+0x1000)
#define USART6_BASEADDR			(APB2PERIPH_BASE+0x1400)

#define GPIOA 					((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB 					((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC 					((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 					((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE 					((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF 					((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG 					((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH 					((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC						((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI					((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG					((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1					((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2					((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3					((SPI_RegDef_t*)SPI3_BASEADDR)

//periphiral stuctures for SPI
typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;

}SPI_RegDef_t;

//peripheral register definition structures for GPIO
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDER;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_RegDef_t;
//peripheral register definitoin structure for RCC
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	uint32_t RESEREVD2;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	uint32_t RESERVED3[2];
	volatile uint32_t AHB1LPENER;
	volatile uint32_t AHB2LPENER;
	volatile uint32_t AHB3LPENER;
	uint32_t RESERVED4;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	uint32_t RESERVED5[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	uint32_t RESERVED6[2];
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t PLLSAICFGR;
	volatile uint32_t DCKCFGR;
	volatile uint32_t CKGATENR;
	volatile uint32_t CFGR2;

}RCC_RegDef_t;
//periphiral strucutre of EXTI register
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_RegDef_t;
//periphiral structuire for SYSCF
typedef struct
{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t RESERVED1[2];
	volatile uint32_t CMPCR;
	volatile uint32_t RESERVED2;
	volatile uint32_t CFGR;
}SYSCFG_RegDef_t;
//clock enablel macros for periphirals
#define GPIOA_PCLK_EN()		(RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN()		(RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN()		(RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1<<7))

#define I2C1_PCLK_EN()		(RCC->APB1ENR |=(1<<21))
#define I2C2_PCLK_EN()		(RCC->APB1ENR |=(1<<22))
#define I2C3_PCLK_EN()		(RCC->APB1ENR |=(1<<23))

#define SPI1_PCLK_EN()		(RCC->APB2ENR |=(1<<12))
#define SPI2_PCLK_EN()		(RCC->APB1ENR |=(1<<14))
#define SPI3_PCLK_EN()		(RCC->APB1ENR |=(1<<15))

#define USART2_PCLK_EN()		(RCC->APB1ENR |=(1<<17))
#define USART3_PCLK_EN()		(RCC->APB1ENR |=(1<<18))
#define UART4_PCLK_EN()		(RCC->APB1ENR |=(1<<19))
#define UART5_PCLK_EN()		(RCC->APB1ENR |=(1<<20))

#define SYSCFG_PCLK_EN()		(RCC->APB2ENR |=(1<<14))
//cllock disable macros for periphirals
#define GPIOA_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<7))

#define I2C1_PCLK_DI()		(RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DI()		(RCC->APB1ENR &= ~(1<<22))
#define I2C3_PCLK_DI()		(RCC->APB1ENR &= ~(1<<23))

#define SPI1_PCLK_DI()		(RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DI()		(RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DI()		(RCC->APB1ENR &= ~(1<<15))

#define USART2_PCLK_DI()		(RCC->APB1ENR &= ~(1<<17))
#define USART3_PCLK_DI()		(RCC->APB1ENR &= ~(1<<18))
#define UART4_PCLK_DI()		(RCC->APB1ENR &= ~(1<<19))
#define UART5_PCLK_DI()		(RCC->APB1ENR &= ~(1<<20))

#define SYSCFG_PCLK_DI()		(RCC->APB2ENR |=(1<<14))

//macros for reset registers
#define GPIOA_REG_RESET()		do {RCC->AHB1RSTR |=(1<<0); RCC->AHB1RSTR &= ~(1<<0);}while(0)
#define GPIOB_REG_RESET()		do {RCC->AHB1RSTR |=(1<<1); RCC->AHB1RSTR &= ~(1<<1);}while(0)
#define GPIOC_REG_RESET()		do {RCC->AHB1RSTR |=(1<<2); RCC->AHB1RSTR &= ~(1<<2);}while(0)
#define GPIOD_REG_RESET()		do {RCC->AHB1RSTR |=(1<<3); RCC->AHB1RSTR &= ~(1<<3);}while(0)
#define GPIOE_REG_RESET()		do {RCC->AHB1RSTR |=(1<<4); RCC->AHB1RSTR &= ~(1<<4);}while(0)
#define GPIOF_REG_RESET()		do {RCC->AHB1RSTR |=(1<<5); RCC->AHB1RSTR &= ~(1<<5);}while(0)
#define GPIOG_REG_RESET()		do {RCC->AHB1RSTR |=(1<<6); RCC->AHB1RSTR &= ~(1<<6);}while(0)
#define GPIOH_REG_RESET()		do {RCC->AHB1RSTR |=(1<<7); RCC->AHB1RSTR &= ~(1<<7);}while(0)
//MACROS FOR SPI RSET REGEISTERS
#define SPI1_REG_RESET()		do {RCC->APB2RSTR |=(1<<12); RCC->APB2RSTR &= ~(1<<12);}while(0)
#define SPI2_REG_RESET()		do {RCC->APB1RSTR |=(1<<14); RCC->APB1RSTR &= ~(1<<14);}while(0)
#define SPI3_REG_RESET()		do {RCC->APB1RSTR |=(1<<15); RCC->APB1RSTR &= ~(1<<15);}while(0)



#define GPIO_BASEADDR_TO_CODE(x)  	(x==GPIOA)? 0 :\
								  	(x==GPIOB)? 1 :\
									(x==GPIOC)? 2 :\
									(x==GPIOD)? 3 :\
									(x==GPIOE)? 4 :\
									(x==GPIOF)? 5 :\
									(x==GPIOG)? 6 :\
									(x==GPIOH)? 7 :0
//IRQ NUMBERS of the STff46RE
#define IRQ_NO_EXTI0 		6
#define IRQ_NO_EXTI1 		7
#define IRQ_NO_EXTI2 		8
#define IRQ_NO_EXTI3 		9
#define IRQ_NO_EXTI4 		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10	40

//some generic macros
#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET ENABLE
#define GPIO_PIN_RESET DISABLE
#define FLAG_RESET		RESET
#define FLA_SET			SET

#endif /* INC_STM32F446XX_H_ */

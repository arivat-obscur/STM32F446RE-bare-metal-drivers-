/*
 * stmf446rexx_spi_drivers.h
 *
 *  Created on: Aug 23, 2026
 *      Author: ariva
 */

#ifndef INC_STMF446REXX_SPI_DRIVERS_H_
#define INC_STMF446REXX_SPI_DRIVERS_H
#include "stm32f446xx.h"
typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPHA;
	uint8_t SPI_CPOL;
	uint8_t SPI_SSM;
}SPI_Config_t;
typedef struct
{
	SPI_RegDef_t *pSPIx;
	SPI_Config_t SPI_Config;
}SPI_Handle_t;
#define SPI_DEVICE_MODE_MASTER 1
#define SPI_DEVICE_MODE_SLAVE 0
//SPI_BUSCONFIG
#define SPI_BUS_CONFIG_FD					0
#define SPI_BUS_CONFIG_HD					1
#define SPI_BUS_CONFIG_SIMPLEX_TXONLY		2
//SPI_Clock speed
#define SPI_CLK_SPEED_DIV2					0
#define SPI_CLK_SPEED_DIV4					1
#define SPI_CLK_SPEED_DIV8					2
#define SPI_CLK_SPEED_DIV16					3
#define SPI_CLK_SPEED_DIV32					4
#define SPI_CLK_SPEED_DIV64					5
#define SPI_CLK_SPEED_DIV128				6
#define SPI_CLK_SPEED_DIV256				7
//SPI DFF
#define SPI_DFF_8BITS     0
#define SPI_DFF_16BITS    1
//SPI CPHA AND CPOL
#define SPI_CPHA_HIGH 	  0
#define SPI_CPHA_LOW      1
#define SPI_CPOL_HIGH	  0
#define SPI_CPOL_LOW	  1
//SPI SSM
#define SPI_SSM_EN		1
#define SPI_SSM_DI		0
//SPI periphiral clock control
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);
//Init and Deinit
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);
//data send and recieve
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer,uint32_t Len);
void SPI_RecieveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer,uint32_t Len);
//IRQ configuration and ISR handling
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumebr,uint8_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);

//MACROS FOR SPI REGISTERS
#define SPI_CR1_CPHA 		0
#define SPI_CR1_CPOL		1
#define SPI_CR1_MSTR		2
#define SPI_CR1_BR			3
#define SPI_CR1_SPE			6
#define SPI_CR1_LSBFIRST	7
#define SPI_CR1_SSI			8
#define SPI_CR1_SSM			9
#define SPI_CR1_RXONLY		10
#define SPI_CR1_DFF			11
#define SPI_CR1_CRCNEXT		12
#define SPI_CR1_CRCEN		13
#define SPI_CR1_BIDIOE		14
#define SPI_CR1_BIDIMODE	15
//STATUS REGISTER
#define SPI_SR_RXNE			0
#define SPI_SR_TXE			1
#define SPI_SR_CHSIDE		2
#define SPI_SR_UDR			3
#define SPI_SR_CRCERR		4
#define SPI_SR_MODF			5
#define SPI_SR_OVR			6
#define SPI_SR_BSY			7
#define SPI_SR_FRE			8

#define SPI_TXE_FLAG 		(1 << SPI_SR_TXE)
#define SPI_RXNE_FLAG 		(1<<SPI_SR_RXNE)
#define SPI_BUSY_FLAG		(1<<SPI_SR_BUSY)
#endif /* INC_STMF446REXX_SPI_DRIVERS_H_ */

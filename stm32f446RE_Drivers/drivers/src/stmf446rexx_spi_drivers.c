/*
 * stmf446rexx_spi_drivers.c
 *
 *  Created on: Aug 23, 2026
 *      Author: ariva
 */

#include <stdint.h>
#include "stmf446rexx_spi_drivers.h"
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
	{
		if(EnorDi==ENABLE)
			{
				if(pSPIx==SPI1)
				{
					SPI1_PCLK_EN();
				}
				else if(pSPIx==SPI2)
				{
					SPI2_PCLK_EN();
				}
				else if(pSPIx==SPI3)
				{
					SPI3_PCLK_EN();
				}

			}
		else
			if(pSPIx==SPI1)
			{
				SPI1_PCLK_DI();
			}
			else if(pSPIx==SPI2)
			{
				SPI2_PCLK_DI();
			}
			else if(pSPIx==SPI3)
			{
				SPI3_PCLK_DI();
			}
	}
	//Init and Deinit
void SPI_Init(SPI_Handle_t *pSPIHandle)
	{
	SPI_PeriClockControl(pSPIHandle->pSPIx, ENABLE);
	uint32_t tempreg=0;
//	confiuring the device mode
	tempreg |= pSPIHandle->SPI_Config.SPI_DeviceMode<<SPI_CR1_MSTR;
//	configuring the BUs
	if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		tempreg &= ~(1<< SPI_CR1_BIDIMODE);
	}else if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_HD)
		tempreg |= (1<< SPI_CR1_BIDIMODE);
	else if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_TXONLY)
	{
		tempreg &= ~(1<<SPI_CR1_BIDIMODE);
		tempreg |= (1<<SPI_CR1_RXONLY);
	}
//	cinfguring the clock speeed
	tempreg|= pSPIHandle->SPI_Config.SPI_SclkSpeed<<SPI_CR1_BR;
//	configure the DFF
	tempreg |= pSPIHandle->SPI_Config.SPI_DFF<<SPI_CR1_DFF;
//	configure COPL
	tempreg |= pSPIHandle->SPI_Config.SPI_CPOL<<SPI_CR1_CPOL;
//	configure the CPHA
	tempreg |= pSPIHandle->SPI_Config.SPI_CPHA<<SPI_CR1_CPHA;
	pSPIHandle->pSPIx->CR1 = tempreg;

	}
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx,uint32_t FlagName)
{
	if(pSPIx->SR & FlagName)
	return FLAG_RESET;
}

void SPI_DeInit(SPI_RegDef_t *pSPIx)
	{
	if(pSPIx==SPI1)
		{
			SPI1_REG_RESET();
		}
		else if(pSPIx==SPI2)
		{
			SPI2_REG_RESET();
		}
		else if(pSPIx==SPI3)
		{
			SPI3_REG_RESET();
		}
	}
	//data send and recieve
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer,uint32_t Len)
	{
	while(Len)
	{
		while(SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG)== FLAG_RESET)
		{
			if(pSPIx->CR1 && (1<< SPI_CR1_DFF))
			{
//				16 bit data format
				pSPIx->DR=*((uint16_t*)pTxBuffer);
				Len--;
				Len--;
				(uint16_t*)pTxBuffer++;
			}
			else
			{
//				8 bit data format
				pSPIx->DR=*(pTxBuffer);
				Len--;
				pTxBuffer++;
			}
	}
	}
	}
void SPI_RecieveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer,uint32_t Len)
	{
	while(Len)
	{
		while(SPI_GetFlagStatus(pSPIx, SPI_RXNE_FLAG)== FLAG_RESET)
		{
			if(pSPIx->CR1 && (1<< SPI_CR1_DFF))
			{
//				16 bit data format
				*((uint16_t*)pRxBuffer)=pSPIx->DR;
				Len--;
				Len--;
				(uint16_t*)pRxBuffer++;
			}
			else
			{
//				8 bit data format
				*(pRxBuffer)=pSPIx->DR;
				Len--;
				pRxBuffer++;
			}
	}
	}
	}
	//IRQ configuration and ISR handling
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
	{

	}
void SPI_IRQPriorityConfig(uint8_t IRQNumebr,uint8_t IRQPriority)
	{

	}
void SPI_PeriphiralControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi)
{
	if (EnOrDi == ENABLE)
	{
		pSPIx->CR1 |= (1<<SPI_CR1_SPE);
	}
	else
	{
		pSPIx->CR1 &= ~(1<<SPI_CR1_SPE);
	}
}



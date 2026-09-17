/*
 * SPI_main.c
 *
 *  Created on: Sep 4, 2026
 *      Author: ariva
 */
//
//PB15-->mosi
//PB13-->SCK
//ALT FUNCTION MODE 5
#include <string.h>
#include "stmf446rexx_gpio_driver.h"
#include "stmf446rexx_spi_drivers.h"]
void SPI2_GPIOInits(void)
{
	GPIO_Handle_t SPI_pins;
	SPI_pins.pGPIOx =GPIOB;
	SPI_pins.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_ALTFN;
	SPI_pins.GPIO_PinConfig.GPIO_PinAltFunMode=5;
	SPI_pins.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
	SPI_pins.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;
	SPI_pins.GPIO_PinConfig.GPIO_Pinspeed=GPIO_SPEED_FAST;

//	pin configuration for MISO
	SPI_pins.GPIO_PinConfig.GPIO_PinNumber=15;
	GPIO_Init(&SPI_pins);
//	pin configuration for SCK
	SPI_pins.GPIO_PinConfig.GPIO_PinNumber=13;
	GPIO_Init(&SPI_pins);
////	pin configuration for MOSI
//	SPI_pins.GPIO_PinConfig.GPIO_PinNumber=14;
//	GPIO_Init(&SPI_pins);
////	pin configuration for NSS
//	SPI_pins.GPIO_PinConfig.GPIO_PinNumber=12;
//	GPIO_Init(&SPI_pins);

}
void SPI2_Inits(void)
{
	SPI_Handle_t SPI_pins;
	SPI_pins.pSPIx=SPI2;
	SPI_pins.SPI_Config.SPI_BusConfig=SPI_BUS_CONFIG_FD;
	SPI_pins.SPI_Config.SPI_DeviceMode=SPI_DEVICE_MODE_MASTER;
	SPI_pins.SPI_Config.SPI_SclkSpeed=SPI_CLK_SPEED_DIV2;
	SPI_pins.SPI_Config.SPI_DFF=SPI_DFF_16BITS;
	SPI_pins.SPI_Config.SPI_CPHA=SPI_CPHA_LOW;
	SPI_pins.SPI_Config.SPI_CPOL=SPI_CPOL_LOW;
	SPI_pins.SPI_Config.SPI_SSM=SPI_SSM_EN;

	SPI_Init(&SPI_pins);
}
int main(void)
{
	char user_data[]="hello gng";
	SPI2_GPIOInits();
	SPI2_Inits();
	SPI_PeriphiralControl(SPI2, ENABLE);
	SPI_SendData(SPI2, user_data, strlen(user_data));
	while(1);
	return 0;
}

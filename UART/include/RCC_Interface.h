/************************************/
/*        Author:  Eslam 			*/
/*        Date:    09/05/2023		*/
/*        Version: 1.1				*/
/************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#include "STD_TYPES.h"
#include "BIT_MATH.h"

typedef enum
{
	HSE_ON,
	HSI_ON,
	PLL_ON,
	HSE_HSI,
	HSE_PLL,
	HSI_PLL,
	HSE_HSI_PLL,
	/*CSS_ON_HSE_ON,
	CSS_ON_HSI_ON,
	CSS_ON_PLL_ON,
	CSS_ON_HSE_HSI,
	CSS_ON_HSE_PLL,
	CSS_ON_HSI_PLL,
	CSS_ON_HSE_HSI_PLL*/
	
}Clock_Enable;

typedef enum
{
	HSI_Clock,
	HSE_Clock,
	PLL_Clock
	
}System_Clock;

typedef enum 
{
	HSE_RC,
	HSE_CRYSTAL,
	
}HSE_OSC_Type;

typedef enum
{
	
	GPIOA_ID = 0 ,
	GPIOB_ID     ,
	GPIOC_ID     ,
	GPIOD_ID     ,
	GPIOE_ID     ,
	GPIOH_ID = 7 ,
	CRC_ID   = 12,
	DMA1_ID  = 21,
	DMA2_ID  = 22,
	OTGFS_ID = 7 ,
	TIM5_ID  = 3 ,
	TIM4_ID  = 2 ,
	TIM3_ID  = 1 ,
	TIM2_ID  = 0 ,
	WWDG_ID  = 11,
	SPI2_ID  = 14,
	SPI3_ID  = 15,
	USART2_ID= 17,
	I2C1_ID  = 21,
	I2C2_ID  = 22,
	I2C3_ID  = 23,
	PWREN    = 28,
	TIM1_ID  = 0 ,
	USART1_ID= 4 ,
	USART6_ID= 5 ,
	ADC1_ID  = 8 ,
	SDIO_ID  = 11,
	SPI1_ID  = 12,
	SPI4_ID  = 13,
	SYSCFG_ID= 14,
	TIM9_ID  = 16,
	TIM10_ID = 17,
	TIM11_ID = 18,
	
}Perph_Enable;

typedef enum
{
	AHB1,
	AHB2,
	APB1,
	APB2,

}bus_Type;

typedef enum
{
	BIT_HSION  = 0,
	BIT_HSIRDY ,
	BIT_HSEON  = 16,
	BIT_HSERDY ,
	BIT_HSEBYP ,
	BIT_CSSON  ,
	BIT_PLLON  = 24,
	BIT_PLLRDY = 25,

}CR_PINS;

typedef enum
{
	BIT_SW0 = 0,
	BIT_SW1  ,
	BIT_SWS0 ,
	BIT_SWS1 ,

}RCC_CFGR;


typedef enum
{
	Disable,
	Enable

}State;


typedef struct 
{
	Clock_Enable ClockEnable ;
	System_Clock SystemClock ;
	HSE_OSC_Type HSEOCSTYPE ;

}RCCModes;


void MRCC_voidInitSysClock(RCCModes * Mode);
void RCC_voidEnableClockForPripheral(bus_Type Copy_u8BusId, uint8 Copy_u8PerId);
void RCC_voidDisableClockForPripheral(bus_Type Copy_u8BusId, uint8 Copy_u8PerId);

#endif

/************************************/
/*        Author:  Eslam 			*/
/*        Date:    09/05/2023		*/
/*        Version: 1.1				*/
/************************************/



#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"


void MRCC_voidInitSysClock(RCCModes * Mode)
{
	/*this switch enable the system clock we may need in the runtime */
	switch(Mode->ClockEnable)
	{
		case HSE_ON :
				SET_BIT(RCC->RCC_CR , BIT_HSEON);
				CLR_BIT(RCC->RCC_CR , BIT_PLLON);
				CLR_BIT(RCC->RCC_CR , BIT_HSION);
				while( !GET_BIT(RCC->RCC_CR,BIT_HSERDY) );
				switch(Mode->HSEOCSTYPE)
				{
					case HSE_RC :
					  SET_BIT(RCC->RCC_CR , BIT_HSEBYP);
					  break;
					case HSE_CRYSTAL :
					  CLR_BIT(RCC->RCC_CR , BIT_HSEBYP);
					  break;
				}
			break;
			
		case HSI_ON :
				SET_BIT(RCC->RCC_CR , BIT_HSION);
				CLR_BIT(RCC->RCC_CR , BIT_PLLON);
				CLR_BIT(RCC->RCC_CR , BIT_HSEON);		
				while( !GET_BIT(RCC->RCC_CR,BIT_HSIRDY) );				
			break;
			
		case PLL_ON :
				SET_BIT(RCC->RCC_CR , BIT_PLLON);
				CLR_BIT(RCC->RCC_CR , BIT_HSEON);
				CLR_BIT(RCC->RCC_CR , BIT_HSION);
				while( !GET_BIT(RCC->RCC_CR,BIT_PLLRDY) );
			break;
			
		case HSE_HSI :
				SET_BIT(RCC->RCC_CR , BIT_HSION);
				SET_BIT(RCC->RCC_CR , BIT_HSEON);
				CLR_BIT(RCC->RCC_CR , BIT_PLLON);
				while( !GET_BIT(RCC->RCC_CR,BIT_HSERDY) && !GET_BIT(RCC->RCC_CR,BIT_HSIRDY) );
			break;
			
		case HSE_PLL :
				SET_BIT(RCC->RCC_CR , BIT_HSEON);
				SET_BIT(RCC->RCC_CR , BIT_PLLON);
				CLR_BIT(RCC->RCC_CR , BIT_HSION);
				while( !GET_BIT(RCC->RCC_CR,BIT_HSERDY) && !GET_BIT(RCC->RCC_CR,BIT_PLLRDY) );
			break;
			
		case HSI_PLL :
				SET_BIT(RCC->RCC_CR , BIT_HSION);
				SET_BIT(RCC->RCC_CR , BIT_PLLON);
				CLR_BIT(RCC->RCC_CR , BIT_HSEON);
				while( !GET_BIT(RCC->RCC_CR,BIT_PLLRDY) && !GET_BIT(RCC->RCC_CR,BIT_HSIRDY) );
			break;
			
		case HSE_HSI_PLL :
				SET_BIT(RCC->RCC_CR , BIT_HSION);
				SET_BIT(RCC->RCC_CR , BIT_HSEON);
				SET_BIT(RCC->RCC_CR , BIT_PLLON);
				while( !GET_BIT(RCC->RCC_CR,BIT_HSERDY) && !GET_BIT(RCC->RCC_CR,BIT_HSIRDY) && !GET_BIT(RCC->RCC_CR,BIT_PLLRDY)  );
			break;
			
	}
    
	switch(Mode->SystemClock)
	{
		case HSI_Clock :
				CLR_BIT(RCC->RCC_CFGR , BIT_SW0);
				CLR_BIT(RCC->RCC_CFGR , BIT_SW1);
			break;
			
		case HSE_Clock :
				SET_BIT(RCC->RCC_CFGR , BIT_SW0);
				CLR_BIT(RCC->RCC_CFGR , BIT_SW1);
			break;
			
		case PLL_Clock :
				CLR_BIT(RCC->RCC_CFGR , BIT_SW0);
				SET_BIT(RCC->RCC_CFGR , BIT_SW1);
			break;
	}



}

void RCC_voidEnableClockForPripheral(bus_Type Copy_u8BusId, uint8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case AHB1 :
			 SET_BIT(RCC->RCC_AHB1ENR , Copy_u8PerId);
			break;
			case AHB2 :
			 SET_BIT(RCC->RCC_AHB2ENR , Copy_u8PerId);
			break;
			case APB1 :
			 SET_BIT(RCC->RCC_APB1ENR , Copy_u8PerId);
			break;
			case APB2 :
             SET_BIT(RCC->RCC_APB2ENR , Copy_u8PerId);
			break;
		}
	}
}

void RCC_voidDisableClockForPripheral(bus_Type Copy_u8BusId, uint8 Copy_u8PerId)
{
		if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case AHB1 :
			 CLR_BIT(RCC->RCC_AHB1ENR , Copy_u8PerId);
			break;
			case AHB2 :
			 CLR_BIT(RCC->RCC_AHB2ENR , Copy_u8PerId);
			break;
			case APB1 :
			 CLR_BIT(RCC->RCC_APB1ENR , Copy_u8PerId);
			break;
			case APB2 :
             CLR_BIT(RCC->RCC_APB2ENR , Copy_u8PerId);
			break;
		}
	}
}

/************************************/
/*        Author:  Eslam 			*/
/*        Date:    01/06/2023		*/
/*        Version: 1.1				*/
/************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Private.h"
#include "DIO_interface.h"


void DIO_PinConfig(DIO_Configuration * config)
{
	switch(config->PORT)
	{
		case PORTA:
			  // select input state from MODER regsiter (input - output - analog - AF)
				switch(config->PINModes)
				{
				  case Input: 
						CLR_BIT(GPIOA->MODER , (config->Pins * 2));
						CLR_BIT(GPIOA->MODER , ((config->Pins * 2) + 1) );
						//if input select the type of the input mode to the pin 
						switch(config->PIN_INPUT_MODE)
						{
						case INPUT_NO_MODE:
							CLR_BIT(GPIOA->PUPDR , (config->Pins * 2));
							CLR_BIT(GPIOA->PUPDR , ((config->Pins * 2) + 1) );
							break;
						case INPUT_PULL_UP:
							SET_BIT(GPIOA->PUPDR , (config->Pins * 2));
							CLR_BIT(GPIOA->PUPDR , ((config->Pins * 2) + 1) );
							break;
						case INPUT_PULL_DOWN:
							CLR_BIT(GPIOA->PUPDR , (config->Pins * 2));
							SET_BIT(GPIOA->PUPDR , ((config->Pins * 2) + 1) );
							break;						
						}
					break;
						
				case Output:
						SET_BIT(GPIOA->MODER , (config->Pins * 2));
						CLR_BIT(GPIOA->MODER , ((config->Pins * 2) + 1) );
						//if output select the output mode of the pin 
						switch(config->PIN_OUTPUT_MODE)
						{
						case OUTPUT_PUSH_PULL:
							CLR_BIT(GPIOA->OTYPE , config->Pins);
							break;
						case OUTPUT_OPEN_DRAIN:
							SET_BIT(GPIOA->OTYPE , config->Pins);
							break;					
						}
					break;
					
				case Analog:
						SET_BIT(GPIOA->MODER , (config->Pins * 2));
						SET_BIT(GPIOA->MODER , ((config->Pins * 2) + 1) );
					break;
					
				case Alternate_Function:
						CLR_BIT(GPIOA->MODER , (config->Pins * 2));
						SET_BIT(GPIOA->MODER , ((config->Pins * 2) + 1) );
					break;					
				}

				switch(config->Pin_SPEED)
				{
					case Low_speed:
							CLR_BIT(GPIOA->OSPEEDR , (config->Pins * 2));
							CLR_BIT(GPIOA->OSPEEDR , ((config->Pins * 2) + 1) );
						break;
						
					case Medium_speed:
							SET_BIT(GPIOA->OSPEEDR , (config->Pins * 2));
							CLR_BIT(GPIOA->OSPEEDR , ((config->Pins * 2) + 1) );
						break;

					case High_speed:
							CLR_BIT(GPIOA->OSPEEDR , (config->Pins * 2));
							SET_BIT(GPIOA->OSPEEDR , ((config->Pins * 2) + 1) );
						break;

					case Very_high_speed:
							SET_BIT(GPIOA->OSPEEDR , (config->Pins * 2));
							SET_BIT(GPIOA->OSPEEDR , ((config->Pins * 2) + 1) );
						break;			
				}

		break;

		case PORTB:
		  if( config->Pins != PIN11)
		  {
				// select input state from MODER regsiter (input - output - analog - AF)
				switch(config->PINModes)
				{
				  case Input: 
						CLR_BIT(GPIOB->MODER , (config->Pins * 2));
						CLR_BIT(GPIOB->MODER , ((config->Pins * 2) + 1) );
						//if input select the type of the input mode to the pin 
						switch(config->PIN_INPUT_MODE)
						{
						case INPUT_NO_MODE:
							CLR_BIT(GPIOB->PUPDR , (config->Pins * 2));
							CLR_BIT(GPIOB->PUPDR , ((config->Pins * 2) + 1) );
							break;
						case INPUT_PULL_UP:
							SET_BIT(GPIOB->PUPDR , (config->Pins * 2));
							CLR_BIT(GPIOB->PUPDR , ((config->Pins * 2) + 1) );
							break;
						case INPUT_PULL_DOWN:
							CLR_BIT(GPIOB->PUPDR , (config->Pins * 2));
							SET_BIT(GPIOB->PUPDR , ((config->Pins * 2) + 1) );
							break;						
						}
					break;
						
				case Output:
						SET_BIT(GPIOB->MODER , (config->Pins * 2));
						CLR_BIT(GPIOB->MODER , ((config->Pins * 2) + 1) );
						//if output select the output mode of the pin 
						switch(config->PIN_OUTPUT_MODE)
						{
						case OUTPUT_PUSH_PULL:
							CLR_BIT(GPIOB->OTYPE , config->Pins);
							break;
						case OUTPUT_OPEN_DRAIN:
							SET_BIT(GPIOB->OTYPE , config->Pins);
							break;					
						}
					break;
					
				case Analog:
						SET_BIT(GPIOB->MODER , (config->Pins * 2));
						SET_BIT(GPIOB->MODER , ((config->Pins * 2) + 1) );
					break;
					
				case Alternate_Function:
						CLR_BIT(GPIOB->MODER , (config->Pins * 2));
						SET_BIT(GPIOB->MODER , ((config->Pins * 2) + 1) );
					break;					
				}

				switch(config->Pin_SPEED)
				{
					case Low_speed:
							CLR_BIT(GPIOB->OSPEEDR , (config->Pins * 2));
							CLR_BIT(GPIOB->OSPEEDR , ((config->Pins * 2) + 1) );
						break;
						
					case Medium_speed:
							SET_BIT(GPIOB->OSPEEDR , (config->Pins * 2));
							CLR_BIT(GPIOB->OSPEEDR , ((config->Pins * 2) + 1) );
						break;

					case High_speed:
							CLR_BIT(GPIOB->OSPEEDR , (config->Pins * 2));
							SET_BIT(GPIOB->OSPEEDR , ((config->Pins * 2) + 1) );
						break;

					case Very_high_speed:
							SET_BIT(GPIOB->OSPEEDR , (config->Pins * 2));
							SET_BIT(GPIOB->OSPEEDR , ((config->Pins * 2) + 1) );
						break;			
				}
					  
		 }
		  else 
		  {
			  //#error Pin Not Found in this port
		  }
		break;	

		case PORTC:
		  if(config->Pins >= 13 && config->Pins <= 15)
		  {
				// select input state from MODER regsiter (input - output - analog - AF)
				switch(config->PINModes)
				{
				  case Input: 
						CLR_BIT(GPIOC->MODER , (config->Pins * 2));
						CLR_BIT(GPIOC->MODER , ((config->Pins * 2) + 1) );
						//if input select the type of the input mode to the pin 
						switch(config->PIN_INPUT_MODE)
						{
						case INPUT_NO_MODE:
							CLR_BIT(GPIOC->PUPDR , (config->Pins * 2));
							CLR_BIT(GPIOC->PUPDR , ((config->Pins * 2) + 1) );
							break;
						case INPUT_PULL_UP:
							SET_BIT(GPIOC->PUPDR , (config->Pins * 2));
							CLR_BIT(GPIOC->PUPDR , ((config->Pins * 2) + 1) );
							break;
						case INPUT_PULL_DOWN:
							CLR_BIT(GPIOC->PUPDR , (config->Pins * 2));
							SET_BIT(GPIOC->PUPDR , ((config->Pins * 2) + 1) );
							break;						
						}
					break;
						
				case Output:
						SET_BIT(GPIOC->MODER , (config->Pins * 2));
						CLR_BIT(GPIOC->MODER , ((config->Pins * 2) + 1) );
						//if output select the output mode of the pin 
						switch(config->PIN_OUTPUT_MODE)
						{
						case OUTPUT_PUSH_PULL:
							CLR_BIT(GPIOC->OTYPE , config->Pins);
							break;
						case OUTPUT_OPEN_DRAIN:
							SET_BIT(GPIOC->OTYPE , config->Pins);
							break;					
						}
					break;
					
				case Analog:
						SET_BIT(GPIOC->MODER , (config->Pins * 2));
						SET_BIT(GPIOC->MODER , ((config->Pins * 2) + 1) );
					break;
					
				case Alternate_Function:
						CLR_BIT(GPIOC->MODER , (config->Pins * 2));
						SET_BIT(GPIOC->MODER , ((config->Pins * 2) + 1) );
					break;					
				}

				switch(config->Pin_SPEED)
				{
					case Low_speed:
							CLR_BIT(GPIOC->OSPEEDR , (config->Pins * 2));
							CLR_BIT(GPIOC->OSPEEDR , ((config->Pins * 2) + 1) );
						break;
						
					case Medium_speed:
							SET_BIT(GPIOC->OSPEEDR , (config->Pins * 2));
							CLR_BIT(GPIOC->OSPEEDR , ((config->Pins * 2) + 1) );
						break;

					case High_speed:
							CLR_BIT(GPIOC->OSPEEDR , (config->Pins * 2));
							SET_BIT(GPIOC->OSPEEDR , ((config->Pins * 2) + 1) );
						break;

					case Very_high_speed:
							SET_BIT(GPIOC->OSPEEDR , (config->Pins * 2));
							SET_BIT(GPIOC->OSPEEDR , ((config->Pins * 2) + 1) );
						break;			
				}
					  
		  }
		  else 
		  {
			  //#error Pin Not Found in this port
		  }
		break;			
		
	}



}

void DIO_SETPinVal(PORTS Port , PINS Pin , Pin_State State)
{
	switch(Port)
	{
		case PORTA:
				switch(State)
				{
					case HIGH:
					 SET_BIT(GPIOA->ODR , Pin);
					break;
					case LOW:
					 CLR_BIT(GPIOA->ODR , Pin);	
					break;					 
				}

			break;
			
		case PORTB:
			if(Pin != PIN11)
			{
				switch(State)
				{
					case HIGH:
					 SET_BIT(GPIOB->ODR , Pin);
					break;
					case LOW:
					 CLR_BIT(GPIOB->ODR , Pin);	
					break;					 
				}
			}
			else 
			{
				//#error Pin not found in this port
			}
			break;	

		case PORTC:
			if(Pin<=PIN15 && Pin>=PIN13)
			{
				switch(State)
				{
					case HIGH:
					 SET_BIT(GPIOC->ODR , Pin);
					break;
					case LOW:
					 CLR_BIT(GPIOC->ODR , Pin);	
					break;					 
				}
			}
			else 
			{
				//#error Pin not found in this port
			}
			break;				
	}

}

uint8 DIO_GETPinVal(PORTS Port , PINS Pin)
{
	uint8 PinVal = 0 ;
	switch(Port)
	{
		case PORTA:
				PinVal = GET_BIT(GPIOA->IDR , Pin);
			break;
			
		case PORTB:
			if(Pin != PIN11)
			{
				PinVal = GET_BIT(GPIOB->IDR , Pin);
			}
			else 
			{
				//#error Pin not found in this port
			}
			break;	

		case PORTC:
			if(Pin<=PIN15 && Pin>=PIN13)
			{
				PinVal = GET_BIT(GPIOC->IDR , Pin);
			}
			else 
			{
				//#error Pin not found in this port
			}
			break;				
	}	

return PinVal;
}

void MGPIO_voidSetPinAltFun(PORTS Copy_u8PortName ,uint8 Copy_u8PinNum, PIN_AF Copy_u8AlFun)
{
	if(Copy_u8PinNum <=7U)
	{
		switch(Copy_u8PortName)
		{
		case PORTA:GPIOA->ARF[0]   |=(uint32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		case PORTB:GPIOB->ARF[0]   |=(uint32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		case PORTC:GPIOC->ARF[0]   |=(uint32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		default : break ;
		}
	}
	else
	{
		switch(Copy_u8PortName)
		{
		case PORTA:GPIOA->ARF[1]   |=(uint32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		case PORTB:GPIOB->ARF[1]   |=(uint32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		case PORTC:GPIOC->ARF[1]   |=(uint32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		default : break ;
		}

	}
}

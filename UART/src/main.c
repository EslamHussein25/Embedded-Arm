#include "RCC_interface.h"
#include "UART_interface.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"




int main(void)
{
	RCCModes * rccmode = NULL;
	rccmode->ClockEnable = HSI_ON ;
	rccmode->SystemClock = HSI_Clock ;
	MRCC_voidInitSysClock(rccmode);

	RCC_voidEnableClockForPripheral(APB2 , USART1_ID);
	RCC_voidEnableClockForPripheral(AHB1 , GPIOA_ID); // FOR GPIO
	RCC_voidEnableClockForPripheral(AHB1 , GPIOC_ID); // FOR GPIO

	MGPIO_voidSetPinAltFun(PORTA , 9 , AF7); // TX
	MGPIO_voidSetPinAltFun(PORTA , 10 , AF7); // RX

	UARTConfig Conf ;
	Conf.BaudRate = _9600 ;
	Conf.OverSamplingMode = OverSample_16 ;
	Conf.UART_Mode = PeerToPeer;
	Conf.UART_Selection = UART1 ;
	Conf.USART_Control = USART_Enable ;
	Conf.WordLength = _8_bit ;
	Conf.Parity_Control = Parity_disable ;
	Conf.TxControl = Tx_enable ;
	Conf.RxControl = Rx_enable ;
	UART_Init(Conf);

	DIO_Configuration Config9 ;
	Config9.PINModes = Alternate_Function ;
	Config9.Pin_SPEED = Very_high_speed ;
	Config9.PORT = PORTA ;
	Config9.Pins = 9 ;
	DIO_PinConfig(&Config9);

	DIO_Configuration Config10 ;
	Config10.PINModes = Alternate_Function ;
	Config10.Pin_SPEED = Very_high_speed ;
	Config10.PORT = PORTA ;
	Config10.Pins = 10 ;
	DIO_PinConfig(&Config10);

	DIO_Configuration Config ;
	Config.PINModes = Output ;
	Config.PIN_OUTPUT_MODE = OUTPUT_PUSH_PULL ;
	Config.Pin_SPEED = Low_speed ;
	Config.PORT = PORTC ;
	Config.Pins = 13 ;
	DIO_PinConfig(&Config);


			UART_SendString("AT+CMGF=1\r" , UART1);
			UART_SendString("AT+CMGS=\"+201091728114\"\r" , UART1);
			  for(int count = 0 ;  count <= 10000 ; count++)
			  {
				  for(int count2 = 0 ; count2 <= 10000 ; count2++)
				  {

				  }
			  }
			UART_SendString("Hello" , UART1);
			  for(int count = 0 ;  count <= 1000 ; count++)
				  {
					  for(int count2 = 0 ; count2 <= 1000 ; count2++)
					  {

					  }
				  }

			  UART_Send((char)26 , UART1);
			  for(int count = 0 ;  count <= 10000 ; count++)
				  {
					  for(int count2 = 0 ; count2 <= 10000 ; count2++)
					  {

					  }
				  }
while (1)
  {

	  DIO_SETPinVal(PORTC , 13 , HIGH);
	  for(int count = 0 ;  count <= 1000 ; count++)
	  {
		  for(int count2 = 0 ; count2 <= 1000 ; count2++)
		  {

		  }
	  }
	  UART_SendString("AT\r" , UART1);

	  StringData = UART_ReceiveStringUntil('K', UART1);
	  UART_SendString(StringData, UART1);

	  DIO_SETPinVal(PORTC , 13 , LOW);
	  for(int count = 0 ;  count <= 1000 ; count++)
	  {
		  for(int count2 = 0 ; count2 <= 1000 ; count2++)
		  {

		  }
	  }
  }




	return 0 ;
}


/*MGPIO_voidSetPinAltFun(PORTA , 9 , AF7);
	MGPIO_voidSetPinAltFun(PORTA , 10 , AF7);


	UARTConfig Conf ;
	Conf.BaudRate = _9600 ;
	Conf.OverSamplingMode = OverSample_8 ;
	Conf.UART_Mode = PeerToPeer;
	Conf.UART_Selection = UART1 ;
	Conf.USART_Control = USART_Enable ;
	Conf.WordLength = _8_bit ;
	UART_Init(Conf);*/

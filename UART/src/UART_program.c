/********************************************************/
/*		Author  : Eslam							        */
/*		Date    : 09/10/2023    						*/
/*		Version : 1.1									*/
/********************************************************/


#include "UART_interface.h"

char NULLPTR = 0 ;
char * StringData = &NULLPTR;
uint16 BufferSize = 0 ;

void WritePin(_UART_Selection UART_Selection , uint32  Reg , uint8 Pin , uint8 Val)
{
    UART_REG * UART = SelectUART(UART_Selection) ;
	switch (Reg)
	{
	case 1 :
		switch(Val)
		{
			case 0 :
				CLR_BIT(UART->USART_CR1  , Pin);
			break;

			case 1 :
				SET_BIT(UART->USART_CR1  , Pin);
			break;
		}
	break ;

	case 2 :
		switch(Val)
		{
			case 0 :
				CLR_BIT(UART->USART_CR2  , Pin);
			break;

			case 1 :
				SET_BIT(UART->USART_CR2  , Pin);
			break;
		}
	break ;

	case 3 :
		switch(Val)
		{
			case 0 :
				CLR_BIT(UART->USART_CR3  , Pin);
			break;

			case 1 :
				SET_BIT(UART->USART_CR3  , Pin);
			break;
		}
	break ;
	}

}

UART_REG * SelectUART(_UART_Selection UART_Selection)
{
	UART_REG * UART = NULL;

	switch(UART_Selection)
	{
		case UART1 :
			UART = (UART_REG*)UART1_BASE_ADD ;
		break;

		case UART2 :
			UART = (UART_REG*)UART2_BASE_ADD ;
		break;

		case UART6 :
			UART = (UART_REG*)UART6_BASE_ADD ;
		break;
	}

	return UART ;
}

void UART_Init(UARTConfig Config)
{

     UART_REG * UART = SelectUART(Config.UART_Selection) ;


	switch(Config.USART_Control)
	{
		case USART_Disable :
			CLR_BIT(UART->USART_CR1 , 13);
			return ;
		case USART_Enable  :
			SET_BIT(UART->USART_CR1 , 13);
	}

	   WritePin(Config.UART_Selection , 1 , 15 , Config.OverSamplingMode);
	   WritePin(Config.UART_Selection , 1 , 12 , Config.WordLength);
	   WritePin(Config.UART_Selection , 1 , 11 , Config.WakeUp);
	   WritePin(Config.UART_Selection , 1 , 10 , Config.Parity_Control);
	   WritePin(Config.UART_Selection , 1 ,  9 , Config.Parity_selection);
	   WritePin(Config.UART_Selection , 1 ,  3 , Config.TxControl);
	   WritePin(Config.UART_Selection , 1 ,  2 , Config.RxControl);

   WritePin(Config.UART_Selection , 2 ,  14 , Config.LINMode);

   	switch(Config.StopBits)
	{
		case _1_Stop :
			CLR_BIT(UART->USART_CR2 , 12);
			CLR_BIT(UART->USART_CR2 , 13);
		break;
		case _Hlaf_Stop  :
			CLR_BIT(UART->USART_CR2 , 12);
			SET_BIT(UART->USART_CR2 , 13);
		break;
		case _1_5_Stop :
			SET_BIT(UART->USART_CR2 , 12);
			CLR_BIT(UART->USART_CR2 , 13);
		break;
		case _2_Stop  :
			SET_BIT(UART->USART_CR2 , 12);
			SET_BIT(UART->USART_CR2 , 13);
		break;
	}

	if(Config.UART_Mode)
	{
	   WritePin( Config.UART_Selection , 2 ,  11 , Config.Clock_Enable);
	   WritePin( Config.UART_Selection , 2 ,  10 , Config.ClockPolarity);
	   WritePin( Config.UART_Selection , 2 ,   9 , Config.ClockPhase);
	}

	WritePin( Config.UART_Selection, 3 , 7 , Config.DMA_Transmission_Control);
	WritePin( Config.UART_Selection, 3 , 6 , Config.DMA_Receiver_Control);
	WritePin( Config.UART_Selection, 3 , 3 , Config.HalfDuplex);

	//Inturrput

	WritePin( Config.UART_Selection , 1 , 8 , Config.Intrrupt_Control.PEIE_Control);
	WritePin( Config.UART_Selection , 1 , 7 , Config.Intrrupt_Control.TXEIE_Control);
	WritePin( Config.UART_Selection , 1 , 6 , Config.Intrrupt_Control.TCIE_Control);
	WritePin( Config.UART_Selection , 1 , 5 , Config.Intrrupt_Control.RXNEIE_Control);
	WritePin( Config.UART_Selection , 1 , 4 , Config.Intrrupt_Control.IDLEIE_Control);


	//Baud Rate handle part
	double ClockFrequency = 16000000;
    double BaudRate = Config.BaudRate;
    double MentissaF = (ClockFrequency / (BaudRate * (16 / (2 - (1 - Config.OverSamplingMode) ) ) ) );

    uint16 Mentissa = MentissaF;

	double FractionF = (MentissaF - Mentissa)  *  (16 / (2 - (1 - Config.OverSamplingMode) ) );

    uint16 Fraction = ceil(FractionF);

	uint8 AnddingVar = ((1 - Config.OverSamplingMode) << 3) | 0111 ;

	uint16 USARTDIV = (Mentissa << 4) | (Fraction & AnddingVar ) ;
	UART->USART_BRR = USARTDIV ;
	UART->USART_BRR = USARTDIV;

}

bool UART_Send(uint8 Data , _UART_Selection UART_Selection)
{
	UART_REG * UART = SelectUART(UART_Selection) ;
	UART->USART_DR = Data ;
	while(GET_BIT(UART->USART_SR , 7) == 0) ; //  wait to make sure the data are sent
	return TRUE ;
}

uint8 UART_Receive(_UART_Selection UART_Selection)
{
	UART_REG * UART = SelectUART(UART_Selection) ;
	while(GET_BIT(UART->USART_SR , 5) == 0) ;
	uint8 Data = UART->USART_DR ;
    return Data ;
}

void UART_SendString(char * StringData , _UART_Selection UART_Selection)
{
	for( uint16 Count = 0  ; Count < strlen(StringData)  ; Count++)
	{
		UART_Send(StringData[Count] , UART_Selection);
	}
}

char * UART_ReceiveString(_UART_Selection UART_Selection)
{
	char * StringData = NULL ;
	uint8 Count = 0 ;
	while(UART_Receive(UART_Selection) != '\0')
	{
		StringData[Count] = UART_Receive(UART_Selection) ;
		Count++ ;
	}
	return StringData ;
}

char * UART_ReceiveStringUntil(char Limit , _UART_Selection UART_Selection )
{
	uint16 Count = 0;
	char Data = 0;
	while(BufferSize <= 0)
	{
		StringData[Count] = 0 ;
		Count++ ;
		BufferSize-- ;
	}
	StringData[Count] = 0 ;
	Count = 0 ;
	while(TRUE)
	{
		Data = UART_Receive(UART_Selection);
		if(Data == Limit)
		{
			break;
		}
		StringData[Count] = Data ;
		Count++ ;
		BufferSize++;
	}
	return StringData ;
}

uint8 Await_UART_Receive(_UART_Selection UART_Selection , uint8 Count)
{
	UART_REG * UART = SelectUART(UART_Selection) ;
	while(GET_BIT(UART->USART_SR , 5) == 0 && Count--);
	uint8 Data = UART->USART_DR ;
    return Data ;
}

uint8 UART_Tx_Rx(uint8 Data , _UART_Selection UART_Selection)
{
	uint8 RData;
	UART_REG * UART = SelectUART(UART_Selection) ;
	UART->USART_DR = Data ;
	while(GET_BIT(UART->USART_SR , 7) == 0) ; //  wait to make sure the data are sent
	while(GET_BIT(UART->USART_SR , 5) == 0) ;
	RData = UART->USART_DR ;
	return RData ;
}

void UART_Enable(_UART_Selection UART_Selection)
{
	UART_REG * UART = SelectUART(UART_Selection) ;
	SET_BIT(UART->USART_CR1 , 13);
}

void UART_Disable(_UART_Selection UART_Selection)
{
	UART_REG * UART = SelectUART(UART_Selection) ;
	CLR_BIT(UART->USART_CR1 , 13);
}

void UART_Smart_Enable(_UART_Selection UART_Selection)
{
	switch(UART_Selection)
	{
	case UART1 :
		RCC_voidEnableClockForPripheral(APB2, USART1_ID);
	break;
	case UART2 :
		RCC_voidEnableClockForPripheral(APB1, USART2_ID);
	break;
	case UART6 :
		RCC_voidEnableClockForPripheral(APB2, USART6_ID);
	break;
	}
}

void UART_Smart_Disable(_UART_Selection UART_Selection)
{
	switch(UART_Selection)
	{
	case UART1 :
		RCC_voidDisableClockForPripheral(APB2, USART1_ID);
	break;
	case UART2 :
		RCC_voidDisableClockForPripheral(APB1, USART2_ID);
	break;
	case UART6 :
		RCC_voidDisableClockForPripheral(APB2, USART6_ID);
	break;
	}
}




void(*ptr)(void);


void UART_CallBack(void(*User_Function)(void))
{
	ptr = User_Function ; // now we have the pointer to the user function we can pass it to the ISR of the uart
}

void USART1_IRQHandler(void)
{
  ptr();
	//UART1->USART_SR = 0 ; // Make the status register is 0 after implement the user function
}

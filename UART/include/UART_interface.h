/********************************************************/
/*		Author  : Eslam							        */
/*		Date    : 09/10/2023    						*/
/*		Version : 1.1									*/
/********************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <math.h>
#include "UART_private.h"
#include "RCC_Interface.h"
#include <string.h>
#include <math.h>

extern char * StringData ;
extern uint16 BufferSize ;

typedef enum
{
	UART1 ,
	UART2 ,
	UART6 ,

}_UART_Selection ;

typedef enum
{
	PeerToPeer ,
	Master_Salve ,

}_UART_Mode ;

typedef enum
{
	OverSample_16 ,
	OverSample_8 ,

}_OverSamplingMode ;

typedef enum
{
	USART_Disable,
	USART_Enable,
	
}_USART_Control;

typedef enum
{
	_8_bit,
	_9_bit,
	
}_WordLength ;

typedef enum
{
	WakeUp_IdelLine,// wake up the controller to receive or send by start bit
	WakePUp_Address,// wake up the controller to receive or send by send the address ( it's address)
	
}_WakeUp;

typedef enum
{
	Parity_disable,
	Parity_enable,
	
}_Parity_Control;

typedef enum
{
	Even_Parity,
	Odd_Parity,

}_Parity_selection;

typedef enum
{
	Tx_disable,
	Tx_enable,
	
}_TxControl;

typedef enum
{
	Rx_disable,
	Rx_enable,
	
}_RxControl;

typedef enum
{
	LIN_disable,
	LIN_enable,
	
}_LINMode ;

typedef enum
{
	_1_Stop,
	_Hlaf_Stop,
	_1_5_Stop,
	_2_Stop
	
}_StopBits;

typedef enum
{
	Clock_disable,
	Clock_enable,
	
}_Clock_Control;

typedef enum
{
	Steady_Low,
	Steady_High,
	
}_ClockPolarity;

typedef enum
{
	FirstClock,
	SecondClock,
	
}_ClockPhase;

typedef enum
{
	DMA_Transmission_disable,
	DMA_Transmission_enable,
	
}_DMA_Transmission_Control;

typedef enum
{
	DMA_Receiver_disable,
	DMA_Receiver_enable ,
	
}_DMA_Receiver_Control;

typedef enum
{
	HalfDuplex_disable,
	HalfDuplex_enable ,
	
}_HalfDuplex;

typedef enum
{
	DisablePEIE = 0,
	EnablePEIE  ,		

}_PEIE_Control ;

typedef enum
{
	DisableTXEIE = 0,
	EnablePTXEIE ,

}_TXEIE_Control;

typedef enum
{
	DisableTCIE  = 0,
	EnablePTCIE  ,

}_TCIE_Control;

typedef enum
{
	DisableRXNEIE = 0,
	EnablePRXNEIE,

}_RXNEIE_Control;

typedef enum
{
	DisableIDLEIE = 0,
	EnablePIDLEIE,

}_IDLEIE_Control;


typedef struct 
{
	_PEIE_Control	PEIE_Control;// parity error interrupt enable
	_TXEIE_Control	TXEIE_Control; // when data is ready to send will generate inturrput enable
	_TCIE_Control	TCIE_Control; // when transimstion compelete will generate interurupt enable
	_RXNEIE_Control	RXNEIE_Control;// when receive new data will generate interrupt enable
	_IDLEIE_Control	IDLEIE_Control;// when idel line detection generate interrupt enable

}_Intrrupt_Control;

typedef enum
{
	_921600 = 921600,
	_460800 = 460800,
	_230400 = 230400,
	_115200 = 115200,
	_57600 = 57600,
	_38400 = 38400,
	_19200 = 19200,
	_9600 = 9600,
	_4800 = 4800,
	_2400 = 2400,
	_1200 = 1200,
	_300 = 300,
	_150 = 150,
	_110 = 110,

}_BaudRate ;


typedef struct 
{
	_UART_Selection				UART_Selection			;
	_UART_Mode					UART_Mode				;
	_OverSamplingMode			OverSamplingMode        ;
	_USART_Control              USART_Control           ;
	_WordLength                 WordLength              ;
	_WakeUp                     WakeUp                  ;
	_Parity_Control             Parity_Control          ;
	_Parity_selection			Parity_selection		;
	_TxControl                  TxControl               ;
	_RxControl                  RxControl               ;
	_LINMode                    LINMode                 ;
	_StopBits                   StopBits                ;
	_Clock_Control              Clock_Enable            ;
	_ClockPolarity              ClockPolarity           ;
	_ClockPhase                 ClockPhase              ;
	_DMA_Transmission_Control   DMA_Transmission_Control;
	_DMA_Receiver_Control       DMA_Receiver_Control    ;
	_HalfDuplex                 HalfDuplex              ;
	_Intrrupt_Control           Intrrupt_Control        ;
	_BaudRate 					BaudRate 				;

}UARTConfig;



void UART_Init(UARTConfig Config);

void WritePin(_UART_Selection UART_Selection , uint32  Reg , uint8 Pin , uint8 Val);

UART_REG * SelectUART(_UART_Selection UART_Selection);

bool UART_Send(uint8 Data , _UART_Selection UART_Selection);

uint8 UART_Receive(_UART_Selection UART_Selection);

void UART_SendString(char * StringData , _UART_Selection UART_Selection);

char * UART_ReceiveString(_UART_Selection UART_Selection);

char * UART_ReceiveStringUntil(char Limit , _UART_Selection UART_Selection );

uint8 UART_Tx_Rx(uint8 Data , _UART_Selection UART_Selection);

void UART_Enable( _UART_Selection UART_Selection);

void UART_Disable( _UART_Selection UART_Selection);

void UART_Smart_Enable(_UART_Selection UART_Selection);

void UART_Smart_Disable(_UART_Selection UART_Selection);

void UART_CallBack(void (*User_Function)(void));







#endif

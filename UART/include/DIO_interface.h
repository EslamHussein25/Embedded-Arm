/************************************/
/*        Author:  Eslam 			*/
/*        Date:    01/06/2023		*/
/*        Version: 1.1				*/
/************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H



typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	
}PINS;

typedef enum
{
	Input ,
	Output,
	Analog,
	Alternate_Function,
	 
}PIN_Mode;

typedef enum
{
	OUTPUT_PUSH_PULL,
	OUTPUT_OPEN_DRAIN,
	
}PIN_OUTPUT_Mode;

typedef enum
{
	INPUT_NO_MODE,
	INPUT_PULL_UP,
	INPUT_PULL_DOWN,
	
}PIN_INPUT_Mode;

typedef enum
{
	Low_speed,
	Medium_speed,
	High_speed,
	Very_high_speed,

}Pin_Speed;

typedef enum
{
	LOW,
	HIGH,
	
}Pin_State;

typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	
}PORTS;

typedef enum
{
	AF0=0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15,

}PIN_AF;

typedef struct 
{
	PINS 			     Pins ;
	Pin_State            State;				     
	PORTS                PORT;
	PIN_Mode  		     PINModes ;
	PIN_OUTPUT_Mode      PIN_OUTPUT_MODE;
	PIN_INPUT_Mode       PIN_INPUT_MODE;
	Pin_Speed 		     Pin_SPEED ;
	
}DIO_Configuration;



void DIO_PinConfig(DIO_Configuration * Config);
void DIO_SETPinVal(PORTS Port , PINS pin , Pin_State State);
uint8 DIO_GETPinVal(PORTS Port , PINS pin);
void MGPIO_voidSetPinAltFun(PORTS Copy_u8PortName ,uint8 Copy_u8PinNum, PIN_AF Copy_u8AlFun);


#endif

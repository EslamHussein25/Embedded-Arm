/************************************************************************/
/* Author 		: Eslam    												*/
/* Date 		: 29-JUL-2020 	    									*/
/* Version 		: V01 													*/
/************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define NIBBLE_PINS  0b1111
#define BYTE_PINS    0b11111111
#define NIBBLE 4
#define BYTE   8
#define NULL1 ((unsigned char *)0)

#define SET_BIT(VAR , BIT)   VAR |= (1<<BIT)
#define CLR_BIT(VAR , BIT)   VAR &= ~(1<<BIT)
#define GET_BIT(VAR , BIT)   ((VAR >> BIT)&1)
#define TOG_BIT(VAR , BIT)   VAR ^= (1<<BIT)    // VAR |= (1<<BIT) Like that but the or change to the xor to toggle 
//#define WritePin(VAR , BIT , VAL)   ((VAL)?(VAR |= (1<<BIT)):(VAR &= ~(1<<BIT)))

#define CLR_NIBBLE(VAL , START_BIT)  VAL &= ~((NIBBLE_PINS)<<(START_BIT * 4)) 
#define CLR_BYTE(VAL , START_BIT)  VAL &= ~((BYTE_PINS)<<(START_BIT * 8)) 

#define SET_NIBBLE(VAL , START_BIT)  VAL |= (NIBBLE_PINS << (START_BIT * 4)) 
#define SET_BYTE(VAL , START_BIT)    VAL |= (BYTE_PINS << (START_BIT * 8)) 

#define WRITE_NIBBLE(VAL , START_BIT , BITS_VALUE)  VAL |= (BITS_VALUE << (START_BIT * 4)) // Note: you can't to use this macro directly , first you have to clear the nibble first 
#define WRITE_BYTE(VAL , START_BIT , BITS_VALUE)    VAL |= (BITS_VALUE << (START_BIT * 8)) // Note: you can't to use this macro directly , first you have to clear the byte first 



#endif

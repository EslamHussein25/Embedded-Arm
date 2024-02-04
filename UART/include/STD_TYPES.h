/********************************************************/
/*		Author  : Eslam							        */
/*		Date    : 29-JUL-2020							*/
/*		Version : 01									*/
/********************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H


typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           int8;           /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          int16;          /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           int32;          /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      int64;
typedef float                 float32;
typedef double                float64;
typedef unsigned char 		  bool ;

//=============================================================
/*
#define HIGH  1
#define LOW   0*/

#define OUTPUT 1
#define INPUT  0

#define TRUE   1
#define FALSE  0
#define true   1
#define false  0
//=============================================================

/*
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7
#define PIN8  8
#define PIN9  9

#define PIN10  10
#define PIN11  11
#define PIN12  12
#define PIN13  13
#define PIN14  14
#define PIN15  15 */

#define Higher_Nibble_Out    0xF0
#define Lower_Nibble_Out     0x0F
//=============================================================


#endif

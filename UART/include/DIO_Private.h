/************************************/
/*        Author:  Eslam 			*/
/*        Date:    01/06/2023		*/
/*        Version: 1.1				*/
/************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H


#define  PORTA_REG_BASE_ADDRESSES   (0x40020000)
#define  PORTB_REG_BASE_ADDRESSES   (0x40020400)
#define  PORTC_REG_BASE_ADDRESSES   (0x40020800)
#define  PORTD_REG_BASE_ADDRESSES   (0x40020C00)
#define  PORTE_REG_BASE_ADDRESSES   (0x40021000)
#define  PORTH_REG_BASE_ADDRESSES   (0x40021C00)


//dereferance will be done with struct 
//هنا  انا مجبر اكتب كل المسلاجت هتى المحجوزه منها عشان تنزل صح فى الذاكره 
typedef struct 
{
	volatile uint32 MODER;
	volatile uint32 OTYPE;
	volatile uint32 OSPEEDR;
	volatile uint32 PUPDR;
	volatile uint32 IDR;
	volatile uint32 ODR;
	volatile uint32 BSRR;
	volatile uint32 LCKR;
	volatile uint32 ARF[2];
	
}GPIO_ACCESS;

#define GPIOA  ((GPIO_ACCESS*)PORTA_REG_BASE_ADDRESSES)
#define GPIOB  ((GPIO_ACCESS*)PORTB_REG_BASE_ADDRESSES)
#define GPIOC  ((GPIO_ACCESS*)PORTC_REG_BASE_ADDRESSES)
#define GPIOD  ((GPIO_ACCESS*)PORTD_REG_BASE_ADDRESSES)
#define GPIOE  ((GPIO_ACCESS*)PORTE_REG_BASE_ADDRESSES)
#define GPIOH  ((GPIO_ACCESS*)PORTH_REG_BASE_ADDRESSES)

//like hamdy 
//بدل من ان ابعت كل من ال EUNM
// اللى عندى فى الداله وسيكون كل بارمترات الداله بنفس عدد ال NUM  الموجود عندى 
//وممكن يكون كتير جدا الحل ان 
// Collect all eunm in one struct and this struvt to my function to check on it so 
//like array i send every thing in one step and by this struct set all config insed the function 



// بعد كده كل الاختيارات دى هتم فى ال main 
//  من متغير موجوده من ال struct 
//بعده هبعت المتغير ده لل  للداله بتاعت ال setpinmode
//وجه فى ال  runtime because in post bulid method 

#endif
/************************************/
/*        Author:  Eslam 			*/
/*        Date:    09/05/2023		*/
/*        Version: 1.1				*/
/************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


#define RCC_BASE_ADD (0x40023800)

typedef struct 
{
	volatile uint32 RCC_CR           ;
	volatile uint32 RCC_PLLCFGR      ;
	volatile uint32 RCC_CFGR         ; 
	volatile uint32 RCC_CIR          ;
	volatile uint32 RCC_AHB1RSTR     ;
	volatile uint32 RCC_AHB2RSTR     ;
	volatile uint32 Reserved1        ;
	volatile uint32 Reserved2        ;
	volatile uint32 RCC_APB1RSTR     ;
	volatile uint32 RCC_APB2RSTR     ;
	volatile uint32 Reserved3        ;
	volatile uint32 Reserved4        ;
	volatile uint32 RCC_AHB1ENR      ;
	volatile uint32 RCC_AHB2ENR      ;
	volatile uint32 Reserved5        ;
	volatile uint32 Reserved6        ;
	volatile uint32 RCC_APB1ENR      ;
	volatile uint32 RCC_APB2ENR      ;
	volatile uint32 Reserved7        ;
	volatile uint32 Reserved8        ;
	volatile uint32 RCC_AHB1LPENR    ;
	volatile uint32 RCC_AHB2LPENR    ;
	volatile uint32 Reserved9        ;
	volatile uint32 Reserved10       ;
	volatile uint32 RCC_APB1LPENR    ;
	volatile uint32 RCC_APB2LPENR    ;
	volatile uint32 Reserved11       ;
	volatile uint32 Reserved12       ;
	volatile uint32 RCC_BDCR         ;
	volatile uint32 RCC_CSR          ;
	volatile uint32 Reserved13       ;
	volatile uint32 Reserved14       ;
	volatile uint32 RCC_SSCGR        ;
	volatile uint32 RCC_PLLI2SCFGR   ;
	volatile uint32 RCC_DCKCFGR      ;
	
}RCC_Config;

#define RCC ((volatile RCC_Config *)RCC_BASE_ADD)






#endif

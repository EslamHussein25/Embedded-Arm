/********************************************************/
/*		Author  : Eslam							        */
/*		Date    : 09/10/2023    						*/
/*		Version : 1.1									*/
/********************************************************/
 
#define UART1_BASE_ADD (0x40011000)
#define UART2_BASE_ADD (0x40004400)
#define UART6_BASE_ADD (0x40011400)

typedef struct 
{
 volatile uint32 USART_SR   ;
 volatile uint32 USART_DR   ;
 volatile uint32 USART_BRR  ;
 volatile uint32 USART_CR1  ;
 volatile uint32 USART_CR2  ;
 volatile uint32 USART_CR3  ;
 volatile uint32 USART_GTPR ;

}UART_REG;

#define __UART1 ((UART_REG * )UART1_BASE_ADD)
#define __UART2 ((UART_REG * )UART2_BASE_ADD)
#define __UART6 ((UART_REG * )UART6_BASE_ADD)








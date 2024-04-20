/* Three USART Controllers Pin mapping details show the below table.

2.0/3.0 4.0/4.1

GPIO Pin Pin Function On-Board Function GPIO Pin Pin Function On-Board Function
PA9 GPIO UART1_TX(Wi-Fi) PA9 GPIO UART1_TX
PA10 GPIO UART1_RX(Wi-Fi) PA10 GPIO UART1_RX
PA2 GPIO UART2_TX PA2 GPIO UART2_TX
PA3 GPIO UART2_RX PA3 GPIO UART2_RX
PC6 GPIO UART6_TX PC6 GPIO UART6_TX (Wi-Fi)
PC7 GPIO UART6_RX PC7 GPIO UART6_RX (Wi-Fi)    */

#define GPIOA_MODE (*(int *)0x40020000)
#define GPIOB_MODE (*(int *)0x40020400)
#define USART_MODE (*(int *)0x40011000)
#define USART_CR1 (*(int *)0x4001100C)  
#define USART_SR (*(int *)0x40011000)  
#define USART_DR (*(int *)0x40011004)
#define USART_BRR (*(int *)0x40011008)   
#define GPIOA_AFRH (*(int *)0x40020024)
#define RCC_AHB1ENR (*(int *)0x40023830)
#define RCC_APB2ENR (*(int *)0x40023844)
void UART2_OUTCHAR(unsigned char);
void KM_UART_OUT(unsigned char data);
unsigned char KM_UART_IN(void);
void mux_init(void);
void config(void);
char ch=0;
int main()
{

	mux_init();
	config();
	while(1)
	{
		KM_UART_OUT('A');
		ch=KM_UART_IN();
	}

}
void KM_UART_OUT(unsigned char data)
{
	while((USART_SR&0x1<<7)==0);
	USART_DR=data;
}

unsigned char KM_UART_IN(void)
{
	while((USART_SR&0x1<<5)==0);
	return USART_DR;
}

void mux_init()
{
	RCC_AHB1ENR |=0x1;
	RCC_APB2ENR |=0x1<<4;
	//RCC_AHB1ENR |=0x1<<2;
	GPIOA_MODE &=0xffC3ffff;
	GPIOA_MODE |=0x00280000;
	GPIOA_AFRH &=0xfffff00f;
	GPIOA_AFRH |=0x00000770;
	USART_CR1 |=0x3<<2;
	USART_CR1 |=0x1<<13;
}

void config(void)
{

	USART_BRR |=0x3;
	USART_BRR |= 0x68<<4;
}


/*  Develop a Communication between two Raayan mini boads using UART2
protocol.
The switches (PC8 and PC9) are inputs, LEDs (PA8, PC5) are outputs, and the UART2 is used to
communicate      */


#define RCC_AHB1ENR *(int *)0x40023830
#define RCC_APB2ENR *(int *)0x40023844
#define GPIOC_MODER *(int *)0x40020800
#define GPIOC_IDR *(int *)0x40020810
#define GPIOB_MODER *(int *)0x40020400
#define GPIOB_ODR *(int *)0x40020414
#define GPIOA_MODER *(int *)0x40020000
#define GPIOC_PUPDR *(int *)0x4002080C
#define GPIOA_AFRH *(int *)0x40020024
#define USART1_SR *(int *)0x40011000
#define USART1_DR *(int *)0x40011004
#define USART1_BRR *(int *)0x40011008
#define USART1_CR1 *(int *)0x4001100C
char ch=0;

void RCC_init()
{
	RCC_AHB1ENR |= 0x1;
	RCC_AHB1ENR |= 0x1<<1;
	RCC_AHB1ENR |= 0x1<<2;
	RCC_APB2ENR |= 0x1<<4;
}
void MUX_init()
{
	GPIOA_MODER &=~(0xCC<<18);
	GPIOA_MODER |=(0xA<<18);
	GPIOB_MODER &=~(0xC3<26);
	GPIOB_MODER |=(0x1<<26);
	GPIOB_MODER |=(0x1<<28);
	GPIOC_MODER &=0xFFF0FFFF;
	GPIOC_PUPDR &=0xFFF0FFFF;
	GPIOC_PUPDR |=0x5<<16;
	GPIOA_AFRH &=~(0x77<<4);
	GPIOA_AFRH |=0x77<<4;
	USART1_BRR =0x683;
	USART1_CR1 |=0x200C;
}
void delay(int n)
{
	int i=n*2500;
	for(;i>0;i--)
	{
		;
	}
}
void KM_UART_OUT(void)
{
	if((GPIOC_IDR&0x1<<8)==0)
	{
		while((USART1_SR&0x1<<7)==0);
		USART1_DR='R';
		delay(1000);
	}
	if((GPIOC_IDR&0x1<<9)==0)
	{
		while((USART1_SR&0x1<<7)==0);
		USART1_DR='G';
		delay(1000);
	}
}

void KM_UART_IN(void)
{
	if(USART1_SR&0x1<<5)
	{
		ch=USART1_DR;
		if(ch=='R')
		{
			GPIOB_ODR |=0x1<<14;
			GPIOB_ODR &=~(0x1<<13);
		}
		if(ch=='G')
		{
			GPIOB_ODR |=0x1<<13;
			GPIOB_ODR &=~(0x1<<14);
		}
	}
}

int main()
{
	RCC_init();
	MUX_init();
	GPIOB_ODR |=0x1<<13;
	GPIOB_ODR |=0x1<<14;
	while(1)
	{
		KM_UART_OUT();
		KM_UART_IN();
	}
}


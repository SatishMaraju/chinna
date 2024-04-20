/*  Develop Communication between two Raayn MIni Boards using SPI protocol same as previous lab experiment using UART?   */



#define RCC_AHB1ENR *(int *)0x40023830
#define RCC_APB2ENR *(int *)0x40023844
#define GPIOA_MODER *(int *)0x40020000
#define GPIOA_AFRL *(int *)0x40020020
#define SPI1_CR1 *(int *)0x40013000
#define SPI1_CR2 *(int *)0x40013004	
#define SPI1_SR *(int *)0x40013008
#define SPI1_DR *(int *)0x4001300C
#define GPIOB_MODER *(int *)0x40020400
#define GPIOC_MODER *(int *)0x40020800
#define RCC_AHB1ENR *(int *)0x40023830
#define GPIOB_ODR *(int *)0x40020414
#define GPIOC_IDR *(int *)0x40020810
#define PUPDR *(int *) 0x4002080c	


char ch=0;

void RCC_init()
{
	RCC_AHB1ENR |= 0x1;
	while((RCC_AHB1ENR & 0x1)==0)
	{
		;
	}	
	RCC_APB2ENR |= 0x1<<12;
	while((RCC_APB2ENR & 0x1<<12)==0)
	{
		;
	}	
	RCC_AHB1ENR |=0x6;
	while(!(RCC_AHB1ENR &0x6))
	{
		;
	}
}
void MUX_init()
{
	GPIOA_MODER &=~(0xFF);
	GPIOA_MODER |=(0xAA<<8);
	GPIOA_AFRL &=~(0xFFFF<<16);
	GPIOA_AFRL |=0x5555<<16;//
	SPI1_CR1 &=~(0x1<<6);
	SPI1_CR1 &=~(0x1<<2);
	//SPI1_CR1 |=0x44;
	//SPI1_CR2 |=0X1<<2;
	//SPI1_CR1 |=0x1<<2;
	SPI1_CR1 |=0x1<<6;
	GPIOB_MODER &= 0xc3ffffff;
	GPIOB_MODER |= 0x14000000;
	GPIOC_MODER &= 0xfff0ffff;
	GPIOC_MODER |= 0x00000000;
	PUPDR &=0xfff0ffff;
	PUPDR |=0x00050000;
}
void KM_SPI_IN(void)
{
	while((SPI1_SR&0x1)==0)
	{
		;
	}
	if(SPI1_DR=='R')
	{
		GPIOB_ODR &=~(0x01<<13);
		GPIOB_ODR |=(0x01<<14);
	}
	if(SPI1_DR=='G')
	{
		GPIOB_ODR |=(0x01<<13);
		GPIOB_ODR &=~(0x01<<14);
	}

}
void delay(int a)
{
	int i;
	for(i=0;i<1670*a;i++)
	{
		;
	}
}

void KM_SPI_OUT(void)
{

	if((GPIOC_IDR&0x01<<8)==0)
	{
		SPI1_DR='R';
		delay(100);
	}
	if((GPIOC_IDR&0x01<<9)==0)
	{
		SPI1_DR='G';
		delay(100);
	}
	while((SPI1_SR&0x1<<1)==0)
	{
		;
	}		


	//		GPIOB_ODR &=~(0x01<<13);
	//		GPIOB_ODR &=~(0x01<<14);
}

int main()
{
	RCC_init();
	MUX_init();
	GPIOB_ODR |=(0x01<<13);
	GPIOB_ODR |=(0x01<<14);
	while(1)
	{
		KM_SPI_OUT();
		if(SPI1_DR == 'R' || SPI1_DR == 'G')
			KM_SPI_IN();
		//KM_SPI_IN();
	}
}


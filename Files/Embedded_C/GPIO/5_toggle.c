#define GPIOB_MODER *(int *)0x40020400
#define GPIOC_MODER *(int *)0x40020800
#define RCC_AHB1ENR *(int *)0x40023830
#define GPIOB_ODR *(int *)0x40020414
#define GPIOC_IDR *(int *)0x40020810
#define PUPDR *(int *) 0x4002080c	
	
void AHB1ENR()
{
	RCC_AHB1ENR |=0x6;
	while(!(RCC_AHB1ENR &0x6))
	{
		;
	}
}

void CONFIG()
{
	GPIOB_MODER &= 0xf3ffffff;
	GPIOB_MODER |= 0x04000000;
	GPIOC_MODER &= 0xffcfffff;
	GPIOC_MODER |= 0x00000000;
	PUPDR &=0xffCfffff;
	PUPDR |=0x00100000;
	
}
void delay()
{
	int i;
	for(i=0;i<1250000;i++)
	{
		;
	}
}
int main()
{
	AHB1ENR();
	CONFIG();
	// GPIOB_ODR |=(0x1<<13);
	while(1)
	{
		if((GPIOC_IDR&0x1<<10)==0)
		{
		
			GPIOB_ODR ^=(0x01<<13);
			delay();
		}
		
	}
}

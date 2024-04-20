#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODE (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
#define GPIOC_IDR (*((int *)0x40020810))
#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_PUPDR (*((int *)0x4002080C))

void red_init(void);		
void red_config(void);
void delay1();
void delay2();
int main()
{
	red_init();
	red_config();
	GPIOB_ODR |= (0x1<<13);
	while(1)
	{
		if(!(GPIOC_IDR & (0x1<<10)))
			GPIOB_ODR &= ~(0x1<<13);
	}}
void red_init(void)
{
	RCC_AHB1ENR|=(0x6);
	while(!(RCC_AHB1ENR &= 0x6))
	{
		;
	}
}
void red_config(void)
{
	GPIOB_MODE&= 0xf3ffffff;
	GPIOB_MODE |=(0x04000000);
	GPIOC_MODER &= 0xffcfffff;
	GPIOC_MODER |=(0x00000000);
	GPIOC_PUPDR &= (0xffcfffff);
	GPIOC_PUPDR |= (0x00100000);
}


#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODE (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
void red_init(void);		
void red_config(void);
void delay();
int main()
{
	red_init();
	red_config();
	while(1)
	{
		GPIOB_ODR &= ~(0x1<<13);
		delay();
		GPIOB_ODR |=(0x1<<13);
		delay();
	}}
void red_init(void)
{
	RCC_AHB1ENR|=(0x1<<1);
	while(!(RCC_AHB1ENR&=(0x1<<1)))
	{
		;
	}
}
void red_config(void)
{
	GPIOB_MODE=GPIOB_MODE & (0xf3ffffff);
	GPIOB_MODE |=(0x04000000);
}
void delay()
{
	int i;
	for(i=0;i<125000;i++)
	{
		;
	}}


//Toggle RED LED ON time is 50ms and RED LED OFF time is 1300ms


#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODE (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
void red_init(void);		
void red_config(void);
void delay1();
void delay2();
int main()
{
	red_init();
	red_config();
	while(1)
	{
		GPIOB_ODR &= ~(0x1<<13);
		delay1();
		GPIOB_ODR |=(0x1<<13);
		delay2();
	}}
void red_init(void)
{
	RCC_AHB1ENR|=(0x2);
	while(!(RCC_AHB1ENR &= 0x2))
	{
		;
	}
}
void red_config(void)
{
	GPIOB_MODE=GPIOB_MODE & (0xf3ffffff);
	GPIOB_MODE |=(0x04000000);
}
void delay1()
{
	int i;
	for(i=0;i<125000;i++)
	{
		;
	}}
void delay2()
{
	int i;
	for(i=0;i<325000;i++)
	{
		;
	}}


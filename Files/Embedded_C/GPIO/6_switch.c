Read SW_ENT, if switch is press RED LED is ON otherwise RED LED is OFF. Note that RED LED
should remain ON for the duration switch is kept pressed i.e. RED LED should turn OFF when switch is released.


#define GPIOB_MODER *(int *)0x40020400
#define GPIOC_MODER *(int *)0x40020800
#define RCC_AHB1ENR *(int *)0x40023830
#define GPIOB_ODR *(int *)0x40020414
#define GPIOC_IDR *(int *)0x40020810
#define GPIOC_PUPDR *(int *)0x4002080c	
void init();
void config();
void delay();
int main()
{
	init();
config();
while(1)
{
GPIOB_ODR |=0x1<<13;
if(	(GPIOC_IDR &=0x1<<10)==0)
	GPIOB_ODR &=~(0x1<<13);
	delay();
	}}
void init()
{
	RCC_AHB1ENR |=0x6;
	while(!(RCC_AHB1ENR &0x6))
	{
		;
	}
}
void config()
{
	GPIOB_MODER &= 0xf3ffffff;
	GPIOB_MODER |= 0x04000000;
	GPIOC_MODER &= 0xffcfffff;
	GPIOC_MODER |= 0x00000000;
	GPIOC_PUPDR &= 0xffcfffff;
	GPIOC_PUPDR |= 0x00100000;
}
void delay()
{
	int i;
	for(i=0;i<165000;i++)
	{
		;
	}}



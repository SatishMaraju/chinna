/*  Airplane wing Lights blinking Delays:
    USER LED1 (GREEN): ON (50msec), OFF (50msec), ON (50msec), OFF (150msec) periodically. USER LED2 (RED): ON (50msec), OFF (250msec), ON (50msec), OFF (500msec) periodically.
 */



#define GPIOB_MODER *(int *)0x40020400
#define RCC_AHB1ENR *(int *)0x40023830
#define GPIOB_ODR *(int *)0x40020414

void RED_LED()
{
	RCC_AHB1ENR |=(0x1<<1);
	while(!(RCC_AHB1ENR &(0x1<<1)))
	{
		;
	}
}

void RED_LED_CONFIG()
{
	GPIOB_MODER &= 0xf3ffffff;
	GPIOB_MODER |= 0x04000000;
}
void GREEN_LED_CONFIG()
{
	GPIOB_MODER &= 0xcfffffff;
	GPIOB_MODER |= 0x10000000;
}
void delay(int n)
{
	int i=n*2500;
	for(;i>0;i--)
	{
		;
	}
}
int main()
{
	RED_LED();
	RED_LED_CONFIG();
	GREEN_LED_CONFIG();
	while(1)
	{
		GPIOB_ODR &=~(0x01<<13);
		GPIOB_ODR &=~(0x01<<14);
		delay(50);
		GPIOB_ODR |=(0x01<<14);
		delay(50);
		GPIOB_ODR |=(0x01<<13);
		delay(250);
		GPIOB_ODR &=~(0x01<<13);
		GPIOB_ODR &=~(0x01<<14);
		delay(50);
		GPIOB_ODR |=(0x01<<14);
		delay(150);
		GPIOB_ODR |=(0x01<<13);
		delay(500);
	}
}


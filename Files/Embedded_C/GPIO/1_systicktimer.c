/*  Toggle PB13 (RED LED) every 100 msec delay using SysTick timer using 16 MHZ system clock source.
     And also test minimum and maximum delays of 16MHZ timer.
Draw flowcharts and write an embedded C program for the below 2 methods
a: polling method.   */


#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODE (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0X40020414))
#define SYS_CTRL (*((int *)0XE000E010))
#define SYS_LOAD (*((int *)0XE000E014))
#define SYS_VAL (*((int *)0XE000E018))	
	void RED_init()
	{
		RCC_AHB1ENR = RCC_AHB1ENR | (0x1<<1);
		while(!(RCC_AHB1ENR & (0x1<<1)))
		{
			;
		}	
		
	}
	
	void RED_Con()
	{
		GPIOB_MODE &= (0xf3ffffff);
		GPIOB_MODE |=(0x04000000);
		
	}
	void sys()
	{
	SYS_CTRL |= 0x00000005;
		SYS_VAL = 0x232;	
	SYS_LOAD =1600000;
	}
	
int main()
{
RED_init();
RED_Con();
sys();
while(1)
{
	while((SYS_CTRL & 0x1<<16)==0)
	{
		;
	}
	GPIOB_ODR &= ~(0x1 << 13);
	while((SYS_CTRL & 0x1<<16)==0)
	{
		;
	}
	GPIOB_ODR |= 0x1 << 13;
}
}


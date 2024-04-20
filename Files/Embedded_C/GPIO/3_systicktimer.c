1.Write a program to implement generic delay functions using Sys Tick timer with polling method.
void KM_mdelay(int );  
void KM_udelay(int ); 


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
	
	}
	void KM_mdelay(int a)
	{
		SYS_LOAD =16000*a;
	}	
	void KM_udelay(int a)
	{
		SYS_LOAD =16*a;
	}
int main()
{
RED_init();
RED_Con();
sys();
while(1)
{
	GPIOB_ODR &= ~(0x1 << 13);
	KM_mdelay(50);
	while((SYS_CTRL & 0x1<<16)==0)
	{
		;
	}
	GPIOB_ODR |= 0x1 << 13;
	KM_mdelay(1300);
	while((SYS_CTRL & 0x1<<16)==0)
	{
		;
	}
	GPIOB_ODR &= ~(0x1 << 13);
	KM_udelay(100);
	while((SYS_CTRL & 0x1<<16)==0)
	{
		;
	}
	GPIOB_ODR |= 0x1 << 13;
	KM_udelay(1450);
	while((SYS_CTRL & 0x1<<16)==0)
	{
		;
	}
}
}
  

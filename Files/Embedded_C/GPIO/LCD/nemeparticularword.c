/* When no.of switch preeses is 2 then print 2nd word among the sentence.

string:Satish is good boy
ex:presses is 2
o/p:is    */


#define RCCAHB1ENR (*(int *)0x40023830)
#define GPIOB_MODER (*(int *)0x40020400)
#define GPIOB_ODR (*(int *)0x40020414)
	
#define GPIOC_IDR *(int *)0x40020810
#define GPIOC_MODER *(int *)0x40020800
#define PUPDR *(int *) 0x4002080c	
	
#define NVIC_ISER1 (*((int *)0xE000E104))
#define EXTI15_10 (*((int *)0x000000E0))
#define SYSCFG_EXTICR3 (*((int *)0x40013810))
#define EXTI_IMR (*((int *)0x40013C00))
#define EXTI_PR (*((int *)0x40013C14))
#define EXTI_FTSR (*((int *)0x40013C0C))
#define RCC_APB2ENR (*((int *)0x40023844))
	int c=-1;
int i=1;
void delay(int a)
{
	int i;
	for(i=0;i<1670*a;i++)
	{
		;
	}
}
void Write_high_nibble(unsigned char ch)
{
GPIOB_ODR &= ~(0xF); 
GPIOB_ODR |= (ch>>4 & 0xF);
GPIOB_ODR |=(0x1<<8); 
delay(10);
GPIOB_ODR &=~(0x1<<8); 
}
void Write_low_nibble(unsigned char ch)
{


GPIOB_ODR &=~(0xF);
GPIOB_ODR |= (ch&0xF);
GPIOB_ODR |=(0x1<<8);  
	delay(10);
GPIOB_ODR &=~(0x1<<8); 

}
void KM_LCD_Write_CMD(unsigned char ch)
{
GPIOB_ODR &=~(0x01<<4);  
  Write_high_nibble(ch);
Write_low_nibble(ch);
}
void KM_LCD_Write_data(unsigned char  ch)
{
GPIOB_ODR |=(0x01<<4);  
    Write_high_nibble(ch);  
 Write_low_nibble(ch);

}
void KM_LCD_Write_Str(char *ch)
{
int i;
for(i=0;ch[i]!='\0';i++)
{
KM_LCD_Write_data(ch[i]);
}
}
void GPIOB_Init(void)
{

	RCCAHB1ENR |=0x6;
	while(!(RCCAHB1ENR &0x6))
	{
		;
	}
	RCC_APB2ENR |= (0x00004000);
while(!(RCC_APB2ENR & (0x1<<14)))
{
;
}
SYSCFG_EXTICR3 &= 0xFFFFF0FF;
SYSCFG_EXTICR3 |= 0x00000200;
EXTI_FTSR |= (0x1<<10);
EXTI_IMR |= (0x1<<10);
NVIC_ISER1 |= (0x1<<8);

GPIOB_MODER &=0xFFFCF000;
GPIOB_MODER |=0x10555; 
GPIOB_ODR &=~(0x13<<4);
  
	GPIOC_MODER &= 0xffcfffff;
	GPIOC_MODER |= 0x00000000;
	PUPDR &=0xffCfffff;
	PUPDR |=0x00100000;



}


void KM_LCD_Init(void)
{
GPIOB_Init();


KM_LCD_Write_CMD(0x33);
	delay(20);
KM_LCD_Write_CMD(0x32);
	delay(1);
KM_LCD_Write_CMD(0x0C);
KM_LCD_Write_CMD(0x01);

}
int main()
{

GPIOB_Init();
KM_LCD_Init();
	while(1)
	{		

		{
	if(c==1)
	{
		KM_LCD_Write_CMD(0x01);
   KM_LCD_Write_Str("India");
		delay(1000);
		c=0;
	}
	else if(c==2)
	{
		KM_LCD_Write_CMD(0x01);
   KM_LCD_Write_Str("Is");
		delay(1000);
		c=0;
	}
	else if(c==3)
	{
		KM_LCD_Write_CMD(0x01);
   KM_LCD_Write_Str("a");
		delay(1000);
		c=0;
	}
	else if(c==4)
	{
		KM_LCD_Write_CMD(0x01);
   KM_LCD_Write_Str("great");
		delay(1000);
		c=0;
	}
	else if(c==5)
	{
		KM_LCD_Write_CMD(0x01);
   KM_LCD_Write_Str("country");
		delay(1000);
		c=0;
	}
}
}
}

void EXTI15_10_IRQHandler(void)
{
if(EXTI_PR & (0x1<<10))
{
c++; 
EXTI_PR |= (0x1<<10);
delay(1000);

}
}


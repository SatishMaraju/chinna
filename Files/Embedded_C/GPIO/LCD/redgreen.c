/*  Write an Embedded C Program Whenever SW_UP press RED LED is ON, whenever SW_DN press
GREEN LED is ON using Falling edge GPIO interrupt.
*/

#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODE (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
#define GPIOC_MODE (*((int *)0x40020800))
#define GPIOC_PUPDR (*((int *)0x4002080c))
#define GPIOC_IDR (*((int *)0x40020810))
#define NVIC_ISER0 (*((int *)0xE000E100))
//#define EXTI15_10 (*((int *)0x000000E0))
#define SYSCFG_EXTICR3 (*((int *)0x40013810))
#define EXTI_IMR (*((int *)0x40013C00))
#define EXTI_PR (*((int *)0x40013C14))
#define EXTI_FTSR (*((int *)0x40013C0C))
#define RCC_APB2ENR (*((int *)0x40023844))
	

void AHB1ENR()
{
	RCC_AHB1ENR |=0x6;
	while(!(RCC_AHB1ENR &0x6))
	{
		;
	}
}


void config()
{
		GPIOB_MODE &=0xc3ffffff;
		GPIOB_MODE |=0x14000000;
		GPIOC_MODE &=0Xfff0ffff;
	  GPIOC_MODE |=0X00000000;
		GPIOC_PUPDR &=0xfff0ffff;
		GPIOC_PUPDR |=0x00050000;
}

void SW_INT_init(void)
{
RCC_APB2ENR |= (0x00004000);
while(!(RCC_APB2ENR & (0x1<<14)))
{
;
}
SYSCFG_EXTICR3 &= 0xFFFFFF00;
SYSCFG_EXTICR3 |= 0x00000022;
EXTI_FTSR |= 0X00000300;
EXTI_IMR |=  0X00000300;
NVIC_ISER0 |= (0x1<<23);
}
int main()
{
AHB1ENR();
config();
SW_INT_init();
GPIOB_ODR |= (0x1<<13);
GPIOB_ODR |= (0x1<<14);
while(1)
{
;
}
}

void EXTI9_5_IRQHandler(void)
{
if(EXTI_PR & (0x1<<8))
{
GPIOB_ODR &= ~(0x1<<13);
EXTI_PR |= (0x1<<8);
}

if(EXTI_PR & (0x1<<9))
{
GPIOB_ODR &= ~(0x1<<14);
EXTI_PR |= (0x1<<9);
}
}

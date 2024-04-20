/*   Lab Experiment 3: Whenever SW_UP is pressed RED LED is ON, whenever SW_DN is pressed GREEN LED is ON.
     Assign breakpoints after if condition and click run button in debugger window. Whenever SW1/SW2 presses
     program stops at any one of the breakpoint.
 */

#define RCC_AHB1ENR *(int *)0x40023830
#define GPIOB_MODE *(int *)0x40020400
#define GPIOB_ODR *(int *)0x40020414
#define GPIOC_IDR *(int *)0x40020810
#define GPIOC_MODER *(int *)0x40020800
#define GPIOC_PUPDR *(int *)0x4002080C

void red_init(void);		
void red_config(void);
int main()
{
	red_init();
	red_config();
	GPIOB_ODR |= (0x1<<13);
	GPIOB_ODR |= (0x1<<14);
	while(1)
	{
		if((GPIOC_IDR & (0x1<<8))==0)
			GPIOB_ODR &= ~(0x1<<14);
		if((GPIOC_IDR & (0x1<<9))==0)
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
	GPIOB_MODE &=0xc3000000;
	GPIOB_MODE |= 0x14000000;
	GPIOC_MODER &= 0xfff0ffff;
	GPIOC_MODER |= 0x00000000;
	GPIOC_PUPDR &=0xfff0ffff;
	GPIOC_PUPDR |=0x00050000;
}


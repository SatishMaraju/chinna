/*  4: Use “SW_ENT” and declare “counter” global variable. Your program should increment counter
    by one, every time switch is pressed. Note how the value of counter changes on each “ENTER SWITCH” press. Use
    debugger and add Counter to “Watch Expression” window. Does the value of counter increment by one always?
Note: Define counter as a global variable and in debug perspective use continuous refresh option (You will find
Continuous Refresh button on top of the Expression Window). You can use step debugging or breakpoints to check
the variable value.   */


#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODE (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
#define GPIOC_IDR (*((int *)0x40020810))
#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_PUPDR (*((int *)0x4002080C))

void red_init(void);		
void red_config(void);
void delay(void);
int count=0;
int main()
{

	red_init();
	red_config();
	GPIOB_ODR |= (0x1<<13);
	while(1)
	{
		if(!(GPIOC_IDR & (0x1<<10))){
			GPIOB_ODR &= ~(0x1<<13);
			count++;
			delay();}
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
void delay()
{
	int i;
	for(i=0;i<1200000;i++)
	{
		;
	}}


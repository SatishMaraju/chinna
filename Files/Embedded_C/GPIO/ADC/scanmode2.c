/* Write an embedded C program to enable single/continuous conversion mode in ADC and type of trigger is software. Read Analog input 11(AIN 11)
   and store into global variable(potentiometer) */

#define RCC_AHB1ENR   (*(int *)0x40023830)
#define RCC_APB2ENR  (*(int *)0x40023844)
#define GPIOC_MODE   (*(int *)0x40020800)
#define ADC1_CR2    (*(int *)0x40012008)
#define ADC1_CR1    (*(int *)0x40012004)
#define ADC1_SQR3    (*(int *)0x40012034)
#define ADC1_SR    (*(int *)0x40012000)	
#define ADC_DR  (*(int *)0x44001204C)		


#define NVIC_ISER1 (*((int *)0xE000E100))


int value=0;
void mux_init()
{
	RCC_AHB1ENR = RCC_AHB1ENR | 0x04;
	while(!(RCC_AHB1ENR & (0x04)))
	{
		;
	}			
	GPIOC_MODE |= 0x3<<2;
}

void ADC_init()
{
	RCC_APB2ENR |=0x1<<8;
	while(!(RCC_APB2ENR & (0x1<<8)))
	{
		;
	}	
	ADC1_CR1 |=(0x1<<5);
	ADC1_CR2 &= ~(0x1<<10);
	ADC1_SQR3 |= 0x0B;
	ADC1_CR2 &= ~(0x2);
	ADC1_CR2 |= 0x1;

	NVIC_ISER1 |= (0x1<<18);
}
void delay(int n)
{
	int i=0;
	for(;i<n*1600;i++)
	{
		;
	}
}
int main()
{
	mux_init();
	ADC_init();
	while(1)
	{
		ADC1_CR2 |=0x1<<30;
		delay(500);
	}
}

void ADC_IRQHandler(void)
{

	value=ADC_DR;	

}


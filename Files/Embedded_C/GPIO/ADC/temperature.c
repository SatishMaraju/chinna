/* Write an embedded C program to enable single/continuous conversion mode in ADC and type of trigger is software. Read Analog input 11(AIN 11)
   and store into global variable(potentiometer) */

#define RCC_AHB1ENR   (*(int *)0x40023830)
#define RCC_APB2ENR  (*(int *)0x40023844)
#define GPIOC_MODE   (*(int *)0x40020800)
#define ADC1_CR2    (*(int *)0x40012008)
#define ADC1_SQR3    (*(int *)0x40012034)
#define ADC1_CR1    (*(int *)0x40012004)
#define ADC1_SR    (*(int *)0x40012000)	
#define ADC_DR  (*(int *)0x44001204C)		
int value=0;
void mux_init()
{
	RCC_AHB1ENR = RCC_AHB1ENR | 0x04;
	while(!(RCC_AHB1ENR & (0x04)))
	{
		;
	}	
	GPIOC_MODE &= 0XFFFFFFFC;		
	GPIOC_MODE |= 0x3;
}

void ADC_init()
{
	RCC_APB2ENR |=0x1<<8;        //eneble 8th position to get clock
	while(!(RCC_APB2ENR & (0x1<<8)))
	{
		;
	}	
	// ADC1_CR2 &=~(0x3<<24);
	ADC1_CR2 |= 0x1<<10;
	ADC1_CR1 |=(0x1<<8);   //scan mode enable
	ADC1_SQR3 |= 0x0A;   //temperature value
	// 	ADC1_CR2 |= 0x2;
	ADC1_CR2 |= 0x1;    //enable ADC

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
		ADC1_CR2 |=0x1<<30;      //  eneble 30 th position to enable SWSTART to start conversion
		while(!(ADC1_SR&0x2))    //wait untill to get SR enable
		{
			;
		}
		value=(ADC_DR*3000)/(40960);    //convert it into celcius
		//ADC1_CR2 &=~(0x1<<30);
		delay(500);
	}		

}


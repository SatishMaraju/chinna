/* Write an embedded C program to enable single/continuous conversion mode in ADC and type of trigger is software. Read Analog input 11(AIN 11)
   and store into global variable(potentiometer) */

#define RCC_AHB1ENR   (*(int *)0x40023830)
#define RCC_APB2ENR  (*(int *)0x40023844)
#define GPIOC_MODE   (*(int *)0x40020800)
#define GPIOC_IDR    (*(int *)0x40020810)
#define ADC1_CR2    (*(int *)0x40012008)
#define ADC1_SQR3    (*(int *)0x40012034)
#define ADC1_SR    (*(int *)0x40012000)	
#define ADC_DR  (*(int *)0x44001204C)	
#define ADC_CR1 (*(int *)0x40012004)
int value=0;
void mux_init()
{
	RCC_AHB1ENR = RCC_AHB1ENR | 0x04;     // set 2nd position to enable port c
	while(!(RCC_AHB1ENR & (0x04)))           // wait untill to enable RCC
	{
		;
	}			
	GPIOC_MODE |= 0x3<<2; // make 2 and 3 positions 11 to enable GPIOC as analog mode
}

void ADC_init()
{
	RCC_APB2ENR |=0x1<<8;        // 8th bit is ADC clock and make it to set at 8th positions
	while(!(RCC_APB2ENR & (0x1<<8)))  //wait untill to  get 1 at 8th positions
	{
		;
	}	
	// ADC1_CR2 &=~(0x3<<24);
	ADC1_CR2 |= 0x1<<10;		// set 10th position to enable the EOC as 1
	ADC1_SQR3 |= 0x0B;      // set 11 value to make potentiometer in ADC
	//		ADC1_CR2 |= 0x2;
	ADC1_CR2 |= 0x1; 		//set 1st bit position to enable ADC
	ADC_CR1 |= 0x1<<8;
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
		ADC1_CR2 |=0x1<<30;       // set 1 at 30th osition to start conversion at SWSTART
		while(!(ADC1_SR&0x2))      // set bit at 1st position to get output at Data Register
		{
			;
		}
		value=ADC_DR;             // The value of ADC_DR is assigned to global variable to see the output
		//ADC1_CR2 &=~(0x1<<30);
		delay(500);
	}		

}


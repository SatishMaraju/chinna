/*   Write an Embedded C program to initialize ADC Scan mode.
     Using regular channel software trigger samples ADC channel 10 (Temperature sensor) and 11 (potentiometer) and
     stores the result to a global variables that can be accessed with the ST-Link Debugger.
     using interrupt method.

Hint: To read multiple channels, no. of channels mentioned in length field in ADX_SQR1 register.
In this example to read two channels(10,11) so length is 2.
1st channel(10) load in to SQR3 in SQ1 bit fields and
2nd channel(11) load in to SQR3 in SQ2 bit fields.       */


#define RCC_AHB1ENR   (*(int *)0x40023830)
#define RCC_APB2ENR  (*(int *)0x40023844)
#define GPIOC_MODE   (*(int *)0x40020800)
#define ADC1_CR2    (*(int *)0x40012008)
#define ADC1_SQR3    (*(int *)0x40012034)
#define ADC1_CR1    (*(int *)0x40012004)
#define ADC1_SR    (*(int *)0x40012000)	
#define ADC_DR  (*(int *)0x44001204C)	

#define RCCAHB1ENR (*(int *)0x40023830)
#define GPIOB_MODER (*(int *)0x40020400)
#define GPIOB_ODR (*(int *)0x40020414)
char c,c1;
void delay(int n)
{
	int i=0;
	for(;i<n*1600;i++)
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
void KM_LCD_Write_Str(char ch)
{


	KM_LCD_Write_data(ch);

}

void GPIOB_Init(void)
{
	RCCAHB1ENR |=0x02;
	GPIOB_MODER &=0xFFFCF000;
	GPIOB_MODER |=0x10555; 
	GPIOB_ODR &=~(0x13<<4);  
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
	RCC_APB2ENR |=0x1<<8;
	while(!(RCC_APB2ENR & (0x1<<8)))
	{
		;
	}	
	// ADC1_CR2 &=~(0x3<<24);
	ADC1_CR2 |= 0x1<<10;
	ADC1_CR1 |=(0x1<<8);
	ADC1_SQR3 |= 0x0A;
	// 	ADC1_CR2 |= 0x2;
	ADC1_CR2 |= 0x1;

}


int main()
{
	mux_init();
	ADC_init();
	GPIOB_Init();
	KM_LCD_Init();


	while(1)
	{
		ADC1_CR2 |=0x1<<30;
		while(!(ADC1_SR&0x2))
		{
			;
		}
		value=((ADC_DR*3100)/(40960));

		c=(value/10)+48;
		KM_LCD_Write_Str(c);
		c1=(value%10)+48;
		KM_LCD_Write_Str(c1);


		delay(1000);
		KM_LCD_Write_CMD(0x01);
		//delay(500);

	}		

}

//   Write a Pseudo code, draw flow charts and write Embedded C Program to scan I2C devices and show the list of found devices? Use the Polling method. Set I2C clock frequency 100KHZ & Master mode



#define RCC_APB1ENR (*((int *)0x40023840))
#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODE (*((int *)0x40020400))
#define GPIOB_AFRL (*((int *)0X40020420))
#define I2C1_CR1 (*((int *)0x40005400))
#define I2C1_CR2 (*((int *)0x40005404))
#define I2C1_SR1 (*((int *)0x40005414))
#define I2C1_SR2 (*((int *)0x40005418))	
#define I2C1_DR (*((int *)0x40005410))
#define I2C1_OAR1 (*((int *)0x40005408))
#define I2C1_CCR (*((int *)0x4000541C))	
#define GPIOB_OTYPER (*((int *)0x40020404))
#define RCCAHB1ENR (*(int *)0x40023830)
#define GPIOB_MODER (*(int *)0x40020400)
#define GPIOB_ODR (*(int *)0x40020414)	

char device=0;

void init()
{
	RCC_AHB1ENR = RCC_AHB1ENR | (0x1<<1);
	while(!(RCC_AHB1ENR & (0x1<<1)))
	{
		;
	}	
	RCC_APB1ENR = RCC_APB1ENR | (0x1<<21);
	while(!(RCC_APB1ENR & (0x1<<21)))
	{
		;
	}	
}
void mux()
{
	GPIOB_MODE &= (0xffff0fff);
	GPIOB_MODE |= (0x0000A000);
	GPIOB_OTYPER &=(0xffffff3f);
	GPIOB_OTYPER |=(0X000000c0);
	GPIOB_AFRL &= (0x00ffffff); 
	GPIOB_AFRL |= (0x44000000); 
	I2C1_CCR &=~(0x1<<15);
	I2C1_CCR |=(0x50);
	I2C1_CR2 &=~(0x3f);
	I2C1_CR2 =(0x10);
	I2C1_CR1 &=~(0x01);
	I2C1_CR1 =(0x01);
}

void delay(int n)
{
	int i=0;
	for(;i<=1670*n;i++)
	{
		;
	}
}

int KM_I2C_IsDeviceReady(int DevAddress,unsigned int Timeout)

{
	int Dummy_read=0;
	I2C1_CR1 |=0x1<<10;
	I2C1_CR1 |=0x1<<0;

	while((I2C1_SR2 & (0x1<<1)))
	{
		;
	}
	I2C1_CR1 |=0x1<<8;
	while(!(I2C1_SR1 & (0x1)))
	{
		;
	}	
	Dummy_read = I2C1_SR1; 
	I2C1_DR = (DevAddress);
	while((!(I2C1_SR1 & (0x1<<1)) && (!(I2C1_SR1 & (0x1<<10)))) && Timeout)		
	{
		Timeout--;
		delay(1);
		if(Timeout <1)
		{
			return 0;
		}          
	}
	if((I2C1_SR1&(0X1<<1)))
	{
		I2C1_CR1 |=0x1<<9;
		return 1;

	}
	else
	{
		I2C1_SR1 &=~(0X1<<10);
		I2C1_CR1 |=0x1<<9;
		return 0;
	}
	return 0;
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
void KM_LCD_Write_Str1(char ch[])
{
	int i;
	for(i=0;ch[i]!='\0';i++)
	{
		KM_LCD_Write_data(ch[i]);
	}
}
void KM_LCD_Write_Str(char ch)
{
	int i;
	{
		KM_LCD_Write_data(ch);
	}
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

int main()
{
	int i,k=0,s=200;
	char c,c1,c2;
	GPIOB_Init();
	KM_LCD_Init();
	init();
	mux();
	for(i=0;i<128;i++)
	{
		k=i<<1;
		if(KM_I2C_IsDeviceReady(k,s)==1)
		{
			device= i;
			if(device==80)
			{
				KM_LCD_Write_Str1("EPROM found");
				KM_LCD_Write_CMD(0x10);
				delay(5000);
			}	
			KM_LCD_Write_CMD(0x01);	
			if(i==104)
			{
				KM_LCD_Write_Str1("RTC found");
				KM_LCD_Write_CMD(0x01);
				delay(1000);
			}
		}
	}
}

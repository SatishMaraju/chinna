/*  Draw Block Diagram, pseudo code, Flowchart and write an Embedded C program and read
temperature value from LM35 Temperature sensor every 5 sec delay and send to LCD and
Kernel Masters webserver?
Hint: Write separate source file for every peripheral.
Example: SysTickTimer.c, lcd.c, adc.c , wifi.c , uart.c, main.c     */



***********  adc.c ***********


#include"all.h"


void adc_init(void)
{
	RCC_APB2ENR|=(0x01<<8); //enable ADC clock
	ADC_CR2|=(0x01<<0);//set oth bit
	ADC_CR2|=(0x01<<1);//set 1st bit
	ADC_CR2|=(0x01<<10);//set 10th bit
  ADC_SQR3=10;
}



void MUX_init(void)
{
	 RCC_AHB1ENR |=(0x01<<2);//enable port c clock
	 GPIOC_MODE&=0xfffffffc;//clear 1-0 positions 
	GPIOC_MODE|=0x00000003;//load "11" in 1-0 positions on GPIOC_MODE
}
void RCC_Init(void)
{
RCC_AHB1ENR |=(0x01<<1);
RCC_AHB1ENR |=(0x01<<2);
GPIOB_MODE &=0xFFFCF000;
GPIOB_MODE |=0x00010555; 
GPIOC_MODE &=0xFFFCFFFF;
GPIOC_MODE |=0X00000000;
GPIOC_PUPDR &=0xFFCFFFFF;
GPIOC_PUPDR |=0x00100000;
GPIOB_ODR &=~(0x13<<4); 
}

********************************************************************************************************************************************************************************************************

**************** all.h ************

#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
	
#define GPIOB_MODE (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
	
#define GPIOC_MODE (*((int *)0x40020800))
#define GPIOC_IDR (*((int *)0x40020810))	
#define GPIOC_PUPDR (*((int *)0x4002080C))
	
#define STK_CTRL (*((int *)0xE000E010))
#define STK_LOAD (*((int *)0xE000E014))	
#define STK_VAL  (*((int *)0xE000E018))
	

	
#define ADC_SR     (*((int *)0x40012000))
#define ADC_CR1    (*((int *)0x40012004))
#define ADC_CR2    (*((int *)0x40012008))
#define ADC_SMPR1    (*((int *)0x4001200c))
#define ADC_SMPR2    (*((int *)0x40012010))
#define ADC_DR     (*((int *)0x4001204c))
#define ADC_SQR1     (*((int *)0x4001202c))
#define ADC_SQR2    (*((int *)0x40012030))
#define ADC_SQR3    (*((int *)0x40012034))
#define NVIC_ISER0 (*((int *)0xE000E100))
	

#define GPIOC_AFRL  (*(int *)0x40020820)
#define UART6_SR    (*(int *)0x40011400)
#define UART6_DR    (*(int *)0x40011404)
#define UART6_BRR   (*(int *)0x40011408)
#define UART6_CR1   (*(int *)0x4001140C)
#define UART6_CR2   (*(int *)0x40011410)


	
	
void Write_high_nibble(unsigned char ch);
void Write_low_nibble(unsigned char ch);
void KM_LCD_Write_CMD(unsigned char ch);
void KM_LCD_Write_data(unsigned char  ch);
void KM_LCD_Write_Str(char *ch);
void KM_LCD_Init(void);
void GPIOB_Init(void);
void delay(int a);

void transmit_char(unsigned char ch);
unsigned char receive_char(void);
void transmit_outsting(char ch[]);
int receive_outchar(void);
int wifi(int );
	
	void adc_init(void);
 void MUX_init(void);
 void RCC_Init(void);

void systick_timer();
void km_udelay(int );
void km_mdelay(int );

void usart6(void);


******************************************************************************************************************************************************************************************************

************* lcd.c **************

#include"all.h"
void GPIOB_Init()
{
	RCC_AHB1ENR |=(0x01<<1);
GPIOB_MODE &=0xFFFCF000;
GPIOB_MODE |=0x00010555;
}
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

*********************************************************************************************************************************************************************************************************

**************** main.c ***************


#include"all.h"

	int result,count,x;
	char a,b;
	unsigned int k;
	char str[2];
	char Fetch[200];
	static char buffer[200];
	#include<stdio.h>
	
int main()
{
	int i=1;
	MUX_init();
	adc_init();
	RCC_Init();
	KM_LCD_Init();
	usart6();
  systick_timer();
 
	while(i<8)
		{
		x=wifi(i);
			if(x==0)
			{
				i++;
			}
			else
			{
			km_mdelay(100);
			while(!(STK_CTRL&(0x01<<16)))
				{
					;
				}		
			}
		 }
		
	 ADC_CR2|=(0x01<<30);
	while(1)	
	{	
		
	 while(!((ADC_SR&(0x01<<1))))
	 {
		 ;
	 }
		result=ADC_DR ;
		k=(result*3000)/(4096*10);
		 a=(char)((k%10)+48);
	      b=(char)(((k/10)%10)+48);
		  str[0]=b;
		  str[1]=a;
		KM_LCD_Write_CMD(0x01);
		KM_LCD_Write_Str(str);
		KM_LCD_Write_Str(" TEMP IN C");
	transmit_outsting("AT+CIPSTATUS\r\n");
		
		 for(i=0;i<200;i++)
		{
			buffer[i]=receive_char();
			if(buffer[i]=='K' && buffer[i-1]=='O')
			{
				break;
			}
		}
		
			transmit_outsting("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
		
		 for(i=0;i<200;i++)
		{
			buffer[i]=receive_char();
			if(buffer[i]=='K' && buffer[i-1]=='O')
			{
				break;
			}
		}
		
		transmit_outsting("AT+CIPSEND=41\r\n");
				sprintf(Fetch,"GET /page.php?temp=%d&hum=40&dev=10\r\n\r\n",k);
		  delay(500);
			transmit_outsting(Fetch);
       delay(4000);
		
		transmit_outsting("AT+CLOSE\r\n");
		 for(i=0;i<200;i++)
		{
			buffer[i]=receive_char();
			if(buffer[i]=='K' && buffer[i-1]=='O')
			{
				break;
			}
		}
		delay(4000);
 }
 }

 
*********************************************************************************************************************************************************************************************************


********************** systick_timer.c *********************


#include"all.h"


	void CLK_init(void)
{
	RCC_AHB1ENR = RCC_AHB1ENR | (0x01 << 1); // port B clock enable
	STK_CTRL |= 0X00000005;
	STK_VAL |=0X229;	
}	


void LED_config(void)
{
	GPIOB_MODE  &= 0xF3FFFFFF; // making 27,26 bit fields in port B clear
	GPIOB_MODE  |= 0x04000000; // load 01 into 27, 26 bit fields in port B
}	
void km_mdelay(int m)
{
	  
STK_LOAD=16000*m;

}

void km_udelay(int n)
{
	  
STK_LOAD=16*n;

}

void systick_timer()
{
	CLK_init();
	LED_config();
}


*******************************************************************************************************************************************************************************************************

************ usart.c ***************


 #include"all.h"
 
void UART6_MODE_Init(void)
{
	RCC_AHB1ENR |= 0x01<<2;								//clock enable for Port C
	while(!(RCC_AHB1ENR & 0x01<<2))  			//wait until bit is set
	{ 
			;
	}
	GPIOC_MODE |= 0x0000A000;						//alternate function mode PC6, PC7
	GPIOC_AFRL |= 0x88000000;						//PC6 acts as TX, PC7 acts as RX	
}	
 
void UART6_Config(void)
{
	RCC_APB2ENR |= (0x01 << 5);					 //UART6 clock enable.
	while(!(RCC_APB2ENR & (0x01<<5)))  	//wait until bit is set
	{
			;
	}
	UART6_CR1 |= 0x0C;									//TX, RX enable
	UART6_BRR |= 0x87;									//Baud rate
	UART6_CR1 |= (0x01<<13);						//UART enable
}	



	void transmit_char(unsigned char ch)
	{
		while(!(UART6_SR&(0x01<<7)))
		{
			;
		}
		UART6_DR = ch;
	}
	
	unsigned char receive_char(void)
	{
		
		while(!(UART6_SR&(0x01<<5)))
		{
			;
		}
			return UART6_DR ;
	}
	
void transmit_outsting(char ch[])
{
	  int i;
	   for(i=0;ch[i]!='\0';i++)
	     {
				 transmit_char(ch[i]); 
			 }
}
		
void usart6()
  {
	
	UART6_MODE_Init();
	UART6_Config();
		
		}	
			
**********************************************************************************************************************************************************************************************************


****************** wifi.c ******************


 #include"all.h"
char buffer[200];
    int i;

int wifi(int i)
{
	if(i==1)
	{
  transmit_outsting("AT\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }
	km_mdelay(400);
				while(!(STK_CTRL&(0x01<<16)))
				{
					;
				}		
	
	 if(i==2)
	{
		transmit_outsting("AT+CWMODE=3\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }	
	
	
	 if(i==3)
	{
		transmit_outsting("AT+CWJAP=\"KM-2.4G4F\",\"9963111084\"\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }

 if(i==4)
	{
		transmit_outsting("AT+CIFSR\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }
	
	
	if(i==5)
	{
		transmit_outsting("AT+CIPMUX=0\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }
	
	if(i==6)
	{
		transmit_outsting("AT+CIPMODE=0\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }
	return 0;
}




	int receive_outchar()
	 {
		for(i=0;i<200;i++)
		{
			buffer[i]=receive_char();
			if(buffer[i]=='K' && buffer[i-1]=='O')
			{
				return 0;
			}
		}
		return -1;
 	}


*********************************************************************************************************************************************************************************************************

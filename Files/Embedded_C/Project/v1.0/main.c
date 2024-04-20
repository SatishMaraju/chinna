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

 



#include"SysTickTimer.h"
#include"lcd.h"
#include"adc1.h"
#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOC_MODE (*((int *)0x40020800))
#define GPIOC_PUPDR (*((int *)0x4002080c))
#define GPIOC_IDR (*((int *)0x40020810))
static int ss,mm,hh,WD,DD,MM,YY,z;
static char str[3];
extern unsigned char T_date[20];


void Task5_SWMS_init()
{


	RCC_AHB1ENR = RCC_AHB1ENR | (0x1<<2);
	while(!(RCC_AHB1ENR & (0x1<<2)));

	GPIOC_MODE &= 0xFFC0FFFF;
	GPIOC_MODE |= 0x00000000;
	GPIOC_PUPDR &= 0xFFC0FFFF;
	GPIOC_PUPDR |=0X00150000;
}
	
	
	
	
void Task5_SWMS_Config()
{
	
	Task5_SWMS_init();
  KM_LCD_String("   WELCOME TO ");
	KM_LCD_write_cmd(0XC0);
	KM_LCD_String(" KERNENEL MASTERS ");
	KM_mdelay(3000);
	KM_LCD_write_cmd(0X01);
	
 KM_LCD_String(" ENTER SWITCH_ENT ");
	while((GPIOC_IDR &(0x01<<10)))
	{
		;
	}
		KM_LCD_write_cmd(0X01);
	
		KM_LCD_String(" HH:MM:SS ");
		KM_LCD_write_cmd(0XC0);
		KM_LCD_String(" 00:00:00 ");
while(1)
   {
	   while(1)
	     {
		 if(!(GPIOC_IDR &(0x01<<8)))
	     {
				 KM_LCD_write_cmd(0XC6);
	      KM_LCD_String(":");		
				  ss++;
				 str[0]=(char)(ss/10+48);
				 str[1]=(char)(ss%10+48);
				 KM_LCD_String(str);
				 KM_mdelay(700);

			 }
			 if(!(GPIOC_IDR &(0x01<<9)))
	     {
				 KM_LCD_write_cmd(0XC6);
	       KM_LCD_String(":");		
				 ss--;
				 str[0]=(char)(ss/10+48);
				 str[1]=(char)(ss%10+48);
				 KM_LCD_String(str);
				 KM_mdelay(700);
			 }
			 
			 if(!(GPIOC_IDR &(0x01<<10)))
			 {
				 break;
			 }
	 }
	
	 KM_mdelay(900);
	KM_mdelay(900);
	  while(1)
	   {
		if(!(GPIOC_IDR &(0x01<<8)))
	     {
				  KM_LCD_write_cmd(0XC3);
	       KM_LCD_String(":");
				 mm++;
				 str[0]=(char)(mm/10+48);
				 str[1]=(char)(mm%10+48);
				 KM_LCD_String(str); 
				 KM_mdelay(700);
			 }
			 
		if(!(GPIOC_IDR &(0x01<<9)))
	     {
				  KM_LCD_write_cmd(0XC3);
	        KM_LCD_String(":");
				mm--;
				 str[0]=(char)(mm/10+48);
				 str[1]=(char)(mm%10+48);
				 KM_LCD_String(str); 
				 	KM_mdelay(700);
			 }
		if(!(GPIOC_IDR &(0x01<<10)))
			 {
				 break;
			 }
	 }
	     KM_mdelay(900);
	     KM_mdelay(900);
	 
	while(1)
	{
		if(!(GPIOC_IDR &(0x01<<8)))
	     {
				 KM_LCD_write_cmd(0XC1);
				 hh++;
				 str[0]=(char)(hh/10+48);
				 str[1]=(char)(hh%10+48);
				 KM_LCD_String(str); 
				 	KM_mdelay(700);
			 }
			 
		if(!(GPIOC_IDR &(0x01<<9)))
	     {
				 KM_LCD_write_cmd(0XC1);
				 hh--;
				str[0]=(char)(hh/10+48);
				 str[1]=(char)(hh%10+48);
				 KM_LCD_String(str); 
				 KM_mdelay(700);
			 }
		if(!(GPIOC_IDR &(0x01<<10)))
			 {
				 break;
			 }
	 }
	  KM_LCD_write_cmd(0X8B);
	  KM_LCD_String("Y-UP"); 
	 	KM_LCD_write_cmd(0XCB);
    KM_LCD_String("N-DN"); 
	 
	 while(1)
	 {
		 if(!(GPIOC_IDR &(0x01<<8)))
		 {
			 z=1;
			 break;
		 }
		 if(!(GPIOC_IDR &(0x01<<9)))
		 {
			 break;
		 }
	 }
	 
	 if(z==1)
	 {
		 KM_LCD_write_cmd(0X01);
		 break;
	 }
	 
 }
	 //FOR DATE
 
	 KM_LCD_write_cmd(0X80);
 KM_LCD_String(" YY:MM:DD:WD ");
		KM_LCD_write_cmd(0XC0);
 KM_LCD_String(" 00:00:00:00 ");
  while(1)
   {
		 while(1)
	     {
		 if(!(GPIOC_IDR &(0x01<<8)))
	     {
				 KM_LCD_write_cmd(0XC9);
	      KM_LCD_String(":");		
				  WD++;
				 str[0]=(char)(WD/10+48);
				 str[1]=(char)(WD%10+48);
				 KM_LCD_String(str);
				 KM_mdelay(700);

			 }
			 if(!(GPIOC_IDR &(0x01<<9)))
	     {
				 KM_LCD_write_cmd(0XC6);
	       KM_LCD_String(":");		
				 ss--;
				 str[0]=(char)(WD/10+48);
				 str[1]=(char)(WD%10+48);
				 KM_LCD_String(str);
				 KM_mdelay(700);
			 }
			 
			 if(!(GPIOC_IDR &(0x01<<10)))
			 {
				 break;
			 }
	   }
			 
	  KM_mdelay(900);
	KM_mdelay(900);
		 
	   while(1)
	     {
		 if(!(GPIOC_IDR &(0x01<<8)))
	     {
				 KM_LCD_write_cmd(0XC6);
	      KM_LCD_String(":");		
				  DD++;
				 str[0]=(char)(DD/10+48);
				 str[1]=(char)(DD%10+48);
				 KM_LCD_String(str);
				 KM_mdelay(700);

			 }
			 if(!(GPIOC_IDR &(0x01<<9)))
	     {
				 KM_LCD_write_cmd(0XC6);
	       KM_LCD_String(":");		
				 DD--;
				 str[0]=(char)(DD/10+48);
				 str[1]=(char)(DD%10+48);
				 KM_LCD_String(str);
				 KM_mdelay(700);
			 }
			 
			 if(!(GPIOC_IDR &(0x01<<10)))
			 {
				 break;
			 }
	 }
	
	 KM_mdelay(900);
	  KM_mdelay(900);
	  while(1)
	   {
		if(!(GPIOC_IDR &(0x01<<8)))
	     {
				  KM_LCD_write_cmd(0XC3);
	       KM_LCD_String(":");
				 MM++;
				 str[0]=(char)(MM/10+48);
				 str[1]=(char)(MM%10+48);
				 KM_LCD_String(str); 
				 KM_mdelay(700);
			 }
			 
		if(!(GPIOC_IDR &(0x01<<9)))
	     {
				  KM_LCD_write_cmd(0XC3);
	        KM_LCD_String(":");
				MM--;
				 str[0]=(char)(MM/10+48);
				 str[1]=(char)(MM%10+48);
				 KM_LCD_String(str); 
				 	KM_mdelay(700);
			 }
		if(!(GPIOC_IDR &(0x01<<10)))
			 {
				 break;
			 }
	 }
	     KM_mdelay(900);
	     KM_mdelay(900);
	 
	while(1)
	{
		if(!(GPIOC_IDR &(0x01<<8)))
	     {
				 KM_LCD_write_cmd(0XC1);
				 YY++;
				 str[0]=(char)(YY/10+48);
				 str[1]=(char)(YY%10+48);
				 KM_LCD_String(str); 
				 	KM_mdelay(700);
			 }
			 
		if(!(GPIOC_IDR &(0x01<<9)))
	     {
				 KM_LCD_write_cmd(0XC1);
				 YY--;
				str[0]=(char)(YY/10+48);
				 str[1]=(char)(YY%10+48);
				 KM_LCD_String(str); 
				 KM_mdelay(700);
			 }
		if(!(GPIOC_IDR &(0x01<<10)))
			 {
				 break;
			 }
	 }
	  KM_LCD_write_cmd(0X8C);
	  KM_LCD_String("Y-UP"); 
	 	KM_LCD_write_cmd(0XCC);
    KM_LCD_String("N-DN"); 
	 
	 while(1)
	 {
		 if(!(GPIOC_IDR &(0x01<<8)))
		 {
			 z=1;
			 break;
		 }
		 if(!(GPIOC_IDR &(0x01<<9)))
		 {
			 break;
		 }
	 }
	 
	 if(z==1)
	 {
		 KM_LCD_write_cmd(0X01);
		 break;
	 }
	 
 }
	  T_date[0]=((ss/10)*16+(ss%10));
    T_date[1]=((mm/10)*16+(mm%10));
    T_date[2]=((hh/10)*16+(hh%10));
    T_date[3]=((WD/10)*16+(WD%10));
    T_date[4]=((DD/10)*16+(DD%10));
    T_date[5]=((MM/10)*16+(MM%10));
    T_date[6]=((YY/10)*16+(YY%10));
 }


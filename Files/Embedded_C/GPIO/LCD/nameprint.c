#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0X40020414))
#define SYS_CTRL (*((int *)0XE000E010))	
#define SYS_LOAD (*((int *)0XE000E014))	
#define SYS_VAL (*((int *)0XE000E018))	

void KM_DELAYM(int n);
void init()
{
	RCC_AHB1ENR|=0x2;
	while((RCC_AHB1ENR&0x2)==0)
	{
	;
	}
}


void config()
{
	GPIOB_MODER &=0xFFFFEC00;
	GPIOB_MODER|=0x00010555;
	SYS_CTRL&=~(0x00000005);
	SYS_CTRL|=0x00000005;
	//SYS_VAL=0x232;
}

void KM_DELAYM(int n)
{
		SYS_VAL=0x232;

	SYS_LOAD=n*16000;
	while((SYS_CTRL&0x1<<16)==0);
}
void write_high_nibble(unsigned char data)
{
		GPIOB_ODR&=0xfffffff0;
		data = data>>4;
		GPIOB_ODR |=data;
		GPIOB_ODR|=0x00000100;
	  KM_DELAYM(10);
	  GPIOB_ODR&=~(0x1<<8);
}
void write_low_nibble(unsigned char data)
{
	
		GPIOB_ODR&=0xfffffff0;
		data &=0x0F;
		GPIOB_ODR |=data;
		GPIOB_ODR|=0x00000100;
		KM_DELAYM(10);
	  GPIOB_ODR&=~(0x1<<8);
}
void KM_LCD_write_cmd(unsigned char data)
{
	GPIOB_ODR&=0xfffffecf;

	write_high_nibble(data);
	write_low_nibble(data);
}

void KM_LCD_write_data(unsigned char data)
{
	GPIOB_ODR&=0xfffffecf;
	GPIOB_ODR|=0x00000010;
	write_high_nibble(data);
	write_low_nibble(data);
}
void KM_LCD_write_string(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		KM_LCD_write_data(str[i]);
	}
}
 

int main ()
{
	init();
	config();
	KM_DELAYM(20);
 	KM_LCD_write_cmd(0x33);
	KM_DELAYM(2);
	KM_LCD_write_cmd(0x32);
	KM_LCD_write_cmd(0x0C);
	KM_LCD_write_cmd(0x01);
	KM_LCD_write_cmd(0x80);
	KM_LCD_write_string("hai everyone");
	KM_LCD_write_cmd(0xC0);
	KM_LCD_write_string(" happy diwali");

}


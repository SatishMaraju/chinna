#define RCC_AHB1ENR *(int *)0x40023830
#define RCC_APB2ENR *(int *)0x40023844
#define GPIOB_MODER *(int *)0x40020400
#define GPIOA_MODER *(int *)0x40020000
#define GPIOA_AFRH *(int *)0x40020024
#define USART1_SR *(int *)0x40011000
#define USART1_DR *(int *)0x40011004
#define USART1_BRR *(int *)0x40011008
#define USART1_CR1 *(int *)0x4001100C
int fun();

void RCC_init()
{
	RCC_AHB1ENR |= 0x1;
	RCC_AHB1ENR |= 0x1<<1;
	RCC_APB2ENR |= 0x1<<4;
}
void MUX_init()
{
	GPIOA_MODER &=~(0xCC<<18);
	GPIOA_MODER |=(0xA<<18);
	GPIOB_MODER &=~(0xCC<26);
	GPIOA_AFRH &=~(0x77<<4);
	GPIOA_AFRH |=0x77<<4;
	USART1_BRR =0x683;
	USART1_CR1 |=0x200C;
}
void UART6_OutChar(char data)
{
	while((USART1_SR&0x1<<7)==0);
	USART1_DR=data;
}

void UART6_OutStr(char *ch)
{
	int i;
	for(i=0;ch[i]!='\0';i++)
	{
		UART6_OutChar(ch[i]);
	}
}
void UART6_OutDec(char *ch)
{
	int i;
	for(i=0;ch[i]!='\0';i++)
	{
		UART6_OutChar(ch[i]);
	}
}
void UART6_OutOct(char *ch)
{
	int i;
	for(i=0;ch[i]!='\0';i++)
	{
		UART6_OutChar(ch[i]);
	}
}
void UART6_OutHex(char *ch)
{
	int i;
	for(i=0;ch[i]!='\0';i++)
	{
		UART6_OutChar(ch[i]);
	}
}

int main()
{
	RCC_init();
	MUX_init();
	fun();

}

#include<stdio.h>
#include<stdarg.h>
void UART6_OutStr(char *ch);
void UART6_OutDec(char *ch);
void UART6_OutHex(char *ch);
void UART6_OutOct(char *ch);
void UART6_OutChar(char );
void Myprintf(char *,...); //Our printf function
char* convert(unsigned int, int); //Convert integer number into octal, hex, etc.
int fun()
{
	Myprintf(" Kernel Masters \n %d\t %c\t %x\t %o\t %s",-8, 's', 64, 8,"satish");
	return 0;
}
void Myprintf(char* format,...)
{
	char *traverse;
	int i;
	char *s;
	//Module 1: Initializing Myprintf's arguments
	va_list arg;
	va_start(arg, format);
	for(traverse = format; *traverse != '\0'; traverse++)
	{
		while( *traverse != '%' )
		{
			UART6_OutChar(*traverse);
			traverse++;
		}
		traverse++;
		//Module 2: Fetching and executing arguments
		switch(*traverse)
		{
			case 'c' : i = va_arg(arg,int); //Fetch char argument

				   UART6_OutChar(i);
				   break;

			case 'd' : i = va_arg(arg,int); //Fetch Decimal/Integerargument

				   if(i<0)
				   {
					   i = -i;
					   UART6_OutChar('-');
				   }
				   UART6_OutDec(convert(i,10));
				   break;

			case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation

				  UART6_OutOct(convert(i,8));
				  break;

			case 's': s = va_arg(arg,char *); //Fetch string

				  UART6_OutStr(s);
				  break;

			case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimalrepresentation

				  UART6_OutHex(convert(i,16));
				  break;

		}
	}
	//Module 3: Closing argument list to necessary clean-up
	va_end(arg);
}
char *convert(unsigned int num, int base)
{
	char Representation[]= "0123456789ABCDEF";
	char buffer[50];
	char *ptr;
	ptr = &buffer[49];
	*ptr = '\0';
	do
	{
		*--ptr = Representation[num%base];
		num /= base;
	}while(num != 0);
	return(ptr);
}


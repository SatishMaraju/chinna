/*   Write a pseudo code and Embedded C program to SPI1 Configuration using the below conditions,
     And transmit character ‘A’ and Receive same character using hardware Loop back.
     a. Full duplex comm.
     b. Motorola Frame format
     c. Enable Polling (nothing but disable SPI Interrupts)
     Short PA6 & PA7 pins

     PA4 - SPI1_NSS
     PA5 - SPI1_SCK
     PA6 - SPI1_MISO
     PA7 - SPI1_MOSI               */



#define RCC_AHB1ENR *(int *)0x40023830
#define RCC_APB2ENR *(int *)0x40023844
#define GPIOA_MODER *(int *)0x40020000
#define SPI1_DR *(int *)0x4001300C
#define GPIOA_AFLR *(int *)0x40020020
#define SPI1_CR1 *(int *)0x40013000
#define SPI1_SR *(int *)0x40013008
#define SPI1_CR2 *(int *)0x40013004

void mux_init();
void KM_SPI_OUT(unsigned char);
unsigned char KM_SPI_IN();
char ch;
//int data;
int main()
{
	RCC_APB2ENR |= 0x1<<12;
	RCC_AHB1ENR |= 0x1;
	mux_init();
	while(1)
	{
		KM_SPI_OUT('A');
		ch=KM_SPI_IN();
	}

}
void KM_SPI_OUT(unsigned char data)
{
	while(!(SPI1_SR & 0x1<<1))
	{
		;	
	}
	SPI1_DR=data;
}

unsigned char KM_SPI_IN(void)
{
	while((SPI1_SR&0x01)==0)
	{
		;
	}
	return SPI1_DR;
}

void mux_init()
{
	GPIOA_MODER &=~(0xFF<<8);
	GPIOA_MODER |=(0xAA<<8);
	GPIOA_AFLR &=~(0xFFFF<<16);
	GPIOA_AFLR |=0x5555<<16;
	SPI1_CR2 |= 0x1<<2;
	//SPI1_CR1 =0x0<<3;

	//SPI1_CR1 |=0x1<<11;
	SPI1_CR1 |=0x1<<6;
	SPI1_CR1 |=0x1<<2;
	//SPI1_CR2 |= 0x1<<2;

}


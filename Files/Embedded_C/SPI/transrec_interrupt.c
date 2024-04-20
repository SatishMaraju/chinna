/* Write a pseudo code and Embedded C program to SPI1 Configuration using the below conditions,
   And transmit character ‘A’ and Receive same character using hardware Loop back.
   a. Full duplex comm.
   b. Motorola Frame format
   c. Enable Polling (nothing but disable SPI Interrupts)
   Short PA6 & PA7 pins

   PA4 - SPI1_NSS
   PA5 - SPI1_SCK
   PA6 - SPI1_MISO
   PA7 - SPI1_MOSI

   Experiment 2:  Above lab experiment with SPI Rx Interrupt. */



#define RCC_AHB1ENR *(int *)0x40023830
#define RCC_APB2ENR *(int *)0x40023844
#define GPIOA_MODER *(int *)0x40020000
#define GPIOA_AFRL *(int *)0x40020020
#define SPI1_CR1 *(int *)0x40013000
#define SPI1_CR2 *(int *)0x40013004	
#define SPI1_SR *(int *)0x40013008
#define SPI1_DR *(int *)0x4001300C
#define GPIOC_MODER *(int *)0x40020800
#define GPIOC_IDR *(int *)0x40020810
#define GPIOC_PUPDR *(int *)0x4002080C
#define GPIOB_MODER *(int *)0x40020400
#define GPIOB_ODR *(int *)0x40020414

char ch=0;
void delay();
void RCC_init()
{
	RCC_AHB1ENR |= 0x7;
	while((RCC_AHB1ENR & 0x7)==0)
	{
		;
	}	
	RCC_APB2ENR |= 0x1<<12;
	while((RCC_APB2ENR & 0x1<<12)==0)
	{
		;
	}	
}
void delay(int a)
{
	int n;
	n=a*1670;
}

void MUX_init()
{
	GPIOA_MODER |=~(0xff);
	GPIOA_MODER |=(0xAA<<8);
	GPIOA_AFRL |=0x5555<<16;
	SPI1_CR1 &=~(0x1<<6);
	SPI1_CR1 &=~(0x1<<2);
	SPI1_CR2 |=0x1<<2;
	SPI1_CR1 |=0x1<<2;
	SPI1_CR1 |=0x1<<6;
	GPIOB_MODER &=0xc3ffffff;
	GPIOB_MODER |=0x14000000;
	GPIOC_MODER &=0Xfff0ffff;
	GPIOC_MODER |=0X00000000;
	GPIOC_PUPDR &=0xfff0ffff;
	GPIOC_PUPDR |=0x00050000;
}
void KM_SPI_IN(void)
{
	while((SPI1_SR&0x1)==0)
	{
		;
	}	
	if(SPI1_DR=='R'){
		GPIOB_ODR &=~(0x1<<13);
		delay(100);
		GPIOB_ODR |=0x1<<14;}
	if(SPI1_DR=='G'){
		GPIOB_ODR &=~(0x1<<14);
		delay(100);
		GPIOB_ODR |=0x1<<13;}
}
void KM_SPI_OUT(void)
{
	{
		if((GPIOC_IDR &0x1<<8)==0){
			SPI1_DR='R';}
		if((GPIOC_IDR &0x1<<9)==0){
			SPI1_DR='G';}
	}
	while ((SPI1_SR&0x2)==0)
	{
		{
			;
		}	
		if((SPI1_DR='G')||(SPI1_DR='R'))
			KM_SPI_IN();
	}
}

int main()
{
	RCC_init();
	MUX_init();

	while(1)
	{
		KM_SPI_OUT();
		//KM_SPI_IN();

	}
}


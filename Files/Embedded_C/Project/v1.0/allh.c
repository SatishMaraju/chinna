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





/* Lab Experiment 8: Write a program Request an interrupt on the Falling edge of ENTER Switch, whenever the user
button is pressed and increment a counter in the interrupt and RED LED is ON.   */


#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODE (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
#define GPIOC_MODE (*((int *)0x40020800))
#define GPIOC_PUPDR (*((int *)0x4002080c))
#define GPIOC_IDR (*((int *)0x40020810))
#define NVIC_ISER1 (*((int *)0xE000E104))
#define EXTI15_10 (*((int *)0x000000E0))
#define SYSCFG_EXTICR3 (*((int *)0x40013810))
#define EXTI_IMR (*((int *)0x40013C00))
#define EXTI_PR (*((int *)0x40013C14))
#define EXTI_FTSR (*((int *)0x40013C0C))
#define RCC_APB2ENR (*((int *)0x40023844))

int counter=0;
void RED_init(void)
{
RCC_AHB1ENR = RCC_AHB1ENR | (0x1<<1);
while(!(RCC_AHB1ENR & (0x1<<1)))
{
;
}
}

void GPIO_init(void)
{

RCC_AHB1ENR = RCC_AHB1ENR | (0x1<<2);
while(!(RCC_AHB1ENR & (0x1<<2)))
{
;
}
}

void SW_INT_init(void)
{
RCC_APB2ENR |= (0x00004000);
while(!(RCC_APB2ENR & (0x1<<14)))
{
;
}
SYSCFG_EXTICR3 &= 0xFFFFF0FF;
SYSCFG_EXTICR3 |= 0x00000200;
EXTI_FTSR |= (0x1<<10);
EXTI_IMR |= (0x1<<10);
NVIC_ISER1 |= (0x1<<8);
}

void delay()
{
int i;
for(i=0;i<600000;i++)
{
;
}
}

void RED_config(void)
{
GPIOB_MODE &= 0xF3FFFFFF;
GPIOB_MODE |= 0x04000000;
GPIOC_MODE &= 0xFFCFFFFF;
GPIOC_MODE |= 0x00000000;
GPIOC_PUPDR &= 0xFFCFFFFF;
GPIOC_PUPDR |=0X00100000;
}

int main()
{
RED_init();
GPIO_init();
RED_config();
SW_INT_init();
GPIOB_ODR |= (0x1<<13);
while(1)
{
;
}
}
void EXTI15_10_IRQHandler(void)
{
if(EXTI_PR & (0x1<<10))
{
counter++;
GPIOB_ODR &= ~(0x1<<13);
EXTI_PR |= (0x1<<10);
delay();
}
}


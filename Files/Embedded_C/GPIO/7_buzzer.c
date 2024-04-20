Whenever SW_ENT Press turn ON BUZZER up to 250msec and Turn OFF BUZZER.



#define RCC_AHB1ENR *(int *)0x40023830
#define GPIOB_MODE *(int *)0x40020400
#define GPIOB_ODR *(int *)0x40020414
#define GPIOC_MODER *(int *)0x40020800
#define GPIOC_IDR *(int *)0x40020810
#define PUPDR *(int *)0x4002080c



void red_init(void);
void red_config(void);
void delay(int a);  // Correct the function signature

int main() {
    red_init();
    red_config();
		GPIOB_ODR &= ~(0x1 << 12);

    while (1) {
        if ((GPIOC_IDR & (0x1 << 10)) == 0)
					{
            GPIOB_ODR |= 0x1 << 12;
            delay(250);   
						}
				GPIOB_ODR &= ~(0x1 << 12);
    }
}

void red_init(void) {
    RCC_AHB1ENR |= (0x6);
    while (!(RCC_AHB1ENR & 0x6)) {
    }
}

void red_config(void) {
    GPIOB_MODE = GPIOB_MODE & 0xfcffffff;
    GPIOB_MODE |= 0x01000000;
    GPIOC_MODER &= 0xffcfffff;
    GPIOC_MODER |= 0x00000000;
		PUPDR &=0xFFCFFFFF;
		PUPDR |=0x00100000;
}

void delay(int a) {
    int i;
    for (i = 0; i < (2500 * a); i++) {
    }
}

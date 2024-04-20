#include "SysTickTimer.h"
#include "LCD_code.h"

int count=0;
int main()
{
	//phase 1: Initialization phase
	RCC_init();
	LCD_config();
	STK_Timer_init();
	KM_LCD_init();
	//operation phase
	KM_LCD_String("KERNEL MASTERS");
	return 0;
}


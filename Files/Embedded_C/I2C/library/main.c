//#include"lcd.h"
#include"SysTickTimer.h"
#include"i2c.h"
unsigned char T_date[]={0x21,0x05,0x4,0x07,0x25,0x11,0x23};
unsigned char rtc_data[20];
int res;

int main()
{
	//KM_LCD_Init();
	STK_Timer_init();
	KM_mdelay(200);
	KM_I2C1_Init();
	KM_I2C1_Config();
	res=KM_I2C_Mem_Write((0x68<<1),0x00,0x01,T_date,7);
	while(1)
	{
	res=KM_I2C_Mem_Read( 0x68, 0x00, 0x01, rtc_data, 7); 
	KM_mdelay(1000);
	}
}

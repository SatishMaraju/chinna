Company: Fervid Smart Solutions     Date:26/03/2024 

1)Write the charecteristics of Diode.
2)Draw the truth table of EX-OR and ENCODER.
ans--> EX-OR				ENCODER
	inputs    output		y0   y1      
	0   0       0			0     0    x0
	0   1       1			0     1    x1
	1   0       1			1     0    x2
	1   1       0			1     1    x3
3)What is volatile and constant keyword.

ans--> The 'const' keyword in C is used to define constant values that cannot be changed at runtime. it is write protected
genarally compiler optimize the veriables when ever we declare with volatile its tells the compiler dont optimize the veriable becuase veriable value may be change at anytime due to external
factors so u all ways pick the variable value form the memory.

4)Draw the block diagram of half bridge,full bridge rectifier.

5)What happens if we change the address of EEPROM then how it can be interface.
ans--> Interface is possible but we should know about that address.
6)What is the formula to convert the ADC signal into Digital.

ans--> (adc value * vref)/(reselution) *100

7)Given the vref and find the resolution value.

8)Draw the diagram for PNP and NPN transistor.

9)They have given 4  programs on function pointers and structures and asked whether the warnings and errors are there And finally resolve the code.

ans--> 4 programs excicuted

10)If we have two EEPROM's with the same addresses and how do we find the value of that particular EEPROM.
ans--> By using the strting sequence address of the EEPROM.
11)Difference between SPI and I2C.

ans--> I2C is a two-wire protocol and SPI is a four-wire protocol. I2C supports clock stretching and SPI does not have clock stretching. I2C is slower than SPI. I2C has an extra overhead start and
stop bits and SPI does not have any start and stop bits.

12)What is the I2C clock speed.

ans--> 100khz

13)What if we have 2 UART devices and each one is connected to the individual Grounds and supply voltages.

ans--> i told the communication is not posible if the both UART have same baud rate after that he said ok but diffrent voltage and diffrent grounds he asked i told its also not posible

14)What is the size of RTC.

ans--> 64Byte

15)Frame formats of I2C and UART.

ans--> for I2C--> start bit--slave address--read/write--ack--reg address--ack--data--ack--stop
for UART--stat-->5 to 8bit data--parity--stop

16)Which protocol can be used to communicate with the device When it's distance is 10cm.

ans--> i uses UART,beacuse there is 1 to 1 communication there is no need to varry about slaves and its addresses
if multi slave are there i use I2C to communicate

17)CODE:
struct student{
	int a;
	char b;
	int c;
}s;
--> What is the size of structure with padding in 32 bit system. ans: 12 bytes
--> What is the size of structure with padding in 16 bit system. ans: 6 bytes
--> What is the size of structure without padding. ans: 9 bytes

18)What is Multiplexer and De-multiplexer.

ans--> A multiplexer is a device that selects one of several input signals and forwards it to a single output line.
A demultiplexer is a device that takes a single input and distributes it to one of several output lines.

19)void fun1()
{
	fun2();
}
int main()
{
	void fun1();
}
void fun2()
{
	fun1();
}
Is there any warnings from above code.
ans--> fun2() should be declared before using
**************************************************** Technical Round 3 ******************************************************************************

1) Self Introduction.
2) They have Given Code to solve based on funnction poiners.
3) Frame format of UART.
4) if the voltage is 2.5v give 10C at what voltage does the 20C occurs.
5) How do you configure the Wi-Fi.
6) Copy the content of a.txt into b.txt in lsp.
7) Which protocol is used in TFT display interfacing.
8) What is the differences between SPI and I2C protocols.
9) Suppose we have PA-7 is connected to switch and PA-8 is connected to LED. On the LED whenever thee switch is pressed.
10) What is Zigbee protocol.

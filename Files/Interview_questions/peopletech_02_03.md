1. Is clock used in CAN protocol ?
ans:No because it is a Asyncronous.

2. What is an Identifier ?
Ans. An identifier is a name which can be used to assign the value, and also for naming the functions.

3. What is structure padding ?
ans. It is nothing but the unused memory allocation between the members of a structure.

4. How to avoid the Structure padding ?
ans. By using the pragma mmacro
	#pragma pack(1)

5. Declare an array of 5 integers and print the 1st index value without using the index method.
Ans. int arr[5]={1,2,3,4,5};
	int *p=&arr;
	printf("%d",*(p+1));

6. What is the difference between the SPI and UART protocol.
	SPI: it is 4 wire communication protocol and it is full duplex and asynchronous. There is no limits for slaves. It's speed is about 10-20 Mbps.
	UART: It is a 3 wire communication protocol which be used for medium and long distance communication and has the speed of 115Kbps.

7. What is the speed of the I2C ?
ans. There are different modes of speeds like
	1.Standard mode : 100Kbps
	2.Fast Mode : 400Kbps
	3.Fast mode plus : 1Mbps
	4.High Speed mode : 3.3Mbps
	5. Ultra fast mode : 5Mbps.
mostly we are using standard mode.

8. Why we are using mostly standard mode in I2C protocol.
ans. Because the data manipulation may not occur in standard mode. that to it doesnot have any error control technique.

9. What is CAN protocol ?
ans. It is a 2 wire communication and it has error control technique and also it is a Asynchronous.
	1.CANH - for 11 bit
	2.CANL - for 29 bit

10. How to impliment CAN protocol in real time ?
11. What is the logic does CAN follows ?
12 . About my B.tech project ?
13. What is system call ?
ans. A system call can be used to interact with the hardware through kernel and allows the user to rewuest for the resources. Because an user can't directly communicate with the hardware. For that purpose We use can use the mediator to communcate with hardware.

14. Who is that mediator ?
ans.Kernel.

14. What is Booting ?
ans. It can load the OS into memory.

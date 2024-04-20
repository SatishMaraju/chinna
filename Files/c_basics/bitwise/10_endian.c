//WAP to convert Little endian integer to Big endian integer.


#include<stdio.h>
int main()
{
	unsigned int a;
	scanf("%x",&a);
	//b=(a<<24)|(a>>24)|((a<<8)&0x00ff0000)|((a>>8)&0x0000ff00);
	printf("%x",(a<<24)|(a>>24)|((a<<8)&0x00ff0000)|((a>>8)&0x0000ff00));
}

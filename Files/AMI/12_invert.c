//  Invert a bit in a given byte.


#include<stdio.h>
int main()
{
	int n,b;
	printf("enter the number: ");
	scanf("%d",&n);
	printf("enter the bit number: ");
	scanf("%d",&b);
	printf("%d",n);
	n=n^(1<<b);
	for(int i=0;i<sizeof(int)*8;i++)
	{
	if(n&(0x1<<(sizeof(int)*8-1))){
	printf("1");n=n<<1;}
	else{
	printf("0");
	n=n<<1;}
	}
}

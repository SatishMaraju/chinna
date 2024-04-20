//WAP Check if the 20th bit of a 32-bit integer is on or off?


#include<stdio.h>
int main()
{
	int a;
	printf("enter a:");
	scanf("%d",&a);
	if(a&(0x1<<19))
		printf("ON");
	else
		printf("OFF");
}

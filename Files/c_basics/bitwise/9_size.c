//WAP to implement the sizeof operation using the bitwise operator.


#include<stdio.h>
int main()
{
	//char x=1;
	//short int x=1;
	//long int x=1
	int x=1,count=0;
	while(x)
	{
		x=x<<1;
		count++;
	}
	printf("%d\n",count/8);
}

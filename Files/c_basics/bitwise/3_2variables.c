/*  Write a printbinary(int , int ) function consists of 2 integer variables. First one is value of the variable and second one is  size of variable. 
Example: 
char x=5; 
printbinary(x,sizeof(x)); 
output:  00000101      */


#include<stdio.h>
void printbinary();
int main()
{
	int x;
	printf("enyter value:");
	scanf("%d",&x);
	printbinary(x,sizeof(x));
	sizeof(x);
}
void printbinary(int x,int size)
{
	int i,count=0;
	for(i=0;i<sizeof(x)*8;i++)
	{
		if(x&(0x1<<(sizeof(x)*8)-1))
			printf("1");
		else
			printf("0");
		x=x<<1;
	}
}

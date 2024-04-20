#include<stdio.h>
int fun(int,int,int);
int main()
{
	int a=10,b=20;
	fun(a=b,a=0,a=b+10);
}
int fun(int x,int y,int z)
{
	printf("%d\t%d\t%d\n",x,y,z);
}

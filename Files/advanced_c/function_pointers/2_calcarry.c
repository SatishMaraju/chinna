// Rewrite the calculator program using an array of function pointers.

#include<stdio.h>
#include<string.h>
int add(int ,int );
int sub(int ,int );
int mul(int ,int );
int div(int ,int );
int mod(int ,int );
int main()
{
	int a,b,i;
	int (*p[]) (int ,int )={add,sub,mul,div,mod};
	printf("enter a,b:");
	scanf("%d%d",&a,&b);
	for(i=0;i<5;i++)
	{
		printf("%d\t",(p[i])(a,b));}
}





int add (int x,int y)
{
	return x+y;}
int sub (int x,int y)
{
	return x-y;}
int mul (int x,int y)
{
	return x*y;}
int div (int x,int y)
{
	return x/y;}
int mod (int x,int y)
{
	return x%y;}


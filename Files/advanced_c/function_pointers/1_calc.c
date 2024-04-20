// Write the calculator program using function pointers for add, sub, mul, div and mod functions, using a single function pointer.


#include<stdio.h>
#include<string.h>
int add(int ,int );
int sub(int ,int );
int mul(int ,int );
int div(int ,int );
int mod(int ,int );
int main()
{
	int a,b;
	int (*p) (int ,int );
	printf("enter a,b:");
	scanf("%d%d",&a,&b);
	p=add;
	printf("%d\t",p(a,b));
	p=sub;
	printf("%d\t",p(a,b));
	p=mul;
	printf("%d\t",p(a,b));
	p=div;
	printf("%d\t",p(a,b));
	p=mod;
	printf("%d\t",p(a,b));
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

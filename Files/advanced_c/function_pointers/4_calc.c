/*  Write the calculator program using a function that accepts an array of function pointers and the operand values and operator character as arguments and invokes appropriate function based on the character. In main function, simply invoke this function by sending the array and operator character and operands as input.
    eg.,
    in main
    case '+' :invokeptr( fparr, x,y, ch);


    invokeptr(int (*fptr[]) (int,int) , int x, int y ,char ch)
    {
//based on ch value, choose which index to apply on fptr and invoke the function
}
 */


#include<stdio.h>
#include<string.h>
int add(int ,int );
int sub(int ,int );
int mul(int ,int );
int div(int ,int );
int mod(int ,int );
int invokeptr(int (*ptr[])(int x,int y),int x,int y,char c);
int main()
{
	int a,b;
	char c;
	int (*ptr[5]) (int ,int )={add,sub,mul,div,mod};
	printf("enter a,b:");
	scanf("%d%d",&a,&b);
	printf("enter operator:");
	scanf(" %c",&c);
	invokeptr(ptr,a,b,c);	




}
int invokeptr(int (*ptr[])(int x,int y),int x,int y,char z)
{
	switch(z)
	{
		case '+':printf("%d",ptr[0](x,y));break;
		case '-':printf("%d",ptr[1](x,y));break;
		case '*':printf("%d",ptr[2](x,y));break;
		case '/':printf("%d",ptr[3](x,y));break;
		case '%':printf("%d",ptr[4](x,y));break;

	}}


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


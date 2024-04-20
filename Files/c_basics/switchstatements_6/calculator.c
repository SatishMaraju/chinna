//Write the calculator program using switch case statement.


#include<stdio.h>
int main()
{
	int a,b;
	char ch;
	printf("enter the numbers a,b and charecter:");
	scanf("%d %c %d",&a,&ch,&b);
	switch(ch)
	{
	case '+':printf("result:%d",a+b);
	break;
	case '-':printf("result:%d",a-b);
	break;
	case '*':printf("result:%d",a*b);
	break;
	case '/':printf("result:%d",a*b);
	break;
	case '%':printf("result:%d",a%b);
	break;
	default:printf("invalid");
}}

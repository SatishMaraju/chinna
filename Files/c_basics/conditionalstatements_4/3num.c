//C program to find Largest among three numbers Using if else

#include<stdio.h>
int main()
{
	int a,b,c, larg;
	printf("Enter Three Number\n");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
	if(a>c)
        larg = a;
	else
        larg = c;
	}
	else
	{
	if(b>c)
        larg = b;
	else
        larg = c;
	}
	printf("%d is largest number",larg);
	return 0;
}

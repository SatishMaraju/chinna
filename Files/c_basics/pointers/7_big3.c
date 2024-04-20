//  Write a program to find the biggest of three numbers using pointers that point to those numbers.


#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter a,b  and c:\n");
	scanf("%d%d%d",&a,&b,&c);
	int *p1=&a;
	int *p2=&b;
	int *p3=&c;
	if(*p1>*p2)
	{
		if(*p1>*p3)
		{
			printf("big:%d",*p1);}

			else
				printf("big:%d",*p3);}
	else if(*p2>*p3)
		printf("big:%d",*p2);
	else
		printf("big:%d",*p3);
}

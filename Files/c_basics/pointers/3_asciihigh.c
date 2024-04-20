//Write a program to take input for two character variables using pointers and find out which character has higher ascii value.


#include<stdio.h>
int main()
{
	char ch1,ch2;
	printf("enter ch1 and ch2:\n");
	scanf(" %c %c",&ch1,&ch2);
	char *p1=&ch1;
	char *p2=&ch2;
	if(*p1>*p2)
		printf(" %c\n %d\n",*p1,*p1);
	else
		printf(" %c\n %d\n",*p2,*p2);
}

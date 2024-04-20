//Write a program to add two variables using their pointers.


#include<stdio.h>
int main()
{
	int x,y;
	printf("enter x and y\n");
	scanf("%d%d",&x,&y);
	int *p1=&x;
	int *p2=&y;
	printf("result:%d\n",*p1+*p2);
}

/*   Take three input integers x,y and z. Write a program to rotate their values such that, x has the value of y, y has the value of z and z has the value of x. Do this using pointers that point to x,y and z.   */


#include<stdio.h>
int main()
{
	int a,b,c,temp;
	printf("enter a,b and c\n");
	scanf("%d%d%d",&a,&b,&c);
	int *p1=&a;
	int *p2=&b;
	int *p3=&c;
	temp=*p1;
	*p1=*p2;
	*p2=*p3;
	*p3=temp;
	printf("%d\t%d\t%d\n",*p1,*p2,*p3);
}


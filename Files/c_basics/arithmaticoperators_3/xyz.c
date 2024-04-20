//Take three input integers x,y and z. Write a program to rotate their values such that, x has the value of y, y has the value of z and z has the value of x.


#include<stdio.h>
int main()
{
	int x,y,z,a;
	printf("enter the numbers x y and z:");
	scanf("%d%d%d",&x,&y,&z);
	a=x;
	x=y;
	y=z;
	z=a;
	printf("the result of x y and z:%d\n %d\n %d\n",x,y,z);
	return 0;
}

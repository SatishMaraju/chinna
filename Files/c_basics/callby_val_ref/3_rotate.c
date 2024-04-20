//Write a function that can rotate the values of three variables. print the results in the main function.



#include<stdio.h>
void rotate();
int main()
{
	int a,b,c;
	printf("enter a,b and c\n");
	scanf("%d%d%d",&a,&b,&c);
	rotate(&a,&b,&c);
	printf("a:%d\tb:%d\tc:%d\n",a,b,c);
}

void rotate(int *p1,int *p2,int *p3)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=*p3;
	*p3=temp;
	printf("x:%d\ty:%d\ty:%d\n",*p1,*p2,*p3);
}


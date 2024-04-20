//Write a program to swap two numbers using Call by Value and Call by Reference.


#include<stdio.h>
void swap();
int main()
{
int a=10,b=20;
swap(&a,&b);
printf("a:%d\tb:%d\n",a,b);
}

void swap(int *p1,int *p2)
{
int temp;
temp=*p1;
*p1=*p2;
*p2=temp;
printf("*p1:%d\t*p2:%d\n",*p1,*p2);
}

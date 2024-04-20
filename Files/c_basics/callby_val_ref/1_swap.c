//Write a program to swap two numbers using Call by Value and Call by Reference.


#include<stdio.h>
void swap();
int main()
{
int a=10,b=20;
swap(a,b);
printf("a:%d\tb:%d\n",a,b);
}

void swap(int x,int y)
{
int temp;
temp=x;
x=y;
y=temp;
printf("x:%d\ty:%d\n",x,y);
}

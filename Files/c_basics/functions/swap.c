//Write a function ,that can take two integers, swap their values and print their new values. return type should be void. function should print the values.

#include<stdio.h>
void swap(int a,int b)
{
int temp;
temp=a;
a=b;
b=temp;
printf("a:%d\nb:%d\n",a,b);
return;
}
int main()
{
int a,b,s;
printf("enter a and b:\n");
scanf("%d%d",&a,&b);
swap(a,b);
return 0;
}


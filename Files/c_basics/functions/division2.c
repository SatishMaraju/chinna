//Write a function that takes two numbers a and b, and returns the remainder after dividing a with b.


#include<stdio.h>
int exa(int a,int b)
{
int c;
c=a%b;
return c;
}
int main()
{
int a,b,result;
printf("enter a and b\n");
scanf("%d%d",&a,&b);
result=exa(a,b);
printf("Remainder is:%d\n",result);
return 0;
}


//Write a function that takes two numbers a and b as input arguments and returns their product as return value , without using * operator.


#include<stdio.h>
int exa(int a,int b)
{
int i,temp=0;
for(i=1;i<=b;i++)
temp=temp+a;
return temp;
}
int main()
{
int a,b,result;
printf("enter a and b\n");
scanf("%d%d",&a,&b);
result=exa(a,b);
printf("%d",result);
return 0;
}


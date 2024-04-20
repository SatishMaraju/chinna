//Write a function that takes two numbers, a and n as input arguments and returns the value of a to the power of n.


#include<stdio.h>
int power(int a,int n)
{
int i,temp=1;
for(i=1;i<=n;i++)
temp=temp*a;
return temp;
}
int main()
{
int a,n,result;
printf("enter base and power\n");
scanf("%d%d",&a,&n);
result=power(a,n);
printf("the result is:%d\n",result);
return 0;
}


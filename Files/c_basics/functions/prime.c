/* write a function that can take an integer as input and return 1 if the number is prime number,  return 0 if it is not prime and print appropriate output message in main according to output.
return type is integer. function name IsPrime - returns int (0 or 1) */

#include<stdio.h>
int prime(int a)
{
int i,count=0,ret=1;
for(i=1;i<=a;i++)
{
if (a%i==0)
count++;
}
if(count==2)
return ret;
else
ret=0;
return ret;
}
int main()
{
int a,s;
printf("enter a:");
scanf("%d",&a);
s=prime(a);
if(s==1)
printf(" prime number:%d\n",s);
else
printf("not prime number:%d\n",s);
return 0;
}

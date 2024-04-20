/*  print the output in the format shown below.
i/p: 123456
o/p: one lakh twenty three thousand four hundred and fifty six
*/


#include<stdio.h>
#include<string.h>
int main()
{
int n,s=0,t;
printf("enter the number: ");
scanf("%d",&n);
while(n)
{
t=n%10;
s=s*10+t;
n=n/10;
}
while(s)
{
t=s%10;
s=s/10;
switch(t)
{
case 0:printf("zero");break;
case 1:printf("one");break;
case 2:printf("two");break;
case 3:printf("three");break;
case 4:printf("four");break;
case 5:printf("five");break;
case 6:printf("six");break;
case 7:printf("seven");break;
case 8:printf("eight");break;
case 9:printf("nine");break;
}}
}

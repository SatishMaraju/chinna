//Write down a macro to find the biggest of four numbers using biggest of 2 macro.


#include<stdio.h>
#define MAX(x,y) x<y
int main()
{
int a,b,c,d;
printf("enter a,b,c and d:\n");
scanf("%d%d%d%d",&a,&b,&c,&d);
if(MAX(a,b))
a=b;
if(MAX(a,c))
a=c;
if(MAX(a,d))
a=d;
printf("%d",a);
}


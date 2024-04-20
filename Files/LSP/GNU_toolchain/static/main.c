#include<stdio.h>
int add(int,int);
int sub(int,int);
int main()
{
int a,b;
printf("enter a and b:");
scanf("%d %d",&a,&b);
printf("%d\n",add(a,b));
printf("%d",sub(a,b));
}

//Write a function that takes an integer number as input and prints its multiplication table.return type is  void.


#include<stdio.h>
void table(int a)
{
int i;
for(i=1;i<=10;i++)
printf("%d*%d=%d\n",a,i,a*i);
}
int main()
{
int a;
printf("enter a\n");
scanf("%d",&a);
table(a);
return 0;
}


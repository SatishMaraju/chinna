/*  print the below patterns using nested for loop and break:
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5    */


#include<stdio.h>
int main()
{
	int a,b,c;
	printf("value of c:");
	scanf("%d",&c);
	for(a=1;a<=c;a++)
	{
	for(b=1;b<=a;b++)
	printf("%d",b);
	printf("\n");
}}

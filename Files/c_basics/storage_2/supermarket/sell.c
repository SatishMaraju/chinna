#include<stdio.h>
#include"header.h"

extern int stock;
int s;
int sell()
{
	printf("Enter the Required no.of Items:");
	scanf("%d",&s);
	if(stock>=s)
	{
		printf("%d items has been saled\n",s);
		deletestock(s);
		return 1;
	}
	else
	{
		printf("Not Enough Stock");
	}
}


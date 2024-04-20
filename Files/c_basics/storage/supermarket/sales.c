#include<stdio.h>
#include"header.h"

extern int stock;
void sell()
{
	int s;
	printf("Enter the Required no.of Items:");
	scanf("%d",&s);
	if(stock>=s)
	{
		printf("%d items has been saled\n",s);
		deletestock(s);
	}
	else
	{
		printf("Not Enough Stock");
	}
}


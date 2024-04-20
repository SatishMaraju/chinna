#include<stdio.h>
#include "header.h"

extern int stock;
int limit=1000;
int i;
int purchase()
{
	printf("Enter no.of items to be purchased:");
	scanf("%d",&i);
	if((i+stock)>limit)
	{
		printf("Storage is full purchasing not required\n");
		return 2;
	}
	else 
	{
		addstock(i);
		return 1;
	}
}


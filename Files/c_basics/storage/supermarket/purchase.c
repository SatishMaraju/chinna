#include<stdio.h>
#include "header.h"

extern int stock;
int limit=1000;
void purchase()
{
	int i;
	printf("Enter no.of items to be purchased:");
	scanf("%d",&i);
	if((i+stock)>limit)
	{
		printf("Storage is full purchasing not required\n");
	}
	else 
	{
		addstock(i);
	}
}


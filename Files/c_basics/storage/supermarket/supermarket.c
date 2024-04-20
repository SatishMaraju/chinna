#include<stdio.h>
#include"header.h"


extern int stock;
int main()
{
	int n;
	do
	{
		printf("Select a option from below Menu\n 1)Check Avaliability Stock\n 2)Purchase New Stock\n 3)Sell Items\n 4)Quit\n");
		scanf("%d",&n);
		if(n==1)
		{
			printf("The Avaliable Stock is %d\n",stock);
		}
		else if(n==2)
		{
			purchase();
		}
		else if(n==3)
		{
			sell();
		}
		else 
		{
			printf("Quitting from supermarket...\n");
			break;
		}
	}
	while(n);
	return 0;
}

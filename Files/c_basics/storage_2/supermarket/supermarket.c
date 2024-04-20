#include<stdio.h>
#include"header.h"


extern int stock;
int TS=0,CS=0,TP=0,CP=0;
extern int i;
extern int s;
int main()
{
	int n;
	char ch;
	do
	{
		printf("Select a option from below Menu\n 1)Check Avaliability Stock\n 2)Purchase New Stock\n 3)Sell Items\n 4)Quit\n");
		l1:scanf("%d",&n);
		if(n==1)
		{
			printf("The Avaliable Stock is %d\n",stock);
		}
		else if(n==2)
		{
			if(purchase()==1)
			{
			CP++;
			TP=TP+i;}
		}
		else if(n==3)
		{
			if(sell()==1)
			{
			CS++;
			TS=TS+s;}
	

		}
		else 
		{
			printf("current stock:%d\n",stock);
			printf("Total sales made today:%d\n",TS);
			printf("No.of times salesmade today:%d\n",CS);
			printf("Total Purchase made today:%d\n",TP);
			printf("Total no.of times purchase was done:%d\n",CP);
			//break;
			scanf(" %c",&ch);
			if(ch=='y')
			goto l1;
			else if(ch=='n')
			return 0;
		}
	}
	while(n);
	return 0;
}

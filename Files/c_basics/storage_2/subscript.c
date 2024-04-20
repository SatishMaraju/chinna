#include<stdio.h>
extern int i;
int subscript()
{
	int n;
	n=i%10;
	switch(n)
	{
		case 1:printf("I am called %dth time\n",i);
		       if(i==11||i==12||i==13){
			printf("I am called %dth time\n",i);}break;
		case 2:printf("I am called %dnd time\n",i);break;
		case 3:printf("I am called %drd time\n",i);break;
		default:printf("I am called %dth time\n",i);
			return 0;
	}
 }

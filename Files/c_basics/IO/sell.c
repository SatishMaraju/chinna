/* sale price and profit of n items is given as inputs,  find the cost price of 1 item.
eg., number of items : 15
        sale price of 15 items : 500
        profit : 50
        cost price of each item: 30 */


#include<stdio.h>
int main()
{
	float sell,profit,cost;
	int a;
	printf("enter sell and profit\n");
	scanf("%f%f",&sell,&profit);
	printf("enter the a value\n");
	scanf("%d",&a);
	cost=(sell-profit)/a;
	printf("cost is:%f\n",cost);
	return 0;
}
	
	

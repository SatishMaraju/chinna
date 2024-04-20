/*Find the power bill for the input number of units :
0 - 200 units : 100/- min
201 - 400 units : 100 + 0.65 per unit excess of 200
401 - 600 units : 230 + 0.80 per unit excess of 400
601 and above units : 390 + 1.00 per unit excess of 600 */



#include<stdio.h>
int main()
{
	int units;
	float bill;
	printf("enter no.of units:");
	scanf("%d",&units);
	if(units>=0&&units<=200)
	printf("%f\n",bill=100);
	else if(units>200&&units<=400)
{
	printf("%f\n",100+(units-200)*0.65);
}
	else if(units>400&&units<=600)
{
	printf("%f\n",230+(units-400)*0.80);
}
	else if(units>600)
{
	printf("%f\n",390+(units-600)*1.0);
}
	else
	printf("invalid");
return 0;
}

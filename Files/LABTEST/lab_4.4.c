//find the power without using * , / and inbuilt funtions.



#include<stdio.h>
int main()
{
	int base,power;
	int answer,increment;
	printf("Enter the base value: ");
	scanf("%d",&base);
	printf("Enter the power value: ");
	scanf("%d",&power);	
	answer=base;
	increment=base;
	for (int i=1;i<power;i++)
	{
		for (int j=1;j<base;j++)
		{
			answer = answer + increment;
		}
		increment = answer;
	}
	printf("Power is: %d\n",answer);
}

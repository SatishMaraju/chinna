/*2) read an integer number, display the number as a number name expansion.
eg., 458 : four five eight*/

#include<stdio.h>
#include<string.h>

int main()
{
	int num,k;

	int i=0;
	printf("enter : ");
	scanf("%d",&num);
	char *number[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	int temp = num, count=0;
	while(temp)
	{
		temp=temp/10;
		count++;
	}

	int str[count];
	while(num)
	{
		str[i] = num%10 + '0';
		num = num/10;
		i++;
	}

	for (int j = 0; j < i / 2; j++)
	{
		char temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}
	for(i=0;i<count;i++)
	{
	k=str[i]-48;
	printf("%s ",number[k]);
	}
	printf("\n");

}

//Read a character and print if the given character is an alphabet or not.





#include<stdio.h>
int main()
{
	char c;
	printf("enter the charecter:");
	scanf("%c",&c);
	if(c<='z')
	{
	if(c>='a')
	printf("it is an alphabet:");
	else if(c<='Z')
	{
	if(c>='A')
	printf("it is alphabet");
	else
	printf("is is not alphabet");
	}
	else
	printf("it is not alphabet");
	}
	else
	{
	printf("it is not a alphabet:");
	}
	return 0;
	}

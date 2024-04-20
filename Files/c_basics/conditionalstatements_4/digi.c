// Read a character and print if the given character is a digit or not




#include<stdio.h>
int main()
{
	char ch;
	printf("enter the charecter:");
	scanf("%c",&ch);
	if(ch>='0')
	if(ch<='9')
	printf("it is a digit:");
	else
	printf("it is not a digit:");
	return 0;
}

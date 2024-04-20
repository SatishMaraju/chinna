//check if a character is alphabet or not


#include<stdio.h>
int main()
{
	char ch;
	printf("enter the charecter:");
	scanf("%c",&ch);
	ch>='a'?ch<='z'?printf("given is an alphabet"):printf("given is not an alphabet"):ch>='A'?ch<='Z'?printf("it ia alphabet"):printf("it is not alphabet"):printf("it is not alphabet");
	return 0;
}


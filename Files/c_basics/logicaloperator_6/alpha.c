//Read a character and print if it is alphabet or not.


#include<stdio.h>
int main()
{
	char ch;
	printf("enter the charecter:");
	scanf("%c",&ch);
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	printf("it is alphabet");
	else
	printf("it is not alphabet");
	return 0;
}

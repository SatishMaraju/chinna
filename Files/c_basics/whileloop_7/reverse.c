//read n characters from user and if the character is alphabet, then print its case reverse. if it is not a character, print it as it is.



#include<stdio.h>
int main()
{
	int i=1,n;
	char ch;
	printf("enter n value:");
	scanf("%d",&n);
	while(i<=n)
	{
	scanf(" %c",&ch);
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		if(ch>='a'&&ch<='z')
		printf("reverse: %c\n",ch-32);
		else
		printf("reverse: %c\n",ch+32);
	else
	printf("charecter is: %c\n",ch);
	i++;
}}

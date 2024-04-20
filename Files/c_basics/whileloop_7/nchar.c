//read n characters from user, and print if every character is alphabet / numeric / special character.


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
	printf("alphabet\n");
	else if(ch>='0'&&ch<='9')
	printf("numeric\n");
	else
	printf("special charecter:");
	i++;
}
}

//Input an alphabet. Output its case reverse.


#include<stdio.h>
int main()
{
	char x;
	printf("enter the charecter:");
	scanf("%c",&x);
	if(x>='A'&&x<='Z')
	printf("%c",x+32);
	else if(x>='a'&&x<='z')
	printf("%c\n",x-32);
	else
	printf("it is not alphabet");
	return 0;
}

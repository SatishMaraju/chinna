/*  Implement below functions using pointer increment or decrement method, use below declarations. Change function name.
 1) int strlen(char s[]);  */


#include<stdio.h>
#include<string.h>
int mystrlength(char *str);

int main()
{
	int i,j;
	char str[10];
	printf("Enter the string:");
	scanf("%[^\n]s",str);

	j=mystrlength(str);
	printf("Length is: %d\n",j);

}


int mystrlength(char *str)
{
	int i=0;
	while(*(str+i))
	{
		i++;
	}
	return i;
}

/*  sort the input string
Ex: i/p- helloworld
o/p- dehllloorw
 */

#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=0;
	char str[100];
	printf("enter the string: ");
	scanf("%[^\n]s",str);
	for(i=0;i<strlen(str);i++)
	{
		for(j=i+1;j<strlen(str);j++)
		{
			if(str[i]>str[j])
			{
				char t=str[i];
				str[i]=str[j];
				str[j]=t;
			}
		}
	}
	printf("%s",str);
}

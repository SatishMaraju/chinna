// WAP to count the no.of times the substring repeated in a given string.

#include <stdio.h>
#include <string.h>
int main()
{
	int x,y,z,i,j,c=0;
	char str[100];
	char sub[100];
	scanf(" %[^\n]s",str);
	scanf(" %[^\n]s",sub);
	x=strlen(str);
	y=strlen(sub);
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(str[i+j]==sub[j]) 
			{
				c++;
			}
			break;
		}
		if(c==y)
		{
			z++;
			c=0;
		}
	}
	printf("%d",z);
}


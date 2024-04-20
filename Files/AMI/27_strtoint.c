/*  convert string into integers
Input :one two three four five
Output : 12345
Take string as input one two three print as 123
 */


#include<stdio.h>
#include<string.h>
int main()
{
	int i,d,j=0,k=0;
	char s[1000];
	char a[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	char l[100];
	printf("enter the string: ");
	scanf("%[^\n]s",s);
	for(i=0;i<=strlen(s);i++)
	{
		if(s[i]!=' '&&s[i]!='\0')
		{
			l[k++]=s[i];
		}
		else{
			l[k++]='\0';
			k=0;
			for(d=0;d<=9;d++)
			{
				if(strcmp(l,a[d])==0)
				{
					printf("%d",d);break;
				}
			}
		}
	}
}

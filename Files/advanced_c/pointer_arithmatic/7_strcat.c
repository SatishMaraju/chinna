//7) char  * strcat(char d[], char s[]); // returns destination base address

#include<string.h>
#include<stdio.h>
char * mystrcat(char d[],char s[]);
int main()
{
	char d[100];
	char s[100];
	printf("Input : ");
	scanf("%[^\n]s",d);
	scanf(" %[^\n]s",s);
	mystrcat(d,s);
	printf("output :%s\n",d);

}

char * mystrcat(char d[],char s[])
{	int i=0,j,n;
	char *p;
	p=d;
	n=strlen(d);
	while(*(s+i))
	{
		*(d+n)=*(s+i);
		i++;
		n++;
	}
	*(s+i)='\0';
	return p;
}

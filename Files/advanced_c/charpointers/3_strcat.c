/*  Implement your own string concatenation function.
try calling the string copy function by sending the below as input:
1) string constant as destination and string variable as source
2) string variable as destination and string constant as source
3) string variable as destination and string variable as source
4) string constant as destination and string constant as source
note down the output and analyze the reasons.
*/



#include<string.h>
#include<stdio.h>
char * mystrcat(char *d,char *s);
int main()
{
	char d[20];
        char s[20];
	printf("enter destination: ");
	scanf("%[^\n]s",d);
	getchar();
	printf("enter source:");
	scanf("%[^\n]s",s);
	mystrcat(d,s);
	printf("%s\n",d);

}

char * mystrcat(char *d,char *s)
{	int i=0,j,n;
	n=strlen(d);
	while(*(s+i)!='\0')
	{
		*(d+n)=*(s+i);
		i++;
		n++;
	}
	*(d+n)='\0';
return d;
}




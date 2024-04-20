/*  sorting a list of names received from the keyboard, with options using callback functions.
1 :  sort with case sensitivity (strcmp)
*/



#include <stdio.h>
#include <string.h>


void csort(int (*fp)(const char *,const char *),char * (*f)(char *,const char *),int n,char name [n][100])
{
	char temp[100];
	int c;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			c=fp(name[i],name[j]);
			if(c>0)
			{
				f(temp,name[i]);
				f(name[i],name[j]);
				f(name[j],temp);
			}
		}
	}
}

int main()
{
	int n;
	int (*fp)(const char *,const char *)=strcmp;
	char * (*f)(char *,const char *)=strcpy;
	printf("Enter the no.of names:");
	scanf("%d",&n);
	char name[n][100];
	printf("Enter names:\n");
	for(int i=0;i<n;i++)
	{
		scanf(" %[^\n]s",name[i]);
	}
	csort(fp,f,n,name);
	for(int i=0;i<n;i++)
		printf("%s\n",name[i]);
	return 0;
}

// Print odd words on console from reading data from file.

#include<string.h>
#include<stdio.h>
int main()
{
	FILE *fp,*fp1;
	int c=0,i=0;
	char str[100],ch;
	fp=fopen("l1.txt","r");
	if(fp==NULL)
	{
		printf("error");
		return 1;
	}
	while(fscanf(fp,"%c",&ch)!=EOF)
	{
		str[i++]=ch;
		if(ch==' '||ch=='\n')
		{
			c=strlen(str);
			--c;
			if(c%2!=0)
			{
				printf("%s",str);
				i=0;
				printf(" ");
			}
		}
	}
	fclose(fp);
}

//  Read a file and delete all the odd words from the file.

#include<string.h>
#include<stdio.h>
int main()
{
	FILE *fp,*fp1;
	int c=0,i=0;
	char str[100],ch;
	fp=fopen("l1.txt","r");
	fp1=fopen("l2.txt","w");
	if(fp==NULL)
	{
		printf("error");
		return 1;
	}
	if(fp1==NULL)
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
			if(c%2==0)
			{
				//fputs(str,fp1);
				fprintf(fp1,"%s",str);i=0;
			}
		}
	}
	fclose(fp);
	fclose(fp1);
}

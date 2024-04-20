//read lines of data and write in file.


#include<stdio.h>
int main()
{
	FILE *fp;
	char str[1000];
	fgets(str,sizeof(str),stdin);
	fp=fopen("abc.txt","w");
	if(fp==NULL)
	{
		printf("error");
		return 1;
	}
	fputs(str,fp);
	fclose(fp);
}

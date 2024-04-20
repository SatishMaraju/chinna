// Read the contents of a file and copy to another file.

#include<stdio.h>
int main()
{
	char c;
	FILE *fp,*fp1;
	fp=fopen("source.txt","r");
	fp1=fopen("dest.txt","w");
	if(fp==NULL)
	{
		printf("bad actually");
	}
	else{
	while(1)
	{
		c=fgetc(fp);
		if(c==EOF)
			break;
		fputc(c,fp1);
	}}
return 0;
}

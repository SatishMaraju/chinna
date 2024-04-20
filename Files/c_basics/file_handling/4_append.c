// Create a new file using contents of two files.(append one file content to another, and write to a third file).


#include<stdio.h>
int main()
{
	char ch;
	FILE *fp,*fp1,*fp2;
	fp=fopen("one.txt","r");
	fp1=fopen("two.txt","r");
	fp2=fopen("three.txt","w");
	if(fp==NULL||fp1==NULL||fp2==NULL)
	{
		printf("bad actually");
	}
	else
	{
		while(1)
		{
			ch=fgetc(fp);
			if(ch==EOF)
			break;
			fputc(ch,fp2);
		}
		rewind(fp);
		while(1)
		{
			ch=fgetc(fp1);
			if(ch==EOF)
			break;
			fputc(ch,fp2);	
		}
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
}

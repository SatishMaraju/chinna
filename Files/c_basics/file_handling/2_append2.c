//  Open the file  in append mode, and write new numbers to it, and print entire content of the file.


#include<stdio.h>
int main()
{
	int x=0;
	FILE *fp;
	fp=fopen("append2.txt","a+");
	if(fp==NULL)
		printf("bad actually");
	else
	{
		scanf("%d",&x);
		putw(x,fp);
		rewind(fp);
		while(1)
		{
		x=getw(fp);
		if(x==EOF)
		break;
		printf("%d\t",x);
		}
	}
}

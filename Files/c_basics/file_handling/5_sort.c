/* Two files data1 and data2 contain sorted list of integers. Write a program to produce a third file data which holds a single,sorted, merged list of these two files. Use command line arguments to specify the file names.  */


#include<stdio.h>
int main(int argc,const char *argv[])
{
	int x,y;
	FILE *fp,*fp1,*fp2;
	fp=fopen(argv[1],"r");
	fp1=fopen(argv[2],"r");
	fp2=fopen(argv[3],"w");
	if(fp==NULL||fp1==NULL||fp2==NULL)
	{
		printf("bad actually");
		return 1;
	}
	while(1)
	{
		x=getw(fp);
		y=getw(fp1);
		if((x==EOF)&&(y==EOF))
		break;
		if((x<=y)||(y==EOF))
		putw(x,fp2);
		if((x>y)&&(y!=EOF))
		putw(y,fp2);
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
return 0;
}

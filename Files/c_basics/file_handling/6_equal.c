// Write a program that compares two files and returns 0 if they are equal and 1 if they are not equal.


#include<stdio.h>
int main()
{
	int x,y,z;
	FILE *fp,*fp1;
	fp=fopen("eq.txt","r+");
	fp1=fopen("eq1.txt","r+");
	if(fp==NULL||fp1==NULL)
	{
	printf("bad actually");
	}
	while(1)
	{
	x=getw(fp);
	y=getw(fp1);
	if(x==EOF||y==EOF){break;}
	if(x==y)
	z=1;
	else
	z=0;
	}
if(z==1)
printf("equal");
else
printf("no");
fclose(fp);
fclose(fp1);
}

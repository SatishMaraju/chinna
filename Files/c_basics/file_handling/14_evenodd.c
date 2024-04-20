//Read numbers entered by user and write to a file.Open the file and read the numbers and write even numbers to even file and odd numbers to odd file.


#include<stdio.h>
int main()
{
	int x=0,y=0;
	FILE *fp,*fp1,*fp2;
	fp=fopen("abc.txt","w+");
	fp1=fopen("even.txt","w+");
	fp2=fopen("odd.txt","w+");
	if(fp==NULL||fp1==NULL||fp2==NULL)
		printf("bad actually");
	else
	{
		while(1)
		{
			scanf("%d",&x);
			if(x==-1)
				break;
			putw(x,fp);
		}
		rewind(fp);
		while(1){
		x=getw(fp);
		if(x==EOF)
		break;
		if(x%2==0)
			putw(x,fp1);
		if(x%2!=0)
			putw(x,fp2);}
	}
	rewind(fp1);
	rewind(fp2);
	while(1)
	{
	x=getw(fp1);y=getw(fp2);
	if((x==EOF)&&(y==EOF))
	break;
	printf("%d\t%d\n",x,y);}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
}

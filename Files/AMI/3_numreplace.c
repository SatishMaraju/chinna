/* Assume that there is a file with 0 to 1000 numbers. Take input of two integers, and replace the first integer with next.
   Eg., 365 ,563
   365 must be replaced everywhere with 563.
 */


#include<stdio.h>
int main()
{
	int a,b,n;
	FILE *fp=fopen("abc.txt","r+");
	if(fp==NULL)
	{
		printf("no file");
		return 1;
	}
	printf("enter the number: ");
	scanf("%d",&a);
	printf("enter value: ");
	scanf("%d",&b);
	while(1)
	{
			fscanf(fp,"%d",&n);
			if(n==EOF)
			break;
			else if(n==a){
			fseek(fp,-4,SEEK_CUR);
			fprintf(fp,"%d",b);}
			else;
	}
	fclose(fp);
	fp=fopen("abc.txt","r+");
	while(1)
	{
		fscanf(fp,"%d",&n);
		if(n==EOF)
		break;
		printf("%d",n);
	}
fclose(fp);
}

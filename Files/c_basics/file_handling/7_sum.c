// Write a program that reads a file containing integers and appends the sum of all integers at the end.

#include <stdio.h>
#include <stdlib.h>

int main() 
{
	FILE *fp;
	int n,sum=0;
	fp = fopen("sum.txt","r");
	if (fp == NULL)
		printf("open fail");
	while (fscanf(fp,"%d",&n) != EOF) 
	{
		sum += n;
	}
	fclose(fp);
	fp = fopen("sum.txt","a");
	if (fp == NULL) 
		printf("open fail");
	fprintf(fp,"\nSum of integers: %d\n",sum);
	fclose(fp);
	printf("Sum appended successfully\n");
	return 0;
}

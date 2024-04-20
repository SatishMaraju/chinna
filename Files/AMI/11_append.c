//  Create a new file using contents of two files.(append one file content to another, and write to a third file).

#include<stdio.h>
int main()
{
	char n;
	FILE *fp,*fp1,*fp2;
	fp=fopen("l1.txt","a+");
	fp1=fopen("l2.txt","r");
	fp2=fopen("l3.txt","w");
	if(fp==NULL){
		printf("erroe");
		return 1;}
	if(fp1==NULL){
		printf("error");
		return 1;}
	if(fp2==NULL){
		printf("error");
		return 1;}
	while(fscanf(fp1,"%c",&n)!=EOF)
	{
		fprintf(fp,"%c",n);
	}
	rewind(fp);
	while(fscanf(fp,"%c",&n)!=EOF)
	{
	fprintf(fp2,"%c",n);
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
}

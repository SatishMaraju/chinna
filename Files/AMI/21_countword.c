// Count the number of words in a file.


#include<stdio.h>
int main()
{
	int a=0;
	char c;
	FILE *fp;
	fp=fopen("l1.txt","r");
	if(fp==NULL)
	{
		printf("error");
		return 1;
	}
	while(fscanf(fp,"%c",&c)!=EOF)
	{
		if(c==' '||c=='\n'){
		if(fscanf(fp,"%c",&c)!=EOF){
		a++;}}
	}
	printf("%d",a);
}

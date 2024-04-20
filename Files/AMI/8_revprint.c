/*  Read a file and print the file contents in reverse order.
Ex: file contains 0,1,2,3…..100
Print  100,99,………..0
 */


#include<stdio.h>
int main()
{
	int n;
	FILE *fp=fopen("abc.txt","r");
	if(fp==NULL)
	{
		printf("bad:");
		return 1;
	}

	fseek(fp,0,SEEK_END);
	while(1)
	{
		fseek(fp,-sizeof(int),SEEK_CUR);
		if(ftell(fp)<4)
		break;
		fscanf(fp,"%d",&n);
		printf("%d",n);
	}
	fclose(fp);
}

/* Take input from user,if user press 1 write the file from beginning.If press 2 and position,start writing from the given position
 */


#include<stdio.h>
int main()
{
	int a,p;
	char str[1000];
	FILE *fp;
	printf("press 1:begin 2:position: ");
	scanf("%d",&a);
	fp=fopen("l1.txt","w+");
	if(fp==NULL)
	{
		printf("error");
		return 1;
	}
	if(a==1)
	{
		printf("enter the string:");
		scanf(" %[^\n]s",str);
		fputs(str,fp);
	}
	if(a==2)
	{
	printf("enter the position");
	scanf("%d",&p);
	fseek(fp,p,SEEK_SET);
	printf("enter the string:");
	scanf(" %[^\n]s",str);
	fputs(str,fp);
	}
}

#include<stdio.h>
#include<stdlib.h>
char *fun(char *p1,char *p2);
int main()
{

	char *p1,*p2,*r;
	p1=(char *)malloc(30*sizeof(char));
	p2=(char *)malloc(30*sizeof(char));
	printf("enter 1st:");
	scanf("%s",p1);
	printf("enter 2nd:");
	scanf(" %s",p2);
	r=fun(p1,p2);
	printf("%s",r);
	free(p1);
	free(p2);
	free(r);
}
char *fun(char *p1,char *p2)
{
	int i,j,x;
	char *p3=(char *)malloc(30*sizeof(char));
	for(i=0;p1[i]!='\0';i++)
	{
		if((p1[i]>=65)&&(p1[i]<=90))
		{
			p1[i]=p1[i]+32;
			p3[x++]=p1[i];
		}
		else{
		p3[x++]=p1[i];}
	for(j=i;j<=i;j++)
	{
	if((p2[j]>=65)&&(p2[j]<=90))
	{
	p2[j]=p2[j]+32;
	p3[x++]=p2[j];
	}
	else
	p3[x++]=p2[j];
	}}
	for(j;p2[j]!='\0';j++)
	{
	p3[x++]=p2[j];
	}
	

return p3;
}
	

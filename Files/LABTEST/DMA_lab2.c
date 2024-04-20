#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * fun(char *p1,char *p2,char *p3);
int main()
{

	char *ptr,*ptr1,*p,*ptr2; 
	ptr=(char *)malloc(20*sizeof(char));
	ptr1=(char *)malloc(20*sizeof(char));
	ptr2=(char *)malloc(20*sizeof(char));


	printf("Enter string 1 : ");
	scanf("%[^\n]s",ptr);
	printf("Enter string 2 : ");
	scanf(" %c",ptr1);
	printf("Enter string 3 : ");
	scanf(" %[^\n]s",ptr2);
	p=fun(ptr,ptr1,ptr2);
	printf("%s\n",p);
	free(ptr);
	free(ptr1);
	free(ptr2);
	free(p);
	return 0;
}

char * fun(char *p1,char *p2,char *p3)
{

	char *p;
	int i,s0=0,s1,s2,s3,s=1;
	s1=strlen(p1);
	s2=strlen(p2);
	s3=strlen(p3);
	p=(char *)malloc(20*sizeof(char));
	int k=0,j=0,x=0;
	for (i=0;p1[i]!=0;i++)
	{	
		if (p1[i]==p2[0])
		{
				for(k=0;p3[k]!=0;k++)
				{
				p[x++]=p3[k];	
				}
			}
			else		                            
			p[x++]=p1[i];

		}
	

	return p;
}

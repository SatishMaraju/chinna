/*  Write a function, that takes two strings as input and concatenates only the first n characters from first string and first m characters from second string and makes a new string.
    eg., input str1 = "kernel masters", str2 = "raayan systems", n = 3, m = 5
output : kerraaya
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,j,m,n;
	char *p1=(char *)malloc(50*sizeof(char));
	char *p2=(char *)malloc(50*sizeof(char));
	char *p3=(char *)malloc(50*sizeof(char));
	printf("enter 1st strings:");
	scanf("%[^\n]s",p1);
	printf("enter 2nd string:");
	scanf(" %[^\n]s",p2);
	printf("enter 1st and 2nd limit:");
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
	p3[i]=p1[i];
	}
	p1[i]='\0';
	for(j=0;j<n;j++,i++)
	{
	p3[i]=p2[j];
	}
	p2[i]='\0';
	printf("%s",p3);

free(p1);
free(p2);
free(p3);
return 0;
}

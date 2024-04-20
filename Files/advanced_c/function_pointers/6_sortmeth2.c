/*6) sorting a list of names received from the keyboard, with options using callback functions.
 sort without case sensitivity (stricmp)
*/


#include<stdio.h>
#include<string.h>
void fun(int (*fp)(const char *,const char *),char *(*f)(char *,const char *),char ch[][10],int n)
{

	int i,j,c;
	char t[10],ch1[n][10];
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
		ch1[i][j] =  ch[i][j];
		}	
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			if(ch1[i][j]>64 && ch1[i][j]<91)
			ch1[i][j] += 32;
		}	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			c=fp(ch1[i],ch1[j]);
			if(c>0)
			{
			f(t,ch[i]);
			f(ch[i],ch[j]);
			f(ch[j],t);
			}
		}
	}
}
int main()
{
	int n,i,j,c;
	int (*fp)(const char *,const char *)=strcmp;
	char *(*f)(char *,const char *)=strcpy;
	scanf("%d",&n);
	char ch[n][10],t[10];
	printf("enter : ");
	for(i=0;i<n;i++)
	scanf(" %[^\n]s",ch[i]);

	fun(fp,f,ch,n);
	printf("\n");
	for(i=0;i<n;i++)
	printf("%s\n",ch[i]);
}

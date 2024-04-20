/*  Write a function to search for a specific element given by the user, in an array and display its index.  Function takes array and element to search as inputs, and returns the index as output. If element not found, return -1.   */

#include<stdio.h>
int search(int b[] ,int ,int );
int main()
{
	int n,i,e,s;
	printf("enter size:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter element to search index:");
	scanf("%d",&e);
	s=search(a,n,e);
	if(s!=-1)
		printf("%d",s);
	else
		printf("not valid");
	return 0;
}

int search(int b[],int n,int e)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(e==b[i])
			return i;}
	return -1;
}

// WAP to insert an element in an array at a particular position.


#include <stdio.h>

int main()
{
	int i=1,p,n,j,temp=0,l;
	printf("enter size");
	scanf("%d",&n);
	int arr[n+1];
	printf("enter the value position\n");
	scanf("%d%d",&l,&p);
	printf("enter the elemnts\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=n;i>p;i--)
	{

		arr[i]=arr[i-1];
	}
	arr[p]=l;

	for(i=0;i<n+1;i++)
		printf("%d\t",arr[i]);
}


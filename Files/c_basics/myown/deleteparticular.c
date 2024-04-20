//WAP to delete a particular element in an array.


#include <stdio.h>

int main()
{
	int i=1,p,n,j,temp=0,l;
	printf("enter size");
	scanf("%d",&n);
	int arr[n];
	printf("enter the position\n");
	scanf("%d",&p);
	printf("enter the elemnts\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	temp=arr[p];
	for(i=p;i<n;i++)
	{       
		arr[i]=arr[i+1];
	}
	arr[n-1]=temp;n--;

	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}

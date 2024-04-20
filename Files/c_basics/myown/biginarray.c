// WAP to print big number in an array.


#include <stdio.h>

int main()
{
	int i=1,p,n,j,temp=0,l;
	printf("enter size");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elemnts\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]<arr[j]){
			temp=arr[j];
			l=j;}
		}
	}

	//for(i=0;i<n;i++)
	printf("%d\t%d\n",temp,l);
}


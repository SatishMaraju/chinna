// WAP to arrange the elments in ascending order using arrays.

#include <stdio.h>

int main()
{
	int i,n,j,temp=0;
	scanf("%d",&n);
	int arr[n];
	printf("enter the elemnts\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{

			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}


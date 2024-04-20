// WAP to delete the duplicates in an array.


#include <stdio.h>

int main()
{
	int i=1,p,n,k,j,temp=0,l;
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
			if(arr[i]==arr[j])
			{
				temp=arr[j];
				for(k=j;k<n;k++)
					arr[k]=arr[k+1];
				arr[n-1]=temp;n--;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}


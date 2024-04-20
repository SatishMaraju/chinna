//writea function to take a array and rotate it to n times eg;- 123456 after rotate 2 times output be 345612//


#include<stdio.h>
void rotate(int arr[],int size,int d);
int main()
{
	int i,j,size,d;
	printf("ENter the size of the array");
	scanf("%d",&size);
	int arr[size];
	printf("The elements of the array");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("Enter the the rotate size");
	scanf("%d",&d);
	rotate(arr,size,d);
}

void rotate(int arr[],int size,int d)
{
	int i,j,temp=0;
	for(i=0;i<d;i++)
	{
		for(j=0;j<size-1;j++)
		{
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
	printf("The array after rotating %d times is:\n",d);
	for(i=0;i<size;i++)
	{
		printf("%d\n",arr[i]);
	}
}

//Write a program to print an integer in binary format using arrays.



#include<stdio.h>
int main()
{
	int n,a,i,s=0;
	printf("enter size: ");
	scanf("%d",&n);
	int arr[n];
	printf("enter integer: ");
	scanf("%d",&a);
	int rem;
	for(i=0;i<n;i++)
	{
		arr[i]=a%2;
		a = a/2;
	}
	for(i=n-1;i>=0;i--)
		printf("%d",arr[i]);
}

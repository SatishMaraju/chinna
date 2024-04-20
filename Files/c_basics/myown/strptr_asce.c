#include<stdio.h>
int main()
{
	char *temp;
	char *arr[]={"satish","chinna","orange","grapes"};
	for(int i=0;i<4;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			if(arr[i][0]>arr[j][0])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}}}
	for(int i=0;i<4;i++)
	{
		printf("%s\t",arr[i]);
	}
}

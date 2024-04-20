/*WAP to perform operations like below

arr[]={10,4,1,6,2}
prod[]={48,120,480,60,240}

ex:arr[5]=arr[1]
prod[1]=prpod[0]*prod[2]*prod[3]*prod[5]
*/

#include<stdio.h>
int main()
{
	int n,i,j,s=1;
	printf("enter size");
	scanf("%d",&n);
	int arr[n];
	int prod[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
	prod[i]=1;}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		if(i==j);
		else
		prod[i]=arr[j]*prod[i];
		}
		}
	for(i=0;i<n;i++)
	{
	printf("%d\n",prod[i]);
}}


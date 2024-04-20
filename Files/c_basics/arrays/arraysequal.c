//write a function to take 2 arrays as input and return 1 if they are equal and 0 if they are not equal ( sizes to be sent as seperate arguments)


#include<stdio.h>
int equal(int a1[],int a2[],int i,int j,int m,int n);
int main()
{
	int m,n,i,j,s;
	printf("enterv size of 1st");
	scanf("%d",&m);
	int a1[m];
	printf("enter size of 2nd");
	scanf("%d",&n);
	int a2[n];
	for(i=0;i<m;i++)
	{
		scanf("%d",&a1[i]);
	}
	for(j=0;j<n;j++)
	{
		scanf("%d",&a2[j]);
	}
	s=equal(a1,a2,i,j,m,n);
	if(s==1)
		printf("equal");
	else
		printf("not equal");
}
int equal(int a1[],int a2[],int i,int j,int m,int n)
{
	if(i==j)
	{
	for(i=0,j=0;i<m,j<n;i++,j++){
		if(a1[i]==a2[j])
		{
		return 1;}}}
	else
		return 0;
}

//Write a function to return the average of marks of all students in a class.

#include<stdio.h>
int main()
{
	int n,m,i,j,sum=0,s,avg=0;
	printf("enter no.of students:");
	scanf("%d",&n);
	int arr[n];
	printf("enter no.of subjects:");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
	sum=0;	
	for(j=0;j<m;j++)
		{
		
		scanf("%d",&arr[i]);//}
		goto label;
	label:sum=sum+arr[i];}
		s+=sum/m;
	printf("%d\n",s);
/*	s+=s;*/}
avg=s/n;
printf("%d",avg);
}

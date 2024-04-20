/*8)  Write a function that takes two sorted integer arrays as input, and returns an array of integers from both arrays in sorted order, excluding duplicate numbers. 
  Assume that the input arrays are sorted.
  eg., array1 : 10,12,13,14,15,16
array2 : 9,12,15,19,20
output array3 : 9,10,12,13,14,15,16,19,20
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{

	int *ptr,*ptr1,*p,k=0,j,n,n1,i,t,len=0;
	printf("Size 1: ");
	scanf("%d",&n);
	printf("Size 2: ");
	scanf("%d",&n1);
	ptr=(int *)malloc(n*sizeof(int));
	ptr1=(int *)malloc(n1*sizeof(int));
	p=(int *)malloc((n+n1)*sizeof(int));


	printf("Array1 : ");

	for(i=0;i<n;i++)
		scanf("%d",&ptr[i]);
	printf("Array2 : ");
	for(j=0;j<n1;j++)
		scanf(" %d",&ptr1[j]);

	//	ptr=(int )realloc(ptr,n1(sizeof(int)));
	for(i=0;i<n;i++)
		p[i]=ptr[i];
	for(i=0;i<n1;i++)
		p[i+n]=ptr1[i];

	n=n+n1;
	j=0;

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i] == p[j])
			{
				for(k=j;k<n-1;k++)
					p[k]=p[k+1];
				n--;
				j--;

			}


		}
	}	

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(p[j]>p[j+1])
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}		
	}
	for(i=0;i<(n);i++)
	{
		printf("%d,",p[i]);
	}

}

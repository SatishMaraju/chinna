// WAP to print all the zeroes in an array at the end of an array.

#include <stdio.h>

int main() {
	int a[]={5,6,0,0,0,4,6,0,9,0,8}; 
	int n=sizeof(a)/sizeof(a[0]); 
	int j=0; 
	for(int i=0;i<n;i++)
	{ 
		if(a[i]!=0)
			{ 
			int temp=a[i]; 
			a[i]=a[j]; 
			a[j]=temp; 
			j++;
		} 
	} 
	for(int i=0;i<n;i++)
	{ 
		printf("%d",a[i]); 
	} 
	return 0;
}

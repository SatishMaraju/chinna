// WAP to remove the duplicates without using iterative method(without usig loops).


#include <stdio.h>
int main()
{
int n,i=0,temp;
scanf("%d",&n);
int arr[n];
l:scanf("%d",&arr[i]);
i++;
if(i<n)
goto l;
i=0;
int j=i+1;
l2:if(i<n){
	l4:if(j<n){
		if(arr[i]==arr[j])
   		{
		temp=arr[j];
		loop:arr[j]=arr[j+1];
		j++;
		goto l4;
		}
		n--;
		i++;
		goto l2;
	}}
i=0;
l3:printf("%d",arr[i]);
i++;
if(i<n)
goto l3;
}

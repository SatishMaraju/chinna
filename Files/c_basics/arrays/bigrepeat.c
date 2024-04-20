/*  write a function to take an array as input, and count how many times the biggest number is repeated in that array, and return the count.
eg., array : {10, 14,16,10, 10 , 16, 14, 14, 16, 16};

output : biggest number is repeated 4 times.       */

#include<stdio.h>
int main()
{
int n,i,big=0,b;
printf("enter size:");
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
for(i=0;i<n;i++)
{
if(big<arr[i])
big=arr[i];
else
big;
}
printf("Big value:%d\n",big);
b=big;
int count=0;
for(i=0;i<n;i++)
{
if(b==arr[i])
count++;
else
count;
}
printf("No.of repetitions of big:%d\n",count);
}

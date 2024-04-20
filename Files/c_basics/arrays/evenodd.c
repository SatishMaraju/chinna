/*  Write the following program :
Declare an integer array of size 100.
Assign numbers 1-100 to each element of the array.
Print all the numbers.
Print all even elements.
Print all odd elements.
Add 5 to each element and print 6 – 105 numbers.  */


#include<stdio.h>
int main()
{
int arr[100],i,a=1,j;
for(i=0;i<100;i++)
{
arr[i]=a;
a++;
printf("%d\t",i);
}
printf("\n");
printf("odd numbers");
for(i=0;i<100;i++){
if(arr[i]%2==0)
printf("%d\t",i);
}
printf("\n");
printf("even numbers");
for(i=1;i<100;i++)
{
if(!(arr[i]%2==0))
printf("%d\t",i);
}
for(i=0;i<100;i++)
{
//arr[i]=a+5;

printf("%d\t",arr[i]+5);
}}

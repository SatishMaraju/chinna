//Create a character pointer array, initialise the pointers to read only strings. Sort the array and print.



#include<stdio.h>
#include<string.h>
int main()
{
char *temp;
int c,i,j;
char *arr[]={"satish","chinna","kernel","masters","mini"};
for(int i=0;i<5;i++)
{
for(j=i+1;j<5;j++)
{
c=strcmp(arr[i],arr[j]);
{
if(c>0)
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}}}
for(i=0;i<5;i++)
{
printf("%s\n",arr[i]);}
}


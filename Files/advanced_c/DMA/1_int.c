//  1) create an integer dynamically ,read and print its value.


#include<stdio.h>
#include<stdlib.h>
int main()
{
int i;
int *p=(int *)malloc(1*sizeof(int));
if(p==NULL)
{
printf("memory not available");
}
printf("enter an integer:");
scanf("%d",&p[0]);
printf("%d\n",p[0]);

free(p);
}

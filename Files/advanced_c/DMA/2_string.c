//  1) create an string dynamically ,read and print its value.


#include<stdio.h>
#include<stdlib.h>
int main()
{
char *p=(char *)malloc(10*sizeof(char));
if(p==NULL)
{
printf("memory not available");
}
printf("enter string:");
scanf("%[^\n]s",p);
printf("%s\n",p);

free(p);
}

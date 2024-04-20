// 3) create a string dynamically, copy a string constant to it ( "Kernel"). Create another string dynamically. Copy the first string to second string.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
char *p=(char *)malloc(20*sizeof(char));
//char *p2=(char *)malloc(20*sizeof(char));
if(p==NULL)
{
printf("memory not available");
}

strcpy(p,"kernel");
char *p1=(char *)malloc(20*sizeof(char));
strcpy(p1,p);
printf("%s",p1);

free(p);
free(p1);
}

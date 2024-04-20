// Try to send a character array / character pointer / string constant as arguments and see what is the size returned, and understand the difference.


#include<stdio.h>
#include<string.h>
#define size(z) (char *)(&z+1)-(char *)(&z)
int main()
{
char arr[]={'s','a','t','i','s','h'};
char *ptr[]={"satish","chinna","nani"};
char str[]="satishchinna";
char *ptr1;
printf("array:%ld\n",size(arr));
printf("pointer:%ld\n",size(ptr));
printf("string:array:%ld\n",size(str));
printf("pointer 1:%ld\n",size(ptr1));
}


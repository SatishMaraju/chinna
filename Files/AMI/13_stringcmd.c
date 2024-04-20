//  Write a program to take a string as input with command line argument and print the string and its length.

#include<string.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
char str[BUFSIZ];
strcpy(str,argv[1]);
printf("%s",str);
printf("\t%ld\n",strlen(str));
}

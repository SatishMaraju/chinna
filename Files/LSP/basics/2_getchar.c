// Write a system programming your own version of getchar() standard C Library?


#include<stdio.h>
#include<unistd.h>
 
int main(int argc,char *argv[])
{
char ch;
int  a;
a=read(0,&ch,1);
write(1,&ch,1);
write(1,"\n",1);
}

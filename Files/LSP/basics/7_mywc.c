//Write a system programming your own version of wc command?


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
int a,wc=0,cc=0,lc=0,ret=0;
char ch;
a=open(argv[1],O_RDONLY);
while(1)
{
ret=read(a,&ch,1);
if(ret==0)
{
break;
}
cc++;
if((ch==' ')||(ch=='\n'))
wc++;
if(ch=='\n')
lc++;
}
printf("no.of char:%d\nno.of words:%d\nno.of lines:%d\n",cc,wc,lc);
}

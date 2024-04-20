// Write a system programming your own version of echo command \?



#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int ret;
	
	for(int i=1;i<argc;i++)
	{
	ret=strlen(argv[i]);
	write(1,argv[i],ret);
	write(1," ",1);
	}
	write(1,"\n",1);
	return 0;
}

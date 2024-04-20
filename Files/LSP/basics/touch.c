//touch
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <utime.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	int df,fd;char ch;
	//df = open(argv[1],O_CREAT,0666);
	fd = utime(argv[1],NULL);  // Gives file modification and opening time
	if (fd==-1)
	open(argv[1],O_CREAT,0666);
	close(df);
}

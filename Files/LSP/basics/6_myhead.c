//Write a system programming your own version of head command?


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	int count=0,ret,df;char ch;
	df = open(argv[1],O_RDONLY);
	while(1)
	{
		ret = read(df,&ch,1);
		if (ret == 0)
		break;
		write(1,&ch,1);
		if (ch == '\n')
		count++;
		if (count == 10)
		break;
	}
}

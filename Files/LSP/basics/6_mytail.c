//6Write a system programming your own version of tail command?


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int count = 0, c = 0, ret, df, temp;
	char ch;
	df = open(argv[1], O_RDONLY);
	if (df == -1) {
	perror("open error");
	exit(2);
	}
	while (1) {
	ret = read(df, &ch, 1);
	if (ret == 0)
	break;
	if (ch == '\n')
	count++;
	}
	temp = count - 10;
	close(df);  
	df = open(argv[1], O_RDWR);
	if (df == -1) {
	perror("open error");
	exit(2);
	}
	while (1) {
	ret = read(df, &ch, 1);
	if (ret == 0)
	break;
	if (ch == '\n')
	c++;
	if (c >= temp)
	write(1, &ch, 1);
	}
	close(df);
return 0;
}

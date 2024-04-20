// WAP with the use of vfork().

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid = vfork();  //creating the child process
	printf("Creation: %d\n", getpid());
	if(pid == 0)
	{
		printf("Child process: %d\t", getpid());
		exit(0);
	} 
	else if(pid > 0) 
	{
		printf("Parent processs: %d\n", getpid());
	}
	else
	{
		printf("Error while forking\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}

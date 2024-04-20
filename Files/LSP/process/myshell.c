// Write a lsp program to create your own version of system library.   ex:system("ls -a");


#include <sys/wait.h>
#include <sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>

int main()
{
	int a,status;
	char *str;
	scanf("%[^\n]s",str);
	a=fork();
	if(a==0)
	{
	execl("/bin/sh","sh","-c",str,0);
	printf("command end\n");
	exit(0);
	}
	else
	{
	//printf("parent");
	wait(&status);
	}
}

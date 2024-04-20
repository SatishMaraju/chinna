// Write a lsp program to create your own shell program.


#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<string.h>
int mysystem();
int main()
{
	char str[100];
	int c;
	while(1)
	{
		printf("$ ");
		scanf(" %[^\n]s",str);
		mysystem(str);
		c=strcmp(str,"exit");
		if(c==0){
		exit(0);
		break;
		}
	}
}
int mysystem(const char *command)
{
	int status;
	int z=fork();
	if(z==0)
	{
	execl("/bin/sh","sh","-c",command,(char *) 0);
	exit(0);
	}
	else
	wait(&status);
return 0;
}

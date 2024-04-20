/*Assignment 3: program names: prod-unrel.c, cons-unrel.c
  Write a separate program for producer.c and consumer.c using,
  - Shared Memory, 
  - synchronizing using named semaphores 
  - without using fork() and exec() system calls.
 */
#include<string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
sem_t  *prod,*con;
int i,shmid;
char ch='A',b[5];
void handle(int sig)
{

	printf("ctrl+c signal is received");
	sem_unlink("producer");
	sem_unlink("consumer");
	signal(SIGINT,SIG_DFL);
}



int main()
{
	char *msg;
	int status;
	signal(SIGINT,handle);
	prod=sem_open("producer",O_CREAT,0666,1);
	if(prod<0)
	{
		perror("message:");
		exit(1);
	}
	con=sem_open("consumer",O_CREAT,0666,0);
	if(con<0)
	{
		perror("message:");
		exit(1);
	}
	if((shmid=shmget(10,1024,0666|IPC_CREAT))==-1)
	{
		perror("message");
		exit(1);
	}
	while(1)
	{
		sem_wait(prod);
		for(i=0;i<5;i++)
		{
		b[i]=ch;
		ch++;
		}
		ch='A';
		msg=shmat(shmid,0,0);
		strcpy(msg,b);
		printf("%s\n",msg);
		shmdt(msg);
		sem_post(con);
	}
	if(shmctl(shmid,IPC_RMID,0)==-1) 
	{
		perror("shmctl");
		exit(1);
	}
}

/*Write a separate program for producer and consumer problem using,
- fork(), exec() 
- shared memory.
- Synchronizing using named seamphore.
*/

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
int a,b,n=0,i=0,shmid;
char arr[10],ch,data[10];
pid_t p;
sem_t *prod,*con;
	
void handle(int sig)
{
	printf("termination signal is received");
	sem_unlink("producer");
	sem_unlink("consumer");
	signal(SIGINT,SIG_DFL);
}
char *argv[]={"in",0};
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
	p=fork();
	if((shmid=shmget(10,1024,0666|IPC_CREAT))==-1)
	{
		perror("message");
		exit(1);
	}
	if(p==0)
	{
//		execl("bin","sh","-C",argv[1],NULL);
		execve("in",argv,NULL);
		
	}
	else
	{
		while(1)
		{
			sem_wait(prod);
			for (i=0;i<10;i++)
			{
				arr[i]=ch;
				ch++;
			}
			ch='A';
			msg=shmat(shmid,0,0);
			strcpy(msg,arr);
			printf("%s\n",msg);	
			shmdt(msg);
			sem_post(con);
	}
		wait(&a);
	}
	if(shmctl(shmid,IPC_RMID,0)==-1)
	{
		perror("shmctl");
		exit(1);
	}
}

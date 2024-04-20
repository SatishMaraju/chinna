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
int z,shmid;
char *msg;
sem_t *prod,*con;

/*void handle(int sig)
  {

  printf("ctrl+c signal is received");
  sem_unlink("producer");
  sem_unlink("consumer");
  signal(SIGINT,SIG_DFL);
  }
 */
int main()
{
	prod=sem_open("producer",0);
	if(prod<0)
	{
		perror("message:");
		exit(1);
	}
	con=sem_open("consumer",0);
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
		sem_wait(con);
		msg=shmat(shmid,0,0);
		printf("	:c:%s\n",msg);
		shmdt(msg);
		sem_post(prod);
	}
}

// Wrote a lsp program to print the even and odd numbers using threads.


#include <pthread.h>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<semaphore.h>
char p[]="hai";
int buff[50];
int n=0;
sem_t prod,cons;
void *pro_fun(void *arg);
void *con_fun(void *arg);
int main()
{
	int b,res;
	void *retval;
	pthread_t pro,con;   // like a file descriptor

	sem_init(&prod,0,1);
	sem_init(&cons,0,0);


	res=pthread_create(&pro,NULL,pro_fun,(void *) p);
	if(res != 0)
	{
		perror("message:");
		pthread_exit("hai");
	}
	
	res=pthread_create(&con,NULL,con_fun,(void *) p);
	if(res != 0)
	{
	perror("message:");
	}
	pthread_join(pro,&retval);
	pthread_join(con,&retval);
}
void *pro_fun (void *arg)
{

while((n>=0)&&(n<=100))
	{
	sem_wait(&prod);
		if(n%2==0)
			{
			printf("even:%d\n",n);
			n++;
			}
		sem_post(&cons);
	}
}

void *con_fun(void *arg)
{
n=0;
while(n<100)
	{
	sem_wait(&cons);
	if(n%2!=0)
		{
		
		printf("odd:%d\n",n);
		n++;
		}
	sem_post(&prod);
	}
}


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/syscall.h>
#include <sys/types.h>
#define _GNU_SOURCE

void *producer(void *arg);
void *consumer(void *arg);
void prod_sig(int sig);
void cons_sig(int sig);
pthread_t a_thread,b_thread;
char buffer[5];
char data[BUFSIZ+1];
sem_t prod,cons;
pid_t x,y;

int main()
{	
	//pid_t tid;
	//tid = syscall(SYS_gettid);

	int res;
	void *thread_result;
    
	sem_init(&prod,0,1);
	sem_init(&cons,0,0);

	res = pthread_create(&a_thread, NULL, producer, NULL);
	if (res != 0)
	{
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
	}

	res = pthread_create(&b_thread, NULL, consumer, NULL);
	if (res != 0)
	{
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
	}
	
	res = pthread_join(a_thread, &thread_result);
	if(res<0)
	{
	perror("message:");
	}
	res = pthread_join(b_thread, &thread_result);
	
	if(res<0)
	{
	perror("message:");
	}
}

void *producer(void *arg)
{
//Step 1: Initialize producer signal handler.
	(void) signal (SIGUSR1,prod_sig); //system call.
	//y=syscall(SYS_gettid);
//Step 2: Waiting for a signal from consumer thread inside infinite loop.Use pause () system call inside infinite loop and wait for a signal from consumer thread.
		while(1)
		{
			pause();
		}
}

void prod_sig(int sig)
{
	//Step 1: Producer start produce the data until the buffer is FULL.
	int i = 0,in=0; 
	char ch='A';
		sem_wait(&prod);
		for(i=0;i<5;i++)
		{
			buffer[i]=ch;
			ch++;
		}
		ch='A';
		printf("p:%s\n",buffer);
		pthread_kill(b_thread,SIGUSR2);
		sem_post(&cons);

	//syscall(SYS_tkill,x,SIGUSR2);
//Use tkill () system call (or) pthread_kill library to raise a signal to consumer thread.
}

void *consumer(void *arg)
{ 
//Step 1: Initialize consumer signal handler.
	(void) signal (SIGUSR2,cons_sig);   // system call for signal handler initialization.
	//x=syscall(SYS_gettid);
//Step 2: Consumer raise a signal to producer thread.
	//tkill(tid,SIGUSR2);
	pthread_kill( a_thread,SIGUSR1);
//Step 3: Waiting for a signal from producer thread inside infinite loop.Use pause () system call wait for a signal from producer thread.
	while(1)
	{
	pause();
	}
}

void cons_sig(int sig)
{
//Step 1: Whenever signal received from producer thread, start read the buffer until buffer is empty.
	int i = 0,s;
		sem_wait(&cons);
		for(i=0;i<5;i++)
		{
		data[i] = buffer[i];
		}
		printf ("\t:c:%s\n",data); 
	pthread_kill(a_thread,SIGUSR1);
	sem_post(&prod);
//Step 2: Whenever the buffer is EMPTY, Consumer raise a signal to producer thread.
	//syscall(SYS_tkill,x,SIGUSR1);
}

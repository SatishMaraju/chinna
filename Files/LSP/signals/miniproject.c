//WAP Producer thread and consumer thread synchronization using Pthreads and Signals? See the below Pseudo code.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
char ch;
pthread_t abc,xyz;
char buffer[26],data[BUFSIZ];

void *producer(void *arg);
void prod_sig(int sig);
void *consumer(void *arg);
void cons_sig(int sig);
int main()
{
	int ret,ret1,ret2,ret3;
	// (void) signal(SIGUSR2,cons_sig);
	// (void) signal(SIGUSR1,prod_sig);
	ret = pthread_create(&abc,NULL,producer,NULL);
	ret1 = pthread_create(&xyz,NULL,consumer,NULL);
	if (ret < 0||ret1 < 0){
		perror("pthread create fail:");
		exit(0);}
	ret2 = pthread_join(abc,NULL);
	ret3 = pthread_join(xyz,NULL);
	if (ret2 < 0||ret3 < 0){
		perror("pthread join fail:");
		exit(0);}
}
void *producer(void *arg)
{
	//Step 1: Initialize producer signal handler.
	(void) signal(SIGUSR1,prod_sig);
	//Step 2: Waiting for a signal from consumer thread inside infinite loop.
	while(1){
		pause();
	}
}
void prod_sig(int sig)
{
	int in = 0,n=26;
	char ch = 'A';
	//Step 1: Producer start produce the data until the buffer is FULL.
	while(n--)
	{
		buffer[in] = ch;
		in = (in+1)%26;
		ch++;
		if(in == 0)
		{
			ch = 'A';
			printf("Producer: %s\n",buffer);
		}
	}
	//Step 2: Whenever buffer is FULL raise a signal to consumer thread.
	pthread_kill(xyz,SIGUSR2);

}
void *consumer(void *arg)
{
	//Step 1: Initialize consumer signal handler.
	(void) signal(SIGUSR2,cons_sig);
	//Step 2: Consumer raise a signal to producer thread.
	pthread_kill(abc,SIGUSR1);
	//Step 3: Waiting for a signal from producer thread inside infinite loop.
	while(1){
		pause();
	}
}
void cons_sig(int sig)
{
	int n=26,out=0;
	//Step 1: Whenever signal received from producer thread, start read the buffer until buffer is empty.
	while(n--)
	{
		data[out] = buffer[out];
		out = (out+1)%26;
		if (out == 0)
			printf("\tConsumer: %s\n",data);
	}
	//Step 2: Whenever the buffer is EMPTY, Consumer raise a signal to producer thread.
	pthread_kill(abc,SIGUSR1);
}

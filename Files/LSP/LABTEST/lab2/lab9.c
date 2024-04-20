// WAP to implent produce and consumer program using threads and semaphore.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void *producer(void *arg);
void *consumer(void *arg);
char buffer[5];
sem_t prod,cons;

int main() {
    int res;
    pthread_t a_thread,b_thread;
    void *thread_result;
    
    sem_init(&prod,0,1);
    sem_init(&cons,0,0);

    res = pthread_create(&a_thread, NULL, producer, NULL);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&b_thread, NULL, consumer, NULL);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Wait for pthread_join\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_join(b_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined\n");
    exit(EXIT_SUCCESS);
}

void *producer(void *arg) {
    int i = 0; 
    char ch='A';
    while(1)
	{
		sem_wait(&prod);
		for(i=0;i<5;i++)
		{
			buffer[i]=ch;
			ch++;
		}
		ch='A';
		printf("p:%s\n",buffer);
		sem_post(&cons);
	}
	
   pthread_exit("exit");	
}
void *consumer(void *arg) {
    int i = 0;
    char data[10];
    while(1)
	{
		sem_wait(&cons);
		for(i=0;i<10;i++){
			data[i] = buffer[i];
		}
		printf ("\t:c:%s\n",data); 
		sem_post(&prod);
	}
   pthread_exit("exit");	
}

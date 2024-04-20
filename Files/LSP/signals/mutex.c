// WAP of producer and consumer using mutex

#include <stdio.h>
#include <pthread.h>

#define BUFSIZE 10

int buffer[BUFSIZE];
int count = 0;
pthread_mutex_t mutex;
void* producer(void* arg) 
{
	for(int i=0; i < 10; i++) 
	{
		pthread_mutex_lock(&mutex);
		buffer[count] = i; // Produce the value of 'i' into the buffer
		count++; // Increase the count of items in the buffer
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

void* consumer(void* arg) {
	int data[BUFSIZ];
	for (int i = 0; i < BUFSIZE; i++) 
	{
		pthread_mutex_lock(&mutex);
		data[i] = buffer[i];
		pthread_mutex_unlock(&mutex);
		printf("Consumed: %d\n", data[i]); // Print the consumed value
	}
	pthread_exit(NULL);
}

int main() 
{
	pthread_t producerThread, consumerThread;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&producerThread, NULL, producer, NULL);
	pthread_create(&consumerThread, NULL, consumer, NULL);
	pthread_join(producerThread, NULL);
	pthread_join(consumerThread, NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}

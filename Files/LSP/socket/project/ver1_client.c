#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include<string.h>
#include <semaphore.h>
#include <pthread.h>
sem_t prod,cons;

char buff[1024];
char s[1024];
char *retval;
int sockfd;

void *thread_fun(void *arg)
{
	while(1)
	{
	sem_wait(&cons);
	
    	read(sockfd, s, sizeof(s));
	printf("data:%s\n",s);
	sem_post(&prod);
	}
	pthread_exit("done");
}

int main()
{
    int len;
    struct sockaddr_in address;
    int result;
    char ch = 'A';
	pthread_t client;
	sem_init(&prod,0,1);
	sem_init(&cons,0,0);

/*  Create a socket for the client.  */

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket, as agreed with the server.  */

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = 9734;
    len = sizeof(address);

/*  Now connect our socket to the server's socket.  */
    result = connect(sockfd, (struct sockaddr *)&address, len);

    if(result == -1) {
        perror("oops: client2");
        exit(1);
    }
	printf("connected\n");
int ret = pthread_create(&client,NULL,thread_fun,(void *)NULL);
	if (ret < 0){
		perror("pthread create fail:");
		exit(0);
	}
while(1)
	{

	sem_wait(&prod);

	fgets(buff,1024,stdin);
	
//	strcpy(buff,"manikanta");
    	write(sockfd, buff, sizeof(buff));

    sem_post(&cons);

}

    close(sockfd);
}

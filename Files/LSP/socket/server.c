#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
 #include <pthread.h>
sem_t prod,cons;

    int server_sockfd, client_sockfd;
char buff[1024];
char s[1024];
void *retval;
   int server_len, client_len;
void *thread_fun2(void *arg)
{
while(1)
	{

//	sem_wait(&prod);

	
    	read(client_sockfd, s, sizeof(s));
	printf("client:%s\n",s);
  //  	sem_post(&cons);

}

 }  
void *thread_fun(void *arg)
{
	while(1)
	{
//	sem_wait(&cons);
	fgets(buff,1024,stdin);	
    	write(client_sockfd, buff, sizeof(buff));
//	sem_post(&prod);
	}
	pthread_exit("done");
}


int main()
{
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
	pthread_t server,client;
//	sem_init(&prod,0,1);
//	sem_init(&cons,0,0);

/*  Create an unnamed socket for the server.  */

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket.  */

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 9734;
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);





/*  Create a connection queue and wait for clients.  */

    listen(server_sockfd, 5);

        printf("server waiting\n");

/*  Accept a connection.  */

        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, 
            (struct sockaddr *)&client_address, &client_len);
	int ret = pthread_create(&server,NULL,thread_fun,(void *)NULL);
	if (ret < 0){
		perror("pthread create fail:");
		exit(0);
	}
	int retu = pthread_create(&client,NULL,thread_fun2,(void *)NULL);
	if (retu < 0){
		perror("pthread create fail:");
		exit(0);
	}
	pthread_join(server,&retval);
	pthread_join(client,&retval);
/*	while(1)
	{
	//sem_wait(&cons);
	fgets(buff,1024,stdin);	
    	write(client_sockfd, buff, sizeof(buff));
//	sem_post(&prod);
	}
	pthread_exit("done");*/
}

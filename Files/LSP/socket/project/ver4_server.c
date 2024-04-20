
/* VERSION 4 ---------   SERVER*/


#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include<string.h>
struct input_event v;
sem_t prod,cons;
int server_sockfd, client_sockfd;
char buff[1024];
char s[1024];
void *retval;
int fd1,l;
int fd;
int server_len, client_len;
void *thread_fun(void *arg)
{
	fd1=open("/dev/input/event0",O_RDWR);
	if(fd1<0)
		perror("open3 fail");
	while(1)
	{
		l=sizeof(v);
		read(fd1,&v,l);
		if((v.code==115))
			write(client_sockfd,"R",2);
		if((v.code==114))
			write(client_sockfd,"O",2);
	}
}  
void *thread_fun2(void *arg)
{
	fd=open("/sys/class/gpio/gpio10/value",O_WRONLY);
	if(fd<0)
		perror("open2 fail");
	while(1)
	{
		read(client_sockfd,s,sizeof(s));
		if((s[0]-'R')==0){
			write(fd,"1",2);
			printf("r\n");
		}	
		if((s[0]-'O')==0){
			write(fd,"0",2);
			printf("o\n");
		}
		memset(s,'\0',sizeof(s));
	}
	pthread_exit("done");
}


int main()
{
	fd=open("/sys/class/gpio/export",O_WRONLY);
	if(fd<0)
		perror("open1 fail");
	write(fd,"10",5);
	close(fd);
	fd=open("/sys/class/gpio/gpio10/direction",O_WRONLY);
	if(fd<0)
		perror("open2 fail");
	write(fd,"out",5);
	close(fd);
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	pthread_t server,client;
	sem_init(&prod,0,1);
	sem_init(&cons,0,0);
	/*  Create an unnamed socket for the server.  */
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	/*  Name the socket.  */
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("192.168.0.112");
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
	//	close(fd);
	//close(fd1);
	int fd5=open("/sys/class/gpio/unexport",O_WRONLY);
	if(fd5<0)
		perror("open4 fail");
	write(fd5,"10",5);
	close(fd5);
}

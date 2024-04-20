
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
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
struct input_event v;
sem_t prod,cons;
int fd,fd1,l;
char buff[1024];
char s[1024];
char ch;
char *retval;
int sockfd;
int led_flag;
void *thread_fun(void *arg)
{
	fd=open("/sys/class/gpio/gpio10/value",O_WRONLY);
	if(fd<0)
		perror("open2 fail");
	while(1)
	{
		read(sockfd,s,sizeof(s));
		if((s[0]-'R')==0 )
			led_flag=1;
		if((s[0]-'O')==0)
		{
			led_flag=0;
			write(fd,"0",2);
		}

		memset(s,'\0',sizeof(s));
	}
	pthread_exit("done");
}
void *thread_fun2(void *arg)
{
	while(1)
	{
		if(led_flag==1)
		{
			write(fd,"1",2);
			sleep(1);
			write(fd,"0",2);
			sleep(1);
		}
	}
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
	int len;
	struct sockaddr_in address;
	int result;
	char ch = 'A';
	pthread_t client,blink2;
	sem_init(&prod,0,1);
	sem_init(&cons,0,0);

	/*  Create a socket for the client.  */

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/*  Name the socket, as agreed with the server.  */

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("192.168.0.112");
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
	int ret1 = pthread_create(&blink2,NULL,thread_fun2,(void *)NULL);
	if (ret1 < 0){
		perror("pthread create fail:");
		exit(0);
	}
	fd1=open("/dev/input/event0",O_RDWR);
	if(fd1<0)
		perror("open3 fail");
	while(1)
	{
		l=sizeof(v);
		read(fd1,&v,l);
		if(((v.code)==115))
			write(sockfd,"R",2);
		if(((v.code)==114))
			write(sockfd,"O",2);

	}
	close(sockfd);
	//close(fd);
	//close(fd1);

	int fd6=open("/sys/class/gpio/unexport",O_WRONLY);
	if(fd6<0)
		perror("open4 fail");
	write(fd6,"10",5);
	close(fd6);
}

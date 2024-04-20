/*Exp 5: Synchronization

  Implement binary semaphore to synchronize main thread and green thread to avoid green_led_flag.  */


#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <pthread.h>
#include <string.h>

pthread_t red, green;
sem_t sem;

int fd, fd1, fd3, ret;
void *red_led(void *arg)
{
	while (1)
	{
		write(fd, "1", 1);
		sleep(1);
		write(fd, "0", 1);
		sleep(1);
	}
}
void *green_led(void *arg)
{
	while(1)
	{
		sem_wait(&sem);
		printf("sem wait\n");
		write(fd3, "1", 1);
		sleep(1);
		write(fd3, "0", 1);
		sleep(1);
	}

}
int main()
{
	struct input_event v;
	sem_init(&sem, 0, 0);
	fd = open("/sys/class/gpio/export", O_WRONLY);
	if (fd < 0)
	{
		perror("open1 fail");
		exit(EXIT_FAILURE); 
	}
	write(fd, "10", 3);
	close(fd);

	fd = open("/sys/class/gpio/gpio10/direction", O_WRONLY); 
	if (fd < 0)
	{
		perror("open2 fail");
		exit(EXIT_FAILURE);
	}
	write(fd, "out", 4);
	close(fd);
	fd = open("/sys/class/gpio/gpio10/value", O_WRONLY); 
	if (fd < 0)
	{
		perror("open2 fail");
		exit(EXIT_FAILURE);
	}

	fd1 = open("/dev/input/event0", O_RDWR);
	if (fd1 < 0)
	{
		perror("open3 fail");
		exit(EXIT_FAILURE);
	}

	fd3 = open("/sys/class/gpio/export", O_WRONLY); 
	if (fd3 < 0)
	{
		perror("open4 fail");
		exit(EXIT_FAILURE);
	}
	write(fd3, "9", 2);
	close(fd3);

	fd3 = open("/sys/class/gpio/gpio9/direction", O_WRONLY); 
	if (fd3 < 0)
	{
		perror("open5 fail");
		exit(EXIT_FAILURE);
	}
	write(fd3, "out", 4);
	close(fd3);
	fd3 = open("/sys/class/gpio/gpio9/value", O_WRONLY); 
	if (fd3 < 0)
	{
		perror("open6 fail");
		exit(EXIT_FAILURE);
	}

	ret = pthread_create(&red, NULL, red_led, NULL);
	if (ret < 0)
	{
		perror("pthread_create fail");
		exit(EXIT_FAILURE);
	}

	ret = pthread_create(&green, NULL, green_led, NULL);
	if (ret < 0)
	{
		perror("pthread_create fail");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		int l = sizeof(v);
		read(fd1, &v, l);
		if ((v.code) == 115 && v.value == 1)
		{
			sem_post(&sem);
			memset(&v,0,l);
		}
	}
	close(fd);
	close(fd1);
	close(fd3);

	fd = open("/sys/class/gpio/unexport", O_WRONLY); 
	if (fd < 0)
	{
		perror("open4 fail");
		exit(EXIT_FAILURE);
	}
	write(fd, "10", 3);
	close(fd);

	fd3 = open("/sys/class/gpio/unexport", O_WRONLY); 
	if (fd3 < 0)
	{
		perror("open4 fail");
		exit(EXIT_FAILURE);
	}
	write(fd3, "9", 2);
	close(fd3);
	return 0;
}

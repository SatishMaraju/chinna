#include<stdio.h>
#include <pthread.h>
pid_t z;
int a=3;
void *ret;
int fun(int );
int main()
{
int n,t;
printf("enter the number\n");
scanf("%d",&n);
t=pthread_create(&z,NULL,fun,n);
if(t<0)
perror("message:");
t=pthread_join(z,&n);
}
int fun(int n)
{
int count=0;
while(n>0)
{
//int count=0;
if((n&a)==3)
count++;
n=n>>2;
//n=n>>1;
}
printf("%d",count);
}

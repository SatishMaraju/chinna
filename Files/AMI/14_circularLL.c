/*  Write a program to create a Circular linked list with following information :
    a.      Roll number
    b.      Student name
 */
#include<stdlib.h>
#include<stdio.h>
typedef struct student{
	int rollno;
	char name[100];
	struct student *next;
}stu;

stu *createnode()
{
	stu *n=(stu *)malloc(sizeof(stu));
	scanf("%d",&n->rollno);
	scanf("%[^\n]s",n->name);
	n->next=NULL;
}
stu *createlist()
{
	stu *n=NULL,*h=NULL,*l=NULL;
	n=createnode();
	if(h==NULL){
		h=n;
		h->next=n;}
	else{
		l=n;
		h->next=n;
		l->next=h;
		return h;
	}
}
stu *display(stu *t)
{
	printf("%d %s",t->rollno,t->name);
	return t;
}

int main()
{
	stu *h=NULL;
	h=createnode();
	display(h);
}

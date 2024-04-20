// WAP to print the linked list.


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void traversal();
typedef struct student
{
	int id;
	char name[100];
	struct student *next;
}stu;

stu *createlist();
stu *createnode();

int main()
{
	stu *h=NULL;
	h=createlist();
	traversal(h);
}
stu *createlist()
{
	stu *h=NULL,*l=NULL,*n=NULL;
	char ch='y';
	while(ch=='y')
	{
		n=createnode();
		if(h==NULL)
			h=n;
		else
			l->next=n;
		l=n;
		printf("yes or no:\n");
		scanf(" %c",&ch);
	}
	return h;
}
stu *createnode()
{
	stu *n=(stu *)malloc(sizeof(stu));
	printf("enter id and name:\n");
	scanf("%d %[^\n]s",&n->id,n->name);
	n->next=NULL;
	return n;
}
void traversal(stu *h)
{
	while(h){
		printf("%d %s\n",h->id,h->name);
		h=h->next;}
}

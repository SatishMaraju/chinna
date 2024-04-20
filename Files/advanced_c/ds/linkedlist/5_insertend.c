// WAP to insert a node in a given position and print  the linked list.


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int pos;
void traversal();
typedef struct student
{
	int id;
	char name[100];
	struct student *next;
}stu;

stu *createlist();
stu *createnode();
stu *insert();
int main()
{
	stu *n=NULL;
	int pos;
	stu *h=NULL;
	h=createlist();
	n=insert(h);
	traversal(n);
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
	while(h)
		{
		printf("%d\t%s\n",h->id,h->name);
		h=h->next;
		}
}

stu *insert(stu *t)
{
	stu *l=NULL;
	l=t;
	stu *n=NULL;
	while(t->next)
	{
	t=t->next;
	}
	t->next=createnode();
	//t->next=n;
return l;
}

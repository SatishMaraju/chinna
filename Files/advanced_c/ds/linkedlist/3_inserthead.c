// WAP to insert the node at first position (i.e.changing the gead).

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct student
{
	int id;
	char name[100];
	struct student *next;
}stu;
int pos;
void traversal();
stu* insert(stu *t);

stu *createlist();
stu *createnode();
int main()
{
	stu *z=NULL,*n=NULL;
	int pos;
	stu *h=NULL;
	n=createlist();
	z=insert(n);
	traversal(z);
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
stu* insert(stu *t)
{
	stu *n=NULL;
	n=createnode();
	n->next=t;
return n;
}


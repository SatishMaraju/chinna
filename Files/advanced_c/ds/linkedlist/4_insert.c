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
char y;
int main()
{

	int pos;stu *z=NULL;
	while(1){
		printf("Enter h:head n:newnode b:before a:after e:end\n");
		scanf(" %c",&y);
		printf("enter position\n");
		scanf("%d",&pos);
		stu *h=NULL;
		h=createlist();
		z=insert(h,pos);
		traversal(z);}
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
stu *insert(stu *t,int pos)
{
	if(y=='n'||y=='b'||y=='a'||y=='h'||y=='e')
	{
		if(y=='h'){
			if(pos==1)
			{
				stu *n=NULL;
				n=createnode();
				n->next=t;
				return n;
			}}
		if(y=='n')
		{
			if(pos!=1) //else
			{
				int i=1;stu *n=NULL;
				while(i<pos-1)
				{
					t=t->next;
					i++;
				}
				n=createnode();
				n->next=t->next;
				t->next=n;return t;
			}}
		if(y=='b')
		{
			int i=1;stu *n=NULL;
			while(i<pos-2)
			{
				t=t->next;
				i++;
			}
			n=createnode();
			n->next=t->next;
			t->next=n;return t;
		}
		if(y=='a')
		{

			int i=1;stu *n=NULL;
			while(i<pos)
			{
				t=t->next;
				i++;
			}
			n=createnode();
			n->next=t->next;
			t->next=n;return t;
		}
		if(y=='e')
		{
			stu *l=NULL;
			l=t;
			stu *n=NULL;
			while(t->next)
			{
				t=t->next;
			}
			t->next=createnode();
			return l;
		}
	}}

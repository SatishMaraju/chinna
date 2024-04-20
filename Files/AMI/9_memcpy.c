// Implement Memcpy function taking two pointers and size as argument.



struct student{
	int no;
	char name[100];
};

#include<stdio.h>
#include<string.h>
void mymemcpy(struct student d,struct student s,int size);
int main()
{
	struct student d;
	struct student s={10,"chinna"};
	mymemcpy(d,s,sizeof(s));
	return 0;
}

void mymemcpy(struct student d,struct student s,int size)
{
d.no=s.no;
for(int i=0;s.name[i]!='\0';i++)
d.name[i]=s.name[i];
printf("%d %s",d.no,d.name);
}

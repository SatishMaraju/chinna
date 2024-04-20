/*3) Write a function to compare 2 structures and return 1 if they are equal, and 0 if they are not equal.
 */
#include"student.h"
struct student s[2];
void marks(int arr[],float *p)
{
	*p=0;
	for(int i=0;i<6;i++)
		*p += arr[i];

	*p /=6;

}

void printstudent(struct student s[],int k)
{
	int i=0;
	printf("ID : ");
	scanf("%d",&s[k].ID);
	printf("name : ");
	scanf("%s",s[k].name);
	printf("marks 6 sub : ");
	for(i=0;i<6;i++)
		scanf("%d",&s[k].marks[i]);
	printf("DOB d-m-y : ");
	scanf("%d-%d-%d",&s[k].d,&s[k].m,&s[k].y);
	printf("Gender : ");
	scanf(" %c",&s[k].gender);

	marks(s[k].marks,&s[k].per);
}
int compare(struct student s[])
{
	int k=0;
	for(int i=0;i<6;i++)
		if(s[0].marks[i]==s[1].marks[i])
			k++;
	if(s[0].ID==s[1].ID && s[0].per==s[1].per && s[0].d==s[1].d && s[0].m==s[1].m && s[0].y==s[1].y && s[0].gender==s[1].gender && k==6)
		if(strcmp(s[0].name,s[1].name)==0)
			return 1;
		else
			return 0;
}

int main()
{
	int n,i;
	for(i=0;i<2;i++)
		printstudent(s,i);

	n=compare(s);
	if(n==1)
		printf("equal\n");
	else
		printf("not equal\n");
}

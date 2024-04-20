/*
   6) Count and print how many girls and how many boys there are in the class.
 */

#include"student.h"
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


int main()
{
	int n,i,girl=0,boy=0;
	printf("num of students " );
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
		printstudent(s,i);


	for(i=0;i<n;i++)
	{
		if(s[i].gender=='f'||s[i].gender=='F')
			girl++;
		else if(s[i].gender=='m'||s[i].gender=='M')
			boy++;
	}

	printf("No. of boys %d\n",boy);
	printf("No. of girls %d\n",girl);
}

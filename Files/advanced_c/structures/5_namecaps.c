/*5) Write a function to take an array of structures as arguments, and convert all their names into capital letters( strupr implementation). print the data in the main function.
 */

#include"student.h"
void marks(int arr[],float *p)
{
	*p=0;
	for(int i=0;i<6;i++)
		*p += arr[i];

	*p /=6;

}

void scan_student(struct student s[],int k)
{
	int i=0;
	printf("ID : ");
	scanf("%d",&s[k].ID);
	printf("name : ");
	scanf("%[^\n]s",s[k].name);
	printf("marks 6 sub : ");
	for(i=0;i<6;i++)
		scanf("%d",&s[k].marks[i]);
	printf("DOB d-m-y : ");
	scanf("%d-%d-%d",&s[k].d,&s[k].m,&s[k].y);
	printf("Gender : ");
	scanf(" %c",&s[k].gender);

	marks(s[k].marks,&s[k].per);
}

void capital(struct student s[],int k)
{

	int i=0,j=0;
	while(s[k].name[i])
	{
		if(s[k].name[i]>=97 && s[k].name[i]<=122)
			s[k].name[j]=s[k].name[j]-32;
		i++;j++;
	}


}


int main()
{
	int n,i,name=0;
	float per=0;
	printf("num of students " );
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
		scan_student(s,i);
	for(i=0;i<n;i++)
		capital(s,i);
	printf("\n");
	for(int k=0;k<n;k++)
	{
		printf("ID :%d\n",s[k].ID);
		printf("name : %s\n",s[k].name);
		printf("marks 6 sub : ");
		for(int i=0;i<6;i++)
			printf("sub-%d %d\n",i+1,s[k].marks[i]);
		printf("DOB d-m-y : %d-%d-%d\n",s[k].d,s[k].m,s[k].y);
		printf("per : %f\n",s[k].per);
		printf("Gender : %c\n",s[k].gender);
		printf("\n");
	}


}

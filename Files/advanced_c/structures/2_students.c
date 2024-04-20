/*2) Create an array of structures using the above template. read the data for all elements of the array. and print the topper name with the highest percentage. 
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
	int n,i,name=0;
	float per=0;
	printf("num of students " );
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
		printstudent(s,i);


	for(i=0;i<n;i++)
		if(s[i].per>per)
		{
			per=s[i].per;
			name=i;
		}
	printf("Topper name : %s ",s[name].name);

	printf("with %f\n",per);
}

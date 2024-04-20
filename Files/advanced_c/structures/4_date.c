/*  4) write a function to take the array of structures as arguments and return the structure element with the oldest date of birth.
    return the structure variable using return statement and array element with index. Return type of the function will be struct student.

    eg.,
    struct student oldest student(struct student arr[])
    { 

    return arr[i]; // find the index at which date of  birth is oldest using date comparison function
    }    */





#include "student.h"

struct student s[10]; 

void scanstudents(struct student s[],int i);
float calculatePercentage(int *arr, int size);
void printstudent(struct student s);
struct student oldest(struct  student arr[]);

int n;

int main()
{
	int i;
	struct student old; 


	printf("Enter the number of students: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanstudents(s,i);
	}

	for (i = 0; i < n; i++)
	{
		printstudent(s[i]);
	}

	old=oldest(s);
	printf("The oldest person is: %s %d %d %d \n",old.name,old.d,old.m,old.y);


	return 0;
}

void scanstudents(struct student s[],int i)
{
	int j;

	printf("Enter ID: ");
	scanf("%d", &s[i].ID);

	printf("Enter name: ");
	scanf(" %s", s[i].name);

	printf("Enter marks for 6 subjects: ");
	for (j = 0; j < 6; j++)
	{
		scanf("%d", &s[i].marks[j]);
	}

	printf("Enter date of birth (dd mm yyyy): ");
	scanf("%d %d %d", &s[i].d, &s[i].m, &s[i].y);

	printf("Enter gender: ");
	scanf(" %c", &s[i].gender);

	s[i].per = calculatePercentage(s[i].marks, 6);
}

float calculatePercentage(int *arr, int size)
{
	int i;
	int add = 0;

	for (i = 0; i < size; i++)
	{
		add = add + arr[i];
	}

	return (float)add / size;
}

void printstudent(struct student s)
{
	int i;

	printf("ID: %d\n", s.ID);
	printf("Name: %s\n", s.name);

	printf("Marks for 6 subjects:\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d ", s.marks[i]);
	}
	printf("\n");

	printf("Date of Birth: %d %d %d\n", s.d, s.m, s.y);

	printf("Percentage: %f\n", s.per);
	printf("Gender: %c\n", s.gender);
}

struct student oldest(struct  student arr[])
{


	int i,j,k;
	for(i=0;i<n-1;i++)
	{	
		j=i+1;
		if((arr[i].y > arr[j].y)   || ((arr[i].y==arr[j].y) && (arr[i].m> arr[j].m ))   || ((arr[i].y==arr[j].y) && (arr[i].m==arr[j].m) && (arr[i].d>arr[j].d )))
		{
			k=j;
		}
	return arr[k];
}}

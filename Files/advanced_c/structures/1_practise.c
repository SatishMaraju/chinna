/*  Practice scanf and printf on each member of the structure using a structure variable using the below structure template:


    struct student
    {
    int ID;
    char name[50];
    int marks[6];
    int d,m,y;
    float per;
    char gender
    };

    create a structure variable of the above type and read ID , name and marks of 6 subjects, date of birth and date of joining using scanf and printf.
    Then calculate the percentage of marks, and store the percentage using per pointer member, and print it.Write a function to calculate the percentage ,and update the percentage member of the structure using function (send only per member using call by reference).

 */

#include <stdio.h>

struct student
{
	int ID;
	char name[50];
	int marks[6];
	int d, m, y;
	float per;
	char gender;
};

void scanstudent(struct student s);
float calculatePercentage(int *arr, int size);
void printstudent(struct student s);

int main()
{
	struct student s;
	scanstudent(s);
	return 0;
}

void scanstudent(struct student s)
{
	int i;
	printf("Enter ID: ");
	scanf("%d", &s.ID);
	printf("Enter name: ");
	scanf(" %s", s.name);
	printf("Enter marks for 6 subjects: ");
	for (i = 0; i < 6; i++)
	{
	scanf(" %d", &s.marks[i]);
	}
	printf("Enter date of birth (dd mm yyyy): ");
	scanf("%d %d %d", &s.d, &s.m, &s.y);
	printf("Enter gender: ");
	scanf(" %c", &s.gender);
	s.per = calculatePercentage(s.marks, 6);
	printstudent(s);
}

float calculatePercentage(int *arr, int size)
{
	int i;
	int a=0;
	for (i = 0; i < size; i++)
	{
	a=a+arr[i];
	}

	return (float)a/ size;
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

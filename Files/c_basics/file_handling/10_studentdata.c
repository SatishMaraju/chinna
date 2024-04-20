/* Write a program, using structures to read details of n students,with details,ID,name,fathername,date of birth and marks, and write those details to a file, one line per student, each detail separated by a comma. The first record must be a Heading. Open the file with .csv extension.
 */


#include <stdio.h>
#include <stdlib.h>

struct Student 
{
	int ID;
	char name[50];
	char fname[50];
	char dob[50];
	float marks;
};

int main() 
{
	FILE *fp;
	int n,i;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	struct Student stu[n];
	printf("Enter details of %d students:\n",n);
	for (i = 0; i < n; i++) 
	{
		printf("Enter details of student%d:\n",i+1);
		printf("ID: ");
		scanf("%d",&stu[i].ID);
		printf("Name: ");
		scanf("%s",stu[i].name);
		printf("Father's Name: ");
		scanf("%s",stu[i].fname);
		printf("Date of Birth: ");
		scanf("%s",stu[i].dob);
		printf("Marks: ");
		scanf("%f",&stu[i].marks);
	}
	fp = fopen("stu.csv","w");
	if (fp == NULL) 
		printf("Unable to create file\n");
	fprintf(fp,"ID,Name,Father's Name,Date of Birth,Marks\n");
	for (i = 0; i < n; i++) 
		fprintf(fp,"%d,%s,%s,%s,%.2f\n",stu[i].ID,stu[i].name,stu[i].fname,stu[i].dob,stu[i].marks);
	fclose(fp);
	printf("Student details written to the file successfully\n");
	return 0;
}


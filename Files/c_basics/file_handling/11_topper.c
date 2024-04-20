/* Write a program to read the above file and print who is topper.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student 
{
	int ID;
	char name[100];
	char fname[100];
	char dob[100];
	float marks;
};

int main() 
{
	FILE *fp;
	struct Student stu;
	float maxMarks = -1;
	char topperName[100];
	fp = fopen("stu.csv","r");
	if (fp == NULL) 
		printf("Unable to open file\n");
	char heading[100];
	fgets(heading,100,fp);
	while (fscanf(fp,"%d,%[^,],%[^,],%[^,],%f\n",&stu.ID,stu.name,stu.fname,stu.dob,&stu.marks) != EOF) 
	{
		if (stu.marks > maxMarks) 
		{
			maxMarks = stu.marks;
			strcpy(topperName,stu.name);
		}
	}
	fclose(fp);
	if (maxMarks == -1)
		printf("No student records found\n");
	else
		printf("The topper is %s with %.2f marks\n",topperName,maxMarks);
	return 0;
}


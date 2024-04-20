/*  Calculate the salary of an employee for a given month and year, after deducting the salary for lose of pay days.
His total monthly salary, and number of days of Loss of Pay (LOP), & month & year are provided as input. Validate the negative cases like –ve salary, -ve date or –ve year in main, before calling other functions.

Print the net salary in main function. 

FileName: main.c

1)       main function. takes input, calls calculatenetsalary function.   */


#include<stdio.h>
#include"Calsal.h"
int main()
{
int ms,l,m,y,ns;
printf("enter the salary and loss of days:\n");
scanf("%d %d %d %d",&ms,&l,&m,&y);
ns=Calsal(ms,l,m,y);
printf("total:%d\n",ns);
}



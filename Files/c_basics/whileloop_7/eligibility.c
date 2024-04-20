/*10) Repeat the eligibility program for n times. Read maths,physics and chemistry marks for n students, and print if each student is eligible for the course or not based on below conditions:
1)Maths >= 60 
2)Physics >=50 
3)Chemistry >= 40

4)Maths + Physics + Chemistry >= 200 
or
5)Maths + Physics >= 150
*/


#include<stdio.h>
int main()
{
	int i=1,n,a,maths,physics,chemistry;
	printf("enter n value:");
	scanf("%d",&n);
	while(i<=n)
	{
	scanf("%d%d%d",&maths,&physics,&chemistry);
	if((maths>=60)&&(physics>=50)&&(chemistry>=40))
	printf("eligible");
	else if((maths+physics+chemistry)>=200)
	printf("eligible");
	else if((maths+physics)>=150)
	printf("eligible");
	else
	printf("not eligible");
	i++;
}}
	

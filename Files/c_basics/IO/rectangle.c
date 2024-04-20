//calculate and print area and perimeter of a rectangle


#include<stdio.h>
int main()
{
	float length,breadth,area,perimeter;
	printf("enter the length and breadth");
	scanf("%f %f",&length,&breadth);
	area =length*breadth;
	perimeter =2*(length+breadth);
	printf("area=%f \n",area);
	printf("perimeter=%f \n",perimeter);
	return 0;
}
	


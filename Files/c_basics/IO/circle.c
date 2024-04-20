//calculate and print area and perimeter of a circle.



#include<stdio.h>
int main()
{
	float radius,area,perimeter;
	printf("enter the radius:%f\n",radius);
	scanf("%f",&radius);
	area=3.14*radius*radius;
	perimeter=2*3.14*radius;
	printf("area:%f\n",area);
	printf("perimeter:%f\n",perimeter);
	return 0;
}

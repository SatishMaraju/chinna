//calculate and print area and perimeter of a square


#include<stdio.h>
int main()
{
	int side,area,perimeter;
	printf("enter the side of a square\n");
	scanf("%d",&side);
	area=side*side;
	perimeter=4*side;
	printf("perimeter of a square:%d\n",perimeter);
	printf("area of a square:%d\n",area);
	return 0;
}

// WAP too implement the proper explantion using switch.


#include <stdio.h>

enum student
{
	sun,mon,tue,wed=5,thu,fri,sat
}s;

int main()
{
	int a;
	while(1)
	{
	scanf("%d",&a);
	switch(a)
	{
	case sun:printf("sunday\n");break;
	case mon:printf("monday\n");break;
	case tue:printf("tuesday\n");break;
	case wed:printf("wednesday\n");break;
	case thu:printf("thursday\n");break;
	case fri:printf("friday\n");break;
	case sat:printf("saturday\n");break;
	default:printf("def case\n");break;
	}
	}
	return 0;
}

// Write a  function that takes a date as input, and returns 1 if the date is valid, 0 if the date is invalid.


#include <stdio.h>
int Valid(int d,int m,int y)
{
	switch(m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: if (d>=1 && d<=31)
				 return 1;
			 else
				 return 0;
			 break;
		case 4:
		case 6:
		case 9:
		case 11: if (d>=1 && d<=30)
				 return 1;
			 else
				 return 0;
			 break;
		case 2: if (y%400==0 || y%100!=0 && y%4==0)
			{
				if (d>=1 && d<=29)
					return 1;
				else 
					return 0;
				break;
			}
			else if (d>=1 && d<=28)
				return 1;
			else 
				return 0;
			break;
		default: return 0;
	}
}
int main()
{
	int d,m,y,s;
	printf("Enter a date: ");
	scanf("%d-%d-%d",&d,&m,&y);
	s=Valid(d,m,y);
	if(s==1)
		printf("%d-%d-%d is a Valid date\n",d,m,y);
	else
		printf("%d-%d-%d is not a Valid date\n",d,m,y);
}

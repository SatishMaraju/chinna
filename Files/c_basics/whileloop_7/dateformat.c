/* Read n number of dates, and print  the date back in below format:

eg., if one of the dates given is 3-4-2000, output should be 
3 April 2000.*/

#include<stdio.h>
int main()
{
	int i=1,n,d,m,y;
	printf("enter the n value:");
	scanf("%d",&n);
	while(i<=n)
	{
	printf("enter date(dd-mm-yyyy):\n");
	scanf("%d-%d-%d",&d,&m,&y);
	switch(m)
	{
	case 1:printf("%dJan%d\n",d,y);break;
	case 2:printf("%dFeb%d\n",d,y);break;
	case 3:printf("%dMar%d\n",d,y);break;
	case 4:printf("%dApr%d\n",d,y);break;
	case 5:printf("%dMay%d\n",d,y);break;
	case 6:printf("%dJun%d\n",d,y);break;
	case 7:printf("%dJul%d\n",d,y);break;
	case 8:printf("%dAug%d\n",d,y);break;
	case 9:printf("%dSep%d\n",d,y);break;
	case 10:printf("%dOct%d\n",d,y);break;
	case 11:printf("%dNov%d\n",d,y);break;
	case 12:printf("%dDec%d\n",d,y);break;
	
	default:printf("nothing");
	}
	i++;
	}
	return 0;
}

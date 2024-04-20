//Input an alphabet. Output its case reverse.



#include<stdio.h>
int main()
{
	char ch;
	printf("enter the charecter:\n");
	scanf("%c",&ch);
	ch>=65?ch<=90?printf("alphabet:%c\n",ch+32):ch>=97?ch<=122?printf("alphabet:%c\n",ch-32):printf("not alphabet"):printf("not alphabet"):printf("not alphabet");
	return 0;
}

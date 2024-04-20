/* convert a given integer to a Roman number.

   Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
   Symbol       Value
   I             1
   V             5
   X             10
   L             50
   C             100
   D             500
   M             1000
 *// 


#include <stdio.h>
int main() 
{
	int n;
	printf("enter the number");
	scanf("%d",&n);
	char *str1[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
	char *str2[]={"","XI","XII","XIII","XIV","XV","XVI","XVII","XVIII","XIX"};
	char *str3[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	char *str4[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	if(n<10)
		printf("%s",*(str1+n));
	else if(n>10&&n<20)
	{
		printf("%s",*(str2+n));    
	}
	else if(n>=10&&n<100){
		printf("%s",*(str3+n/10));
		printf("%s",*(str1+n%10));
	}
	else if(n>=100&&n<1000)
	{
		printf("%s",*(str3+n/100));
		n=n/10;
		printf("%s",*(str2+n/10));
		printf("%s",*(str1+n%10));
	}
}

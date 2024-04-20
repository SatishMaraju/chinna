/* Find the HCf of 2 numbers.  */



#include<stdio.h>
int main()
{
	int a,b,i,k;
	printf("2 nums : ");
	scanf("%d%d",&a,&b);
	for(i=1;i<=a||i<=b;i++){
		if(a%i==0 && b%i==0)
			k=i;
	}
	printf("HCF %d \n",k);
}

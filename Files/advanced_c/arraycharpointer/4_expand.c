/*4) read an integer and print it back in complete number name expansion with place values as below:

  eg., 458
output : four hundred fifty eight

eg., 1458
output: two thousand four hundred fifty eight*/


#include <stdio.h>

int main()
{
	char *ones[]={" ","one","two","three","four","five","six","seven","eight","nine"};
	char *na[]={" ","eleven","tweleve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	char *tens[]={" ","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
	char *name[]={" ","hundred","thousand","lakh"};

	int n,d,c=0,n1;
	printf("Enetr integer:");
	scanf("%d",&n);
	n1=n;
	while(n1)
	{
		c++;
		n1=n1/10;
	}
	n1=n;
	int arr[c];
	for(int i=0;i<c;i++)
	{
		arr[i]=(n1%10);
		n1/=10;
	}

	if(c==1)
	{
		printf("%s ",ones[(arr[0])]);
		printf("\n");
	}
	else if(c==2)
	{
		if(n<11 && n>19)
		{
			printf("%s ",tens[(arr[1])]);
			printf("%s ",ones[(arr[0])]);
		}
		else
		{
			printf("%s ",na[(arr[0])]);
		}
		printf("\n");
	}

	if(c==3)
	{

		printf("%s ",ones[(arr[2])]);
		printf("%s ",name[1]);
		printf("%s ",tens[(arr[1])]);
		printf("%s ",ones[(arr[0])]);
	}
	if(c==4)
	{
		printf("%s ",ones[(arr[3])]);
		printf("%s ",name[2]);

		printf("%s ",ones[(arr[2])]);
		if(arr[2]!=0){
			printf("%s",name[1]);}
		if(arr[1]==1)
		{
			printf("%s",na[(arr[0])]);}
		else{
			printf("%s ",tens[(arr[1])]);
			printf("%s",ones[(arr[0])]);
		}}

	if(c==5)
	{
		printf("%s ",tens[(arr[4])]);
		printf("%s",ones[(arr[3])]);
		printf("%s ",name[2]);

		printf("%s ",ones[(arr[2])]);
		if(arr[2]!=0){
			printf("%s",name[1]);}
		if(arr[1]==1)
		{
			printf("%s",na[(arr[0])]);}
		else{
			printf("%s",tens[(arr[1])]);	
			printf("%s ",ones[(arr[0])]);
		}}
	if(c==6)
	{
		printf("%s ",ones[(arr[5])]);
		printf("%s",name[3]);
		if(arr[4]!=0)
		{
			printf("%s",tens[(arr[4])]);
			printf("%s",ones[(arr[3])]);
		}
		else{
			printf("%s",ones[(arr[3])]);}
		if(arr[3]!=0){
			printf("%s",name[2]);}
		if((arr[4]!=0)){
			printf("%s",name[2]);}
		printf("%s",ones[(arr[2])]);
		if(arr[2]!=0){
			printf("%s",name[1]);}
		if(arr[1]==1)
		{
			printf("%s",na[(arr[0])]);}
		else{
			printf("%s",tens[(arr[1])]);	
			printf("%s ",ones[(arr[0])]);
		}}
	printf("\n");
	return 0;
}

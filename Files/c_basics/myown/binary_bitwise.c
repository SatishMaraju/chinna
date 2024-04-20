// WAP to print the binary for a given number.


#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<8*sizeof(n);i++)
	{
		if(n&(0x1<<(8*sizeof(n)-1)))
		{
			printf("1");
			n=n<<1;
		}
		else
		{
			printf("0");
			n=n<<1;
		}
	}
}


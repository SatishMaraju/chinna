//  Implement your own string comparison function and try calling the function using two string constants as input arguments.



#include<stdio.h>
#include<string.h>

int myownstrcmp(const char *str1,const  char *str2);
int main()
{
	char str1[10];
	char str2[10];
	int c=0;
	scanf("%[^\n]s",str1);
	scanf(" %[^\n]s",str2);
	if(strlen(str1)==strlen(str2))
	{
		c=myownstrcmp(str1,str2);
		if(c==0)	
			printf("Both Strings are equal\n");
		else if(c==-1||c==1)
			printf("Both Strings are not equal\n");
	}
	else
	{
		printf("Both Strings are not equal\n");
	}
}


int myownstrcmp(const char *str1,const char *str2)
{
	int c=0;

	
		for(int i=0;i<strlen(str1);i++)
		{
			if((*(str1+i)-*(str2+i))==0)
			{
				c=0;
			}
			else if((*(str1+i)-*(str2+i))<=0)
			{
				return c=-1;
			}
			else if((*(str1+i)-*(str2+i))>=0)
			{
				return c=1;
			}
		}
                               
		return c;
}



kernel
kernel
Both Strings are equal
km@KernelMasters:~/KM_GITLAB/km52aesd30/Advanced-c/char-pointer-applications$ ./a.out
kernel
kerven
Both Strings are not equal

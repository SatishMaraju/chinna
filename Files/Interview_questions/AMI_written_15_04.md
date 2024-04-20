##DATE:15/04/2024     TOPIC: AMI Wrritten test questions


1) Write a Function that returns the no.of set bits in  a number.

int setbit(int a)
{
	int i=0,c=0;
	for(i=0;i<sizeof(int)*8;i++)
	{
		if(a&0x1){
			c++;
			a=a>>1;}
		else
			a=a>>1;
	}
	return a;
}


2) Write a funtion that returns the string for which the charecters in a string must be in ascending order.


char *string(char *str)
{
	int i=0,j=0;
	for(i=0;*(str+i)!=0;i++)
	{
		for(j=i+1;*(str+j)!=0;j++)
		{
		if((*str+i)>*(str+j))
		{
		char t=*(str+i);
		*(str+i)=*(str+j);
		*(str+j)=t;
		}
		}
	}
	return str;
}


3) Write a function that returns string for which the charecters in a string shuld be in lower case.



char *smallstring(char *str)
{
	int i=0,j=0;
	for(i=0;*(str+i)!=0;i++)
	{
		if(((*str+i)>='A')&&(*(str+i)<='Z'))
		{
			*(str+i)+=32;
		}
	}
	return str;
}


4) Write a function to convert a number from any base to any base.X is the present base and Y is the conversion base and S is the integet number.


int base(int inout1,input2,input3)
{
	int n=sizeof(a)/4;
	if(input1==10)
	{
l1:for(int i=0;input3!=0;i++)
   {
	   arr[i]=input1%input2;
	   input1/=input2;
   }
	}
	if(input2==10)
	{
l2:for(int i=0;input3!=0;i++)
   {
	   arr[i]=input1%10*2^i;
	   input1/=10;
   }
	}
	if(input1==10)
	{
		for(int i=0;input3!=0;i++)
		{
			arr[i]=input1%input2;
			input1/=input2;
		}
	}
	if(input2==2)
	{
		goto l1;
		goto l2:
	}
}


4) Write a Function to perform the duplicates remove opration in linked list.

int fun(int a[])
{
int n=sizeof(a)/sizeof(a[0]);
int *p=a;
for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(a+i)==*(a+j))
			{
				temp=*(a+j);
				for(k=j;k<n;k++)
					*(a+k)=*(a+(k+1));
				*(a+(n-1))=temp;n--;
			}
		}
	}
}
return struct student {.output = &p };

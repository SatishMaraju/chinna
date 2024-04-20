#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{

	int i,j,c;
	char *t;
if(strcmp(argv[1],"-r")==0 && strcmp(argv[2],"-i")==0 ||strcmp(argv[1],"-i")==0 && strcmp(argv[2],"-r")==0 )
{
	for(i=3;i<argc;i++)
	{
		for(j=3;j<argc-1;j++)
		{
			c=strcasecmp(argv[j],argv[j+1]);  
			if(c<0)
			{
				t=argv[j];
				argv[j]=argv[j+1];
				argv[j+1]=t;
			}
		}
	}
	for(i=3; i<argc; i++)
	{
	printf("%s ",argv[i]);
	}
	printf("\n");
}

else if(strcmp(argv[1],"-r")==0  )

{
	for(i=2;i<argc;i++)
	{
		for(j=2;j<argc-1;j++)
		{
			c=strcmp(argv[j],argv[j+1]);  
			if(c<0)
			{
				t=argv[j];
				argv[j]=argv[j+1];
				argv[j+1]=t;
			}
		}
	}
	for(i=2; i<argc; i++)
	{
	printf("%s ",argv[i]);
	}
	printf("\n");
}

else if(strcmp(argv[1],"-i")==0  )
{
	for(i=2;i<argc;i++)
	{
		for(j=2;j<argc-1;j++)
		{
			c=strcasecmp(argv[j],argv[j+1]);  
			if(c>0)
			{
				t=argv[j];
				argv[j]=argv[j+1];
				argv[j+1]=t;
			}
		}
	}
	for(i=2; i<argc; i++)
	{
	printf("%s ",argv[i]);
	}
	printf("\n");
}

else 
{
	for(i=1;i<argc;i++)
	{
		for(j=1;j<argc-1;j++)
		{
			c=strcmp(argv[j],argv[j+1]);  
			if(c>0)
			{
				t=argv[j];
				argv[j]=argv[j+1];
				argv[j+1]=t;
			}
		}
	}
	for(i=1; i<argc; i++)
	{
	printf("%s ",argv[i]);
	}
	printf("\n");
}

}

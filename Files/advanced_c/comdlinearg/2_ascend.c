/*   sorting a list of names received on command line argument, with options like -r and -i

     if -r option is given strings are to be sorted in descending order.
     if -r option is not there, strings are to be sorted in ascending order.

     if -i option is given, strings are to be compared using stricmp function (case insensitive)

     if -i option is not given, strings are to be compared using strcmp function (case sensitive)

     eg.,


     ./sort -r -i abc Abe def dEf gHi aBc iKf deF
     these strings are to be sorted in descending order considering capital and small letters as same.

     ./sort -r abc Abe def dEf gHi aBc iKf deF
     these strings are to be sorted in descending order considering capital and small letters as different.

     ./sort -i abc Abe def dEf gHi aBc iKf deF
     these strings are to be sorted in ascending order considering capital and small letters as same.  

     sort abc Abe def dEf gHi aBc iKf deF
     these strings are to be sorted in ascending order considering capital and small letters as different.
 */

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


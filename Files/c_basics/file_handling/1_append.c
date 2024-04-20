/* Keep reading numbers from user, and write those numbers to a file. Once user presses -1, stop reading, and print all the contents of the file. Open the file everytime with previous contents intact (append mode).  */


#include <stdio.h>
int main()
{
	int x;
	FILE *fp;
	fp=fopen("abc.txt","a+");
	if(fp==NULL)
	{
		printf("bad actually");
	}
	else
	{
		while(1)
		{
			scanf("%d",&x);
			if(x==-1)
			{
				break;
			}
			putw(x,fp);
		}
	}
	fclose(fp);
	fp=fopen("abc.txt","a+");
	while(1)
	{
		x=getw(fp);
		if(x==EOF)
			break;
		printf("%d",x);
	}
	fclose(fp);
}

// Important question on static variable


#include <stdio.h>
#include <string.h>
void main()
{
	static int i=5;
	if(--i)
	{
		main();
		printf ("%d\t",i);
		//main();
	}
}

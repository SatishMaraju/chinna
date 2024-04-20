//define a macro to generate swapping function for int, float , double and character datatypes, as a generic function using macros.



#define SWAP(x,y,z) z=x,x=y,y=z

#include <stdio.h>
int main ()
{
	int a,b,z;
	float c,d,y;
	char e,f,x;
	printf("Enter Integer Values");
	scanf("%d %d",&a,&b);
	printf("Enter float Values:");
	scanf("%f %f",&c,&d);
	printf("Enter character variables:");
	scanf(" %c %c",&e,&f);
	SWAP(a,b,z);
	SWAP(c,d,y);
	SWAP(e,f,x);
	printf("Enter values of a and b:%d %d\n",a,b);
	printf("Enter values of c and d:%f %f\n",c,d);
	printf("Enter values of e and f:%c %c\n",e,f);
}

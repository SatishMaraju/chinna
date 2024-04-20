
PREPROCESSOR ERROR

#include<stdioa.h>
int main()
{
int a=10,b=20,d=0;
int c=a+b;
printf("%d",c);
return 0;
}


--->  compilationstages.c:2:9: fatal error: stdioa.h: No such file or directory
 #include<stdioa.h>
         ^~~~~~~~~~
compilation terminated.

---> we get the output when we remove 'a' at the headerfile.This is a preprocessor errors.
*****************************************************************************************************************************************************

COMPILER ERROR

#include<stdio.h>
int main()
{
int a=10,b=20,d=0;
int c=a+b;
printf("%d",c)
return 0;
}


--->  compilationstages.c: In function ‘main’:
compilationstages.c:34:1: error: expected ‘;’ before ‘return’
 return 0;
 ^~~~~~

---> we get the output when we arrange the ';' at the end of the printf statement.This errors are called comppiler errors.
*****************************************************************************************************************************************************

RUNTIME ERROR

#include<stdio.h>
int main()
{
int a=10,b=20,d=0;
int c=a+b;
printf("%d",a/d);
return 0;
}

--->  Floating point exception (core dumped)

--->  It occurs only when the unconditional/undefined values are faced.
  A user can responsible for those errors.This us also called runtime error.
******************************************************************************************************************************************************

LINKER ERROR

#include<stdio.h>
int main()
{
int a=10,b=20,d=0;
int c=a+b;
printfa("%d",c);
return 0;
}



/tmp/ccY8nlut.o: In function `main':
compilationstages.c:(.text+0x3a): undefined reference to `printfa'
collect2: error: ld returned 1 exit status

---> we get the output whwn we remove 'a' at the printf statements.
This type of errors are called linker errors.



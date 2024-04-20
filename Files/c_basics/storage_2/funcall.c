/*WAP - with a function that prints the following message every nth time it is called : Hello! I am called nth time. Print the appropriate subscript after the n, depending on the last digit.
Output : The function should print the following ,
I am called 1st time.
I am called 2nd time.``
I am called 3rd time…etc.
The subscripts also should be printed appropriately. (st, nd ,rd and th etc.).
Hint : numbers ending with 1 will have st as subscript.
Numbers ending with 2 will have nd as subscript.
Similarly, numbers ending with 3 will have rd and all the remaining numbers will have th.
*/

#include<stdio.h>
int i;
int subscript();
int main()
{
int a;
printf("enter the number:");
scanf("%d",&i);
printf("enter a value");
scanf("%d",&a);
for(i=1;i<=a;i++)
{
//scanf("%d",&i);
subscript();
}}

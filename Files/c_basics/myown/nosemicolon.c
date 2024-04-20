// C program to print all natural numbers upto N without using semi-colon 



#include <stdio.h> 
#define N 10 
int main(int val) 
{ 
	while(val <= N && printf("%d ", val) && main(val+1)){ 
	} 
}

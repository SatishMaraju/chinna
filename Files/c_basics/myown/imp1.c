// Importance of double parenthesis


#include <stdio.h>
void reverse(int i);
int main()
{
	reverse(1);
}
void reverse(int i)
{
	if (i > 5)
		return ;
	printf("%d ", i);
	return reverse((i++, i));
}

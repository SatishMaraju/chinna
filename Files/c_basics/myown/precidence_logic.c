#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n,l=0;
    printf("Enter the no.of elements\n");
    scanf("%d",&n);
    int *p=(int *)malloc(sizeof(int)*n);
    printf("Enter the elements");
    while(l<n){
    scanf("%d",&p[l]);
    l++;
    }
    for(l=0;l<n;l++){
        p[l]=p[l]+p[l+1];  // p[l]=p[l]+p[++l] // precidence takes place
        printf("%d",p[l]);
    }
    return 0;
}

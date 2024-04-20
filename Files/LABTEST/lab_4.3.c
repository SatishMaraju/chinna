#include<stdio.h>
int main()
{
int a,n,i=2,d,m,y,d1,m1,y1;
printf("enter no.of students\n");
scanf("%d",&n);
printf("enter dob of person(dd/mm/yyyy)\n");
scanf("%d/%d/%d",&d,&m,&y);
while(i<=n)
{
printf("enter dob(dd/mm/yyyy)\n");
scanf("%d/%d/%d",&d1,&m1,&y1);
if(y1>y)
d=d1,m=m1,y=y1;
else if(y1<y)
d=d,m=m,y=y;
else if(m1>m)
d=d1,m=m1,y=y1;
else if(m1<m)
d=d,m=m,y=y;
else if(d1>d)
d=d1,m=m1,y=y1;
else if(d1<d)
d=d,m=m,y=y;
else
d,m,y;
printf("%d/%d/%d",d,m,y);
i++;
}}


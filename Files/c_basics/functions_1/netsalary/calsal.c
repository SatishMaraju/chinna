#include"daysinmonth.h"
int Calsal(int ms,int l,int m,int y)
{
int m1,ps,ns;
if((ms<0)||(m<0)||(y<0))
return -1;
m1=NoOfDaysinMonth(m,y);
ps=ms/m1;
ns=ms-(l*ps);
return ns;
}

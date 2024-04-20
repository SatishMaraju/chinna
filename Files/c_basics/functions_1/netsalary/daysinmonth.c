int IsLeapYear(int y);
int NoOfDaysinMonth(int m,int y)
{
	switch(m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 10:
		case 12:return 31;
		case 4:
		case 6:
		case 9:
		case 11:return 30;
		case 2:IsLeapYear(y);
	}
}
int IsLeapYear(int y)
{
	if((y%400==0)||(y%4==0)&&(y%100!=0))
		return 29;
	else
		return 28;
}

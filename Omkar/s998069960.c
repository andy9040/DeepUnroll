#include <stdio.h>

int main(void)
{
	int i,j,k;
	int year,month,day,nengo;
	
	while(scanf("%d %d %d",&year,&month,&day)!=EOF)
	{
	//平成 1989.1.8から
		if(year>=1989 && ((month==1 && day>=8) || month>=2) )
		{
			nengo=year-1988;
			printf("heisei %d %d %d\n",nengo,month,day);
		}
		
	//昭和 1926.12.25から1989.1.7まで
		else if( (year==1926 && month==12 && day>=25) ||
				 (year<=1988 && year>=1927) ||
				 (year==1989 && month==1 && day<=7))
		{
			nengo=year-1925;
			printf("showa %d %d %d\n",nengo,month,day);
		}
		
	//大正 1912.7.30から1926.12.24まで
		else if( (year==1912 && ((month==7 && day>=30) || (month>=8)) ) ||
				 (year<=1925 && year>=1913) ||
				 (year==1926 && ((month<=11) || (month==12 && day<=24))) )
		{
			nengo=year-1911;
			printf("taisho %d %d %d\n",nengo,month,day);
		}
		
	//明治 1868.9.8から1912.7.29まで
		else if( (year==1868 && ((month==9 && day>=8) || (month>=10)) ) ||
				 (year<=1911 && year>=1869) ||
				 (year==1912 && ((month<=6) || (month==7 && day<=29))) )
		{
			nengo=year-1867;
			printf("meiji %d %d %d\n",nengo,month,day);
		}
	//それより以前
		else if( (year<=1867) ||
				 (year==1868 && ((month<=8) || (month==9 && day<=7))) )
			printf("pre-meiji\n");
	}
	
	return 0;
}
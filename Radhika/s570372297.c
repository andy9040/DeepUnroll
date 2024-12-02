#include<stdio.h>

#define FEB 31
#define MAR 60
#define APR 90
#define MAY 121
#define JUN 152
#define JUL 182
#define AUG 213
#define SEP 244
#define OCT 274
#define NOV 305
#define DEC 335

struct data
{
	int month;
	int day;
};

enum
{
	Wed = 0, //0
	Thu, //1
	Fri, //2
	Sat, //3
	Sun, //4
	Mon, //5
	Tue, //6
};

int cal_f11(int month, int day);
void check_today(int day);

main()
{
	struct data time = {0, 0};
	int today = 0, result = 0;
	while(1)
	{
		scanf("%d %d", &time.month, &time.day);
		//printf("month = %d day = %d\n", time.month, time.day);
		if(time.month == 0)
		{
			break;
		}
		today = cal_f11(time.month, time.day);
		check_today(today);
	}
	return 0;
}
int cal_f11(int month, int day)
{
	int result = 0;
	switch(month)
	{
	case 1:
		result = day;
		break;
	case 2:
		result = day + FEB;
		break;
	case 3:
		result = day + MAR;
		break;
	case 4:
		result = day + APR;
		break;
	case 5:
		result = day + MAY;
		break;
	case 6:
		result = day + JUN;
		break;
	case 7:
		result = day + JUL;
		break;
	case 8:
		result = day + AUG;
		break;
	case 9:
		result = day + SEP;
		break;
	case 10:
		result = day + OCT;
		break;
	case 11:
		result = day + NOV;
		break;
	case 12:
		result = day + DEC;
		break;
	}
	return result;
}

void check_today(int day)
{
	//printf("day = %d\n", day);
	switch(day % 7)
	{
	case Wed:
		puts("Wednesday");
		break;
	case Thu:
		puts("Thursday");
		break;
	case Fri:
		puts("Friday");
		break;
	case Sat:
		puts("Saturday");
		break;
	case Sun:
		puts("Sunday");
		break;
	case Mon:
		puts("Monday");
		break;
	case Tue:
		puts("Tuesday");
		break;
	}
}
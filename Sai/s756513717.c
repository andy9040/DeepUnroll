#include<stdio.h>
int main(void)
{
	int days,month,cnt;
	scanf("%d %d",&month,&days);
	while(month!=0&&days!=0){
		switch(month){
			case 1:
			break;
			case 2:
			days=days+31;
			break;
			case 3:
			days=days+60;
			break;
			case 4:
			days=days+91;
			break;
			case 5:
			days=days+121;
			break;
			case 6:
			days=days+152;
			break;
			case 7:
			days=days+182;
			break;
			case 8:
			days=days+213;
			break;
			case 9:
			days=days+244;
			break;
			case 10:
			days=days+274;
			break;
			case 11:
			days=days+305;
			break;
			case 12:
			days=days+335;
			break;
		}
		cnt=(days-1)%7;
		switch(cnt){
			case 0:
			printf("??¨?????\\n");
			break;
			case 1:
			printf("????????\\n");
			break;
			case 2:
			printf("????????\\n");
			break;
			case 3:
			printf("??\?????\\n");
			break;
			case 4:
			printf("????????\\n");
			break;
			case 5:	
			printf("????????\\n");
			break;
			case 6:
			printf("?°´?????\\n");
			break;
		}
	scanf("%d %d",&month,&days);
	}
	return 0;
}
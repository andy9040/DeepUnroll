#include<stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
  int i;
  int num[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
  int m,d,ans;
 
  while(scanf("%d %d",&m,&d) && (m||d)){
    ans = 0;
    for(i=0;i<m-1;i++)ans += num[i];
    ans+=d;
    if(ans%7==0)printf("Wednesday\n");
    if(ans%7==1)printf("Thursday\n");
    if(ans%7==2)printf("Friday\n");
    if(ans%7==3)printf("Saturday\n");
    if(ans%7==4)printf("Sunday\n");
    if(ans%7==5)printf("Monday\n");
    if(ans%7==6)printf("Tuesday\n");
  }
  return 0;
}

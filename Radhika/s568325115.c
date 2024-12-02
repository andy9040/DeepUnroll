#include<stdio.h>

int main(){

  int month[]={31,29,31,30,31,30,31,31,30,31,30,31};
  char week[][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
  int m,d,i;
  int mcnt,cnt;

  while(scanf("%d %d",&m,&d),m!=0){
    mcnt=1;
    cnt=3;
    while(1){
      for(i=1;i<=month[mcnt-1];i++,cnt++){
	if(m==mcnt&&d==i) break;
      }
      if(m=mcnt) break;
      mcnt++;
    }
    printf("%s\n",week[cnt%7]);
  }
  return 0;
}
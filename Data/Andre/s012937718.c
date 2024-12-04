#include<stdio.h>
int main(){
  int i;
  char week[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
  char day[3];
  scanf("%s",day);
  if(day=="SUN"){
    printf("7");
    return 0;
  }
  for(i=1;i<7;i++){
    if(day==week[i]){
      printf("%d",7-i);
      return 0;
    }
  }
    
}
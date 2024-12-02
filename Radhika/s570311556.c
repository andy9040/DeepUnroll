#include <stdio.h>
 
int main(void){
  double money;
  int happiness=0;
  
  do{
    scanf("%lf",&money);
  }while(money < 0 || money >1000000000 || money%1 != 0);
  
  happiness = (money / 500) * 1000 + ((money%500) / 5) * 5;
  
  printf("%d",&happiness);
  
  return 0;
}
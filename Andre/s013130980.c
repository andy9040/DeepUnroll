#include<stdio.h>
int main(void){
  int money = 0;
  scanf("%d",&money);
  int big_gold = money / 500;
  money -= 500 * big_gold;
  int small_gold = money / 5;
  int point = big_gold * 1000 + small_gold * 5;
  printf("%d",point);
  return 0;
}
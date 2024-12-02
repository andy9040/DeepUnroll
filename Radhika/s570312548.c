#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void){
  long int N ;
  scanf("%d",&N);
  long int number;
  int three= 0,five=0,seven = 0,t= 0;;
  for (long int i = 0; i < N; i++) {
    three = 0;
    five = 0;
    seven = 0;
    number = i;
    while(number!=0){
     number = number/10;
     ++digit;
    }
    int s[digit];
    for(int j = 0;j < digit;j++){
      s[i] = S/((int)pow(10, digit-i-1));
      S = S%((int)pow(10, digit-i-1));
    }
    for (int k = 0; k < digit; k++) {
      if(s[i] == 3){
        three++;
      }else if(s[i] == 5){
        five++;
      }else if(s[i] == 7){
        seven++;
      }
    }
    if(three > 0&& five >0||seven > 0){
      t++;
    }
  }
  printf("%d\n",t );
  return 0;
}
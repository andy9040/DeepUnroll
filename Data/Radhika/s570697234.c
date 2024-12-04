include<stdio.h>

int main(void){
  long long int x; scanf("%lld",&x);
  printf("%lld",(x/500)*1000 + ((x-(x/500)*500)/5)*5);
}

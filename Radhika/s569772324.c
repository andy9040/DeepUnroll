#include <stdio.h>
#include <stdint.h>

int main(void) {
  int64_t N;
  scanf("%ld", &N);

  int MIN = 10;
  for(int64_t i = 1; i * i <= N; i++) {
    if(N % i == 0) {
      int64_t B = N / i;
      int M = 0;
      while(B > 0) {
	B /= 10;
	M++;
      }
      MIN = M;
    }
  }
  printf("%d\n", MIN);
  
  return 0;
}

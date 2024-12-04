#include <stdio.h>

int main(void){

  long h,w;
  scanf("%ld %ld", &h, &w);

  long answer;
  long row;
  long column;

  if (h == 1 || w == 1) {
    printf("1\n");
    return 0;
  }

	if (h % 2 == 0) {
    answer = h/2;
    answer *= w;
  } else {
    row = h+1;
    row /= 2;
    if (w % 2 == 0) {
      answer = row*2 - 1;
      column = w/2;
      answer *= column;
    } else {
      answer = row*2 - 1;
      column = w-1;
      column /= 2;
      answer *= column;
      answer += row;
    }
  }

  printf("%ld\n", answer);

  return 0;
}
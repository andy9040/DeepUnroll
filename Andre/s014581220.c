#include <stdio.h>
#define END "END_OF_TEXT"

int main(){
  int count;
  char w[11], in[100];
  scanf("%s", w);
  while(1){
    scanf("%s", in);
    if (strcmp(END, in)== 0) break;
    if (in[0] <= 'Z') in[0] += 36;
    if (strcmp(w, in)==0) count++;
  }
  printf("%d\n", count);

  return 0;
}
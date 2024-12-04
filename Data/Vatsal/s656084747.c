#include <stdio.h>

#define SIZE (10*10*10*10*10)

typedef struct _item_t {
  int A;
  int B;
  int diff;
} item_t;

item_t item[SIZE];

void bsort_reverse(item_t *a, int size)
{
  int i;
  int change = 1;
  item_t tmp;
  
  while (change) {
    change = 0;
    for(i=0; i<(size - 1); i++) {
      if ((a[i].A + a[i].B) < (a[i+1].A + a[i+1].B)) {
        tmp = a[i];
        a[i] = a[i+1];
        a[i+1] = tmp;
        change = 1;
      }
    }// for
  }//while

  return;
}

int main()
{
  int cnt;
  int N;
  long long int result = 0;
  long long int A_total = 0;
  long long int B_total = 0;
  int i;

  cnt = scanf("%d", &N);

  for (i=0; i<N; i++){
    cnt = scanf("%d %d", &item[i].A,&item[i].B);
    item[i].diff = item[i].A - item[i].B;
  }

  bsort_reverse(item, N);
  
  for (i=0; i<N; i++){
    if ((i&1) == 0) {
      A_total += (long long int)item[i].A;
    } else {
      B_total += (long long int)item[i].B;
    }
    result += (long long int)(item[i].A - item[i].B);
  }

//  result = A_total - B_total;

  printf("%lld", result);

  return 0;
}

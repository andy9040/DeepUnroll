#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define mod 1000000007

void swap (int *x, int *y) {
  int temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

/***
* pivotを決め、
* 全データをpivotを境目に振り分け、
* pivotの添え字を返す
***/
int partition (int array[], int left, int right) {
  int i, j, pivot;
  i = left;
  j = right + 1;
  pivot = left;   // 先頭要素をpivotとする

  do {
    do { i++; } while (array[i] < array[pivot]);
    do { j--; } while (array[pivot] < array[j]);
    // pivotより小さいものを左へ、大きいものを右へ
    if (i < j) { swap(&array[i], &array[j]); }
  } while (i < j);

  swap(&array[pivot], &array[j]);   //pivotを更新

  return j;
}

/* クイックソート */
void quick_sort (int array[], int left, int right) {
  int pivot;

  if (left < right) {
    pivot = partition(array, left, right);
    quick_sort(array, left, pivot-1);   // pivotを境に再帰的にクイックソート
    quick_sort(array, pivot+1, right);
  }
}

int main(void){
    int N,K,*a,i,j,s;
    long long int c=0,d=0,t,k;
    scanf("%d %d",&N,&K);
    a = malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            if(a[i] > a[j]) c++;
        }
    }
    quick_sort(a,0,N-1);
    for(i=0;i<N;i++){
        d = d % mod;
        s = 0;
        k = 1;
        d += N - i - 1;
        while(i+k<N && s == 0){
            if(a[i] == a[i+k]){
                k++;
                d--;
            }else{
                s = 1;
            }
        }
    }
    c = c*K % mod;
    d = (d*K % mod)*(K-1)/2 % mod;
    t = (c + d) % mod;
    printf("%lld",t);
    return 0;
}
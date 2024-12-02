#include <stdio.h>
#include <math.h>
#include <string.h>

int gcd(int a,int b){
    if(a<b){
        int now=a;
        a=b;
        b=a;
    }

    int r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }

    return b;
}



/* 値を入れ替える関数 */
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
    int n;
    scanf("%d",&n);
    int A[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    quick_sort(A,0,n-1);
    printf("%d\n",A[n-1]-A[0]);

    return 0;
}
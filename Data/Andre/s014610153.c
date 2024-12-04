#include <stdio.h>
#include <stdlib.h>

int main(){

  int A[2001]={1};

  int a, n, key, q;
  int i, j;

  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d", &a);
    for(j = 2000-a ; j >= 0; j--){
      if(A[j]){
	A[j+a]=1;
      }
    }
  }

  scanf("%d", &q);
  for(i = 0 ; i < q ; i++) {
    scanf("%d", &key);
    if(A[key]){
      printf("yes\n");
    }
    else {
      printf("no\n");
    }
  }
  return 0;
}


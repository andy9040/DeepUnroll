#include<stdio.h>

int search(int, int);

int n, a[50];

int main() {
  int q, m, i;

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &m);
    if(search(0, m) == 1) printf("yes\n");
    else printf("no\n");
  }

  return 0;
}

int search(int i, int x){
  if(x == 0) return 1;
  if(i >= n) return 0;
  return search(i+1, x) || search(i+1, x - a[i]);
}


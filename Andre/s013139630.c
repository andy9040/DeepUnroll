#include <stdio.h>
 
int main() {
  int n;
  int p[20];
  int a = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  for(int i = 0; i < n - 2; i++) {
    for(int j = i + 1; i < n - 1; j++) {
      if(p[i] > p[j]) {
        break;
      }
      for(int k = j + 1; k < n; k++) {
        if(p[j] > p[k]) {
          break;
        } 
        a = j + 1;
        break;
      }
      if (a != 0) {
        break;
      }
    }
    if (a != 0) {
      break;
    }
  }
  printf("%d", a);
  return 0;
}
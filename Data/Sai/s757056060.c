#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  int i, j;

  char str[20];
  char orig[] = "YAKI";
  
  scanf("%s", &str);

  if (strstr(str, orig) == str) {
    printf("Yes");
  }
  else {
    printf("No");
  }

  return 0;
}
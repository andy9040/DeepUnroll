#include <stdio.h>
#include <ctype.h>

int main() {
  int i, str_a_length, str_b_length;
  scanf("%d %d", &str_a_length, &str_b_length);
  char str[str_a_length+str_b_length+2];
  scanf("%s", str);
  for(i = 0; i < str_a_length + str_b_length + 1; i++) {
    if(i < str_a_length || str_a_length < i) {
      if(!isdigit(str[i])) {
        i--;
        break;
      }
    } else {
      if(str[i] != '-') break;
    }
  }
  if(i == str_a_length + str_b_length + 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}

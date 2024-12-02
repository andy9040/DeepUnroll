#include <stdio.h>

int gcd(int number_a, int number_b) {
  int temp;
  if(number_a < number_b) {
    temp = number_a;
    number_a = number_b;
    number_b = temp;
  }
  temp = number_a % number_b;
  while(temp != 0) {
    number_a = number_b;
    number_b = temp;
    temp = number_a % number_b;
  }
  return number_b;
}

int main() {
  int number, i, j, max_value = 0, temp_value;
  scanf("%d", &number);
  int value[number+1];
  for(i = 0; i < number; i++) {
    scanf("%d", &value[i]);
  }
  temp_value = value[1];
  for(i = 0; i < number; i++) {
    for(j = 0; j < number; j++) {
      if(i == j) {
        continue;
      }
      temp_value = gcd(value[j], temp_value);
      if(max_value > temp_value) {
        break;
      }
    }
    if(max_value < temp_value) {
      max_value = temp_value;
    }
    temp_value = value[i];
  }
  printf("%d\n", max_value);
  return 0;
}

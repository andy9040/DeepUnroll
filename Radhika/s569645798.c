#include <stdio.h>

int main(void)
{
  int i;
  int card[2];

  for (i = 0; i < 2; i++) {
    scanf("%d", card + i);
    if (card[i] == 1)card[i] += 13;
  }

  printf((card[0] > card[1]) ? "Alice\n" : ((card[0] < card[1]) ? "Bob\n" : "Draw\n"));

  return(0);
}
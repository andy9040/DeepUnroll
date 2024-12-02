#include <stdio.h>
#include <string.h>

int main(void) 
{
  int i, count = 0;
  char word[11], sentence[1001];

  scanf("%s", word);

  while (1) {
    scanf("%s", sentence);

    if (strcmp(sentence, "END_OF_TEXT\0") == 0) 
      break;

    if (strcmp(sentence, word) == 0) 
      count++;
    }

  printf("%d\n", count);

  return 0;
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
    char word[256], buf[256];
    int i, res = 0;
    scanf("%s", word);
    for (i=0; i<strlen(word); ++i) word[i]=toupper(word[i]);
    while (1) {
        int ok=1;
        scanf("%s", buf);
        if (!strcmp(buf, "END_OF_TEXT")) break;
        for (i=0; i<strlen(buf); ++i) buf[i]=toupper(buf[i]);
        if (!strcmp(buf, word)) res++;
    }
    printf("%d\n", res);
    return 0;
}
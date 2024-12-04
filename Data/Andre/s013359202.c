#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i, sw = 0, se = 0, a = 0;
    char w[11], e[] = "end_of_text";

    scanf("%s", w);
    for (i = 0; w[i] != '\0'; ++i)
        w[i] = tolower(w[i]);

    for (;;) {
        char c = tolower(getchar());
        if (c == '\n')
            c = ' ';

        if (sw == -1) {
            if (c == ' ')
                sw = 0;
        } else {
            if (c == w[sw]) {
                ++sw;
            } else {
                if (c == ' ' && sw == strlen(w))
                    ++a;
                sw = -1;
            }
        }

        if (se == -1) {
            if (c == ' ')
                se = 0;
        } else {
            if (c == e[se]) {
                ++se;
            } else {
                if (se == strlen(e))
                    break;
                se = -1;
            }
        }

        //printf("'%c' -> (%d, %d)\n", c, sw, se);
    }

    printf("%d\n", a);

    return 0;
}
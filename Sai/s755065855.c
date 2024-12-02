#include <stdio.h>
#include <string.h>
 
int
main()
{
        char search[11];
        char *itr, *itr2;
        char buf;
        char test[21];
        int i, cnt = 0;
 
        scanf("%s\n", search);
        scanf("%d\n", &i);
        while (i > 0) {
                itr = test;
                itr2 = test + 10;
                while (scanf("%c", &buf), buf != '\n') {
                        *itr++ = buf;
                        *itr2++ = buf;
                }
                if (strstr(test, search) != NULL) cnt++;
                i--;
        }
        printf("%d\n", cnt);
        return 0;
}
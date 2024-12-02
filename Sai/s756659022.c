#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>

void makeIndex(char *s, int *index, int *pos)
{
    int count[26];
    int i;

    for (i = 0; i < 26; i++) {
        count[i] = 0;
    }

    for (i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'A']++;
    }

    index[0] = 0;
    for (i = 0; i < 26; i++) {
        index[i + 1] = index[i] + count[i];
    }
    
    for (i = 0; i < 26; i++) {
        count[i] = 0;
    }

    for (i = 0; s[i] != '\0'; i++) {
        int c = s[i] - 'A';
        int dest = index[c] + count[c];
        pos[dest] = i;
        count[c]++;
    }
}

int main(int argc, char *argv)
{
    int n, q;
    char s[100001];
//
    int index[27];
    int pos[100000];
//
    int golems[100002];
    int *g = &golems[1];
    char buft[10];
    char bufd[10];
    char t, d;
    int i, j;
    int ans;

    scanf("%d %d", &n, &q);
    scanf("%s", s);

    makeIndex(s, index, pos);

    for (i = 1; i < n + 1; i++) {
        golems[i] = 1;
    }
    golems[0] = 0;
    golems[n + 1] = 0;

    for (i = 0; i < q; i++) {
        scanf("%s %s", buft, bufd);
        t = buft[0];
        d = bufd[0];
        const int c = t - 'A';
        const int jmin = index[c];
        const int jmax = index[c + 1];
        if (d == 'L') { // to left
            for (j = jmin; j < jmax; j++) {
                const int p = pos[j];
                g[p - 1] += g[p];
                g[p] = 0;
            }
        } else { // to right
            for(j = jmax - 1; j >= jmin; j--) {
                const int p = pos[j];
                g[p + 1] += g[p];
                g[p] = 0;
            }
        }
    }

    ans = n - golems[0] - golems[n + 1];

    printf("%d\n", ans);

    return 0;
}

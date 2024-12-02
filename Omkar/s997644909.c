#include <stdio.h>

int i, j, k, l, m, N, Q, X, r;
char S[200010], t[200010], d[200010];

int main(void) {
    scanf("%d%d\n", &N, &Q);
    scanf("%s\n", &S);
    for (j=0;j<Q;j++) scanf("%c%*c%c%*c", &t[j], &d[j]);
    l = 0; r = N-1;
    for (j=Q-1;j>=0;j--) {
        if (d[j] == 'R') if (S[r] == t[j]) r--;
        if (d[j] == 'L') if (S[l] == t[j]) l++;
    }

//    for (i=0;i<N;i++) printf("%d ", G[i]);
    printf("%d\n", r-l+1);
    return 0;
}
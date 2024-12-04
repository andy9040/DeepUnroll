#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define Max 1000

void solve(void){
    char s1[Max], s2[Max];
    scanf("%s\n", s1);
    scanf("%s\n", s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int* mat;
    mat = (int *)malloc(sizeof(int)*(len1+1)*(len2+1));
    rep(len1+1, i) mat[i*(len2+1)] = i;
    rep(len2+1, j) mat[j] = j;

    rep(len1, i) {
        rep(len2, j) {
            int score = (s1[i] == s2[j] ? 0 : 1);
            mat[(i+1)*(len2+1)+j+1] = MIN3(mat[i*(len2+1)+j+1] + 1, mat[(i+1)*(len2+1)+j] + 1, mat[i*(len2+1)+j] + score);
        }
    }
  printf("%d\n", mat[(len1+1)*(len2+1)-1]);
}

int main(void){
  solve();
  return 0;
}
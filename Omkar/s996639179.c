#include<stdio.h>

#define MAX_H 100
#define MAX_W 100
char field[MAX_H][MAX_W+1];
int count, H, W;

void dfs(int x, int y)
{
    if (field[x][y] == '#') {
        field[x][y] = '.';
        if (0 <= x-1 && x-1 < H && field[x-1][y] == '#') dfs(x-1, y);
        if (0 <= x+1 && x+1 < H && field[x+1][y] == '#') dfs(x+1, y);
        if (0 <= y-1 && y-1 < W && field[x][y-1] == '#') dfs(x, y-1);
        if (0 <= y+1 && y+1 < W && field[x][y+1] == '#') dfs(x, y+1);
    } 
    if (field[x][y] == '*') {
        field[x][y] = '.';
        if (0 <= x-1 && x-1 < H && field[x-1][y] == '*') dfs(x-1, y);
        if (0 <= x+1 && x+1 < H && field[x+1][y] == '*') dfs(x+1, y);
        if (0 <= y-1 && y-1 < W && field[x][y-1] == '*') dfs(x, y-1);
        if (0 <= y+1 && y+1 < W && field[x][y+1] == '*') dfs(x, y+1);
    } 
    if (field[x][y] == '@') {
        field[x][y] = '.';
        if (0 <= x-1 && x-1 < H && field[x-1][y] == '@') dfs(x-1, y);
        if (0 <= x+1 && x+1 < H && field[x+1][y] == '@') dfs(x+1, y);
        if (0 <= y-1 && y-1 < W && field[x][y-1] == '@') dfs(x, y-1);
        if (0 <= y+1 && y+1 < W && field[x][y+1] == '@') dfs(x, y+1);
    }
    return ;
}

int main(void)
{
    int i, j;
    while (scanf("%d%d", &H, &W) != EOF) {
        if (!H && !W) break;
        for (i = 0; i < H; i++) {
            scanf("%s", field[i]);
        }
        count = 0;
        for (i = 0; i < H; i++) {
            for (j = 0; j < W; j++) {
                if (field[i][j] != '.') {
                    dfs(i, j);
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
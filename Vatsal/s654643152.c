#include <stdio.h>
#include <string.h>

int w, h;
int island[50][50];

void dfs(int a, int b)
{
	int dx, dy;
	
	island[a][b] = 0;
	
	for (dy = -1; dy < 2; dy++){
		for (dx = -1; dx < 2; dx++){
			if (dx == 0 && dy == 0){
				continue;
			}
			if (0 <= a + dy && a + dy < h && 0 <= b + dx && b + dx < w && island[a + dy][b + dx] == 1){
				dfs(a + dy, b + dx);
			}
		}
	}
	return;
}

int main(void)
{
	int i, j;
	int count;
	
	while (1){
		scanf("%d%d", &w, &h);
		
		if (w + h == 0){
			break;
		}
		
		for (i = 0; i < h; i++){
			for (j = 0; j < w; j++){
				scanf("%d", &island[i][j]);
			}
		}
		
		count = 0;
		for (i = 0; i < h; i++){
			for (j = 0; j < w; j++){
				if (island[i][j]){
					dfs(i, j);
					count++;
				}
			}
		}
		
		printf("%d\n", count);
	}
	
	return (0);
}
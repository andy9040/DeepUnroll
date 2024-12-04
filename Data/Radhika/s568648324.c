#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	int x;
	int y;
	int h;
} info_t;

info_t data[100] = {0};

void get_center_pos(int* cx, int *cy, int n)
{
	int i = 0;
	int j = 0;
	int h1 = 0;
	int h2 = 0;
	int count = 0;
	for( i = 0; i <= 100; i++) {
		for( j = 0; j <= 100;j++) {
			h1 = data[0].h + abs(data[0].x - i) + abs(data[0].y - j);
			int k = 1;
			for( k = 1; k < n; k++) {
				h2 = data[k].h + abs(data[k].x - i) + abs(data[k].y - j);
				if (h1 == h2) {
					count++;
				} else {
					break;
				}
			}
			if( count == (n-1) ) {
				*cx = i;
				*cy = j;
				return;
			}
			count = 0;
		}
	}
	return;
}

int main()
{
	int n_info_count = 0;
	int x,y,h ;
	int i = 0;

	scanf("%d", &n_info_count);
	for(i = 0; i < n_info_count; i++) {
		scanf("%d %d %d", &x, &y, &h);
		data[i].x = x;
		data[i].y = y;
		data[i].h = h;
	}

	get_center_pos(&x, &y, n_info_count);
	h = data[0].h + abs(data[0].x - x) + abs(data[0].y - y);
	printf("%d %d %d\n", x, y, h);
	return 0;
}

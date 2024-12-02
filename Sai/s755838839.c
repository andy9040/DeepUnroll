#include <stdio.h>
#include <stdbool.h>

int main(void)
{   
	int hei, wid; 	
	while (true) {
		scanf ("%d%d", &hei, &wid);
		if (hei == 0 && wid == 0) {
			break;
		} else {
		for (int a = 0; a < wid ; ++a) { //first line
			printf ("#");
		}
		printf("\n");
		for (a = 0; a < hei - 2 ; ++a) {
			for(a = 0; a < wid ; ++a) {
			if (a == 0 || a == wid - 1) {
				printf ("#");
			} else {
				printf(".");
			}
			}
			printf("\n");
		}
		for (a = 0; a < wid ; ++a) {  //last line
			printf ("#");
		}
		printf("\n\n");
		}
	}
    return 0;        
}
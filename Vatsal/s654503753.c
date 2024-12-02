#include <stdio.h>

int main(void)
{
	char mass[8][8];
	int i, j;
	
	while (scanf("%s", mass[0]) != EOF){
		for (i = 1; i < 8; i++){
			scanf("%s", mass[i]);
		}
		
		for (i = 0; i < 8; i++){
			for (j = 0; j < 8; j++){
				if (mass[i][j] == '1' && mass[i][j + 1] == '1'){
					if (mass[i + 1][j] == '1' && mass[i + 1][j + 1] == '1'){
						printf("A\n");
					}
					else if (mass[i][j + 2] == '1' && mass[i][j + 3] == '1'){
						printf("C\n");
					}
					else if (mass[i + 1][j + 1] == '1' && mass[i + 1][j + 2] == '1'){
						printf("E\n");
					}
					else if (mass[i + 1][j - 1] == '1' && mass[i + 1][j] == '1'){
						printf("G\n");
					}
				}
				else if (mass[i][j] == '1' && mass[i + 1][j] == '1'){
					if (mass[i + 2][j] == '1' && mass[i + 3][j] == '1'){
						printf("B\n");
					}
					else if (mass[i + 1][j - 1] == '1' && mass[i + 2][j - 1] == '1'){
						printf("D\n");
					}
					else if (mass[i + 1][j + 1] == '1' && mass[i + 2][j + 1] == '1'){
						printf("F\n");
					}
				}
			}
		}
	}
	return (0);
}
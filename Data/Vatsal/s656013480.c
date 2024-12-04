#include <stdio.h>

void Move(int angle, int *x, int *y, int back)
{

	switch (angle % 4)
	{

	case 0:
		*x += !back ? 1 : -1;
		break;

	case 1:
		*y += !back ? 1 : -1;
		break;

	case 2:
		*x -= !back ? 1 : -1;
		break;

	case 3:
		*y -= !back ? 1: -1;
		break;

	}

}

int search(char *in, int g_x, int g_y)
{

	int i;
	int state[8000] = {0};
	int i_array = 0;

	int x = 0;
	int y = 0;
	int angle = 0;

	while(1)
	{

		int state_check = 0;
		for(i = 0; in[i]; i++)
			if(state[i] == 0)
				state_check = 1;

		if(state == 0)
			return 0;

		char o = in[i_array];
		if(o == 'F'){
			Move(angle, &x, & y, 0);
			state[i_array] = 1;
			i_array++;
		}

		else if(o == 'T'){
			if(state[i_array] == 0){
				angle = (angle + 1) % 4;
				state[i_array] = 1;
			}
			else if(state[i_array] == 1){
				angle = (angle + 3) % 4;
				state[i_array] = 2;
			}
			i_array++;
		}

		else{
			
			if(x == g_x && y == g_y)
				return 1;
			
			while(1){
				i_array--;

				if(i_array == -1)
					return 0;
				
				char c = in[i_array];
				if(c == 'F'){
					Move(angle, &x, &y, 1);
					state[i_array] = 0;
				}
				else{
					if(state[i_array] == 1){
						angle = (angle + 3) % 4;
						break;
					}
					else if(state[i_array] == 2){
						state[i_array] = 0;
						angle = (angle + 1) % 4;
					}
				}
			}

		}

	}

	return 0;

}

int main()
{

	int g_x, g_y;
	char input[8000];
	scanf("%s%d%d", input, &g_x, &g_y);

	int ans = search(input, g_x, g_y);

	printf("%s\n", ans ? "Yes" : "No");

	return 0;

}

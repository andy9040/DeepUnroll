#include <stdio.h>

int main()
{
	int Field[8][8],
		y,x,
		flag,i;
	char progression[9],
		 answer,
		 check;
	
	do
	{
		for(y=0;y<8;y++){
			scanf("%s",progression);
			for(i=0;progression[i];i++){
				Field[y][i] = (progression[i] == '1');
			}
		}
		
		
		flag = 0;
		for(y=0;y<8;y++)
		{
			for(x=0;x<8;x++)
			{
				if(Field[y][x])
				{
					if(Field[y][x+1] && Field[y+1][x] && Field[y+1][x+1]){
						flag = 1;
						answer = 'A';
						break;
					} else if(Field[y+1][x] && Field[y+2][x] && Field[y+3][x]){
						flag = 1;
						answer = 'B';
						break;
					} else if(Field[y][x+1] && Field[y][x+2] && Field[y][x+3]){
						flag = 1;
						answer = 'C';
						break;
					} else if(Field[y+1][x-1] && Field[y+1][x] && Field[y+2][x-1]){
						flag = 1;
						answer = 'D';
						break;
					} else if(Field[y][x+1] && Field[y+1][x+1] && Field[y+1][x+2]){
						flag = 1;
						answer = 'E';
						break;
					} else if(Field[y+1][x] && Field[y+1][x+1] && Field[y+1][x+1]){
						flag = 1;
						answer = 'F';
						break;
					} else if(Field[y][x+1] && Field[y+1][x-1] && Field[y+1][x]){
						flag = 1;
						answer = 'G';
						break;
					}
				}
			}
			if(flag) break;
		}
		
		printf("%c\n",answer);
		scanf("%c",&check);			/*ºÌwhile()àÍµÈ¢Ý½¢B*/
	}while(scanf("%c",&check)!=EOF);
	
	return 0;
}
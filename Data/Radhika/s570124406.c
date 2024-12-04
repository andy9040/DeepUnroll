#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pole{
	struct pole* next;
	int y;
} Pole;

Pole* table[5001];

int search(int x,int y)
{
	if(x < 0 || y < 0 || x > 5000 || y > 5000)return 0;
	if(table[x] != NULL)
	{
		Pole* pt = table[x];
		while(pt->next != NULL)
		{
			if(pt->y == y)
				return 1;
			pt = pt->next;
		}
		if(pt->y == y)
			return 1;
	}
	return 0;
}

void delete(int x,int y)
{
	Pole* pt = table[x];
	if(pt->y == y)
	{
		table[x] = pt->next;
		return;
	}
	while(1)
	{
		if(pt->next->y == y)
		{
			pt->next = pt->next->next;
			return;
		}
		pt = pt->next;
	}
}

int main()
{
	int** poleList;
	int n;
	int i,j,k,l,m,o;
	while(scanf("%d",&n),n)
	{
		for(i = 0;i <= 5000;i++)
		{
			table[i] = NULL;
		}
		poleList = (int**)malloc(sizeof(int*)*n);
		for(i = 0;i < n;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			poleList[i] = (int*)malloc(sizeof(int)*2);
			poleList[i][0] = x;
			poleList[i][1] = y;
			if(table[x] == NULL)
			{
				table[x] = (Pole*)malloc(sizeof(Pole));
				table[x]->next = NULL;
				table[x]->y = y;
			}
			else
			{
				Pole* tmp = table[x];
				table[x] = (Pole*)malloc(sizeof(Pole));
				table[x]->next = tmp;
				table[x]->y = y;
			}
		}
		int maxsq = 0;
		for(i = 0;i < n;i++)
		{
			for(j = (i+1);j < n;j++)
			{
				double posx[6] = {
					poleList[i][0]+poleList[i][1]-poleList[j][1],
					poleList[j][0]+poleList[i][1]-poleList[j][1],
					poleList[i][0]-poleList[i][1]+poleList[j][1],
					poleList[j][0]-poleList[i][1]+poleList[j][1],
					(poleList[i][0]+poleList[j][0]+poleList[i][1]-poleList[j][1])/2,
					(poleList[i][0]+poleList[j][0]-poleList[i][1]+poleList[j][1])/2
				};
				double posy[6] = {
					poleList[i][1]-poleList[i][0]+poleList[j][0],
					poleList[j][1]-poleList[i][0]+poleList[j][0],
					poleList[i][1]+poleList[i][0]-poleList[j][0],
					poleList[j][1]+poleList[i][0]-poleList[j][0],
					(poleList[i][1]+poleList[j][1]-poleList[i][0]+poleList[j][0])/2,
					(poleList[i][1]+poleList[j][1]+poleList[i][0]-poleList[j][0])/2
				};
				int sq = (poleList[i][0]-poleList[j][0])*(poleList[i][0]-poleList[j][0])
					+(poleList[i][1]-poleList[j][1])*(poleList[i][1]-poleList[j][1]);
				if(search(posx[0],posy[0]) && search(posx[1],posy[1]) || search(posx[2],posy[2]) && search(posx[3],posy[3]))
				{
					if(sq < maxsq)continue;
					else maxsq = sq;
				}
				else if(search(posx[4],posy[4]) && search(posx[5],posy[5]))
				{
					if(sq < maxsq*2)continue;
					else maxsq = sq/2;
				}
			}
			delete(poleList[i][0],poleList[i][1]);
		}
		printf("%d\n",maxsq);
	}
	return 0;
}
#include <stdio.h>

void	ft_sort(int *tab, int n)
{
	int tmp;
	int i;
	int j;
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (tab[i] < tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}


int main(void)
{
	int n, m;
	int total = 0;

	scanf("%d%d", &n, &m);
	int a[n + 1];
	int i = 0;
	while (i < n)
	{
		scanf("%d", &a[i]);
		total += a[i];

		i++;
	}
	ft_sort(a, n);
	i = 0;
	float x,y;
	while (i < m)
	{
		
		x = (float)a[i] / total;
		y = (float)1 / (4 * m);
		// printf("%f %f\n", x, y);
		if (x > y)
			i++;
		else
			break ;
	}
	if (i == m)
		printf("Yes");
	else if(i == 0)
		printf("No");
	else
		printf("No");
	return (0);
}

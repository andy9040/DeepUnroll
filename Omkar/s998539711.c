#include <stdio.h>

float ave(int a[],int n);

int main()
{
	int size,number;
	scanf("%d",&size);
	int array[size];
	float average,min;
	for (int i = 0; i < size; ++i)
	{
		scanf("%d",&array[i]);
	}

	average = ave(array,size);
	min = (average - array[0])*(average - array[0]);
	number = 0;

	for (int i = 1; i < size; ++i)
	{
		float dis = (average - array[i])*(average - array[i]);
		if (min>dis){
			number = i;
		}
	}
	printf("%d\n",number);
	return 0;


}

float ave(int a[],int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += a[i];
	}

	return sum/n;

}
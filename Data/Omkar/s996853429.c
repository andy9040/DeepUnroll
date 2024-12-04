/*
	submission # - User: herp_sy
	https://atcoder.jp/contests/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long
#define TBMod 1000000007

// fact(n)
int fact(int n){
	if(n == 1)	return 1;
	else return (n * fact(n - 1));
}

// nCr(n,r)
int nCr(int n, int r){
	if(r == 0 || r == n)	return 1;
	else if(r == 1)	return n;
	return (nCr(n - 1, r - 1) + nCr(n - 1, r));
}

// gcd(a,b)
int gcd(int a,int b){
	if(a == 0) return b;
	else if(b == 0) return a;
	else return gcd(b,a % b);
}

// lcm(a,b)
int lcm(int a,int b){
	return (a * b) / gcd(a,b);
}

// swap(&a, &b);
void swap(int *a,int *b){
	int tmp;
	tmp = *a;	*a = *b;	*b = tmp;
	return;
}

// qsort(array, size, sizeof(int),comp);
int ASC(const int *a,const int *b){
	return (*a - *b);
}

int DESC(const int *a,const int *b){
	return (*b - *a);
}

// append(array,*size,addNum)
void append(int *array,int *size,int num){
	realloc(array, sizeof(int) * (*size + 1));
	array[(*size)] = num;
	++(*size);
}

// pop(array,*size) & nongetpop(array,*size)
int pop(int *array,int *size){
	int temp = array[(*size - 1)];
	nongetpop(array,&(*size));
	return temp;
}

int nongetpop(int *array,int *size){
	realloc(array,sizeof(int) * (*size - 1));
	--(*size);
}

int main(int argc, char const *argv[])
{
	int n,d;
	int x[13][13];
	int dis,temp;
	int cnt = 0;
	scanf("%d%d",&n,&d);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < d; ++j)	scanf("%d",&x[i][j]);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			dis = 0;
			for (int k = 0; k < d; ++k)
			{
				temp = abs(x[i][k] - x[j][k]);
				dis += (temp * temp);
			}
			if( (int)sqrt((double)dis) * (int)sqrt((double)dis) == dis ){
				++cnt;
			} 
		}
	}
	printf("%d\n", cnt);
	return 0;
}

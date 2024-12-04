#include<stdio.h>

int nextInt();
void sort(int *a, int size);

int N, i;
int A[100000], B[100000], C[100000];
long long int a, b;

int main(){
	N=nextInt();
	for(i=0; i<N; i++){
		A[i]=nextInt();
		B[i]=nextInt();
		C[i] = A[i] + B[i];
		b += B[i];
	}
	sort(C, N);
	for(i=0; i<N; i+=2){
		a += C[i];
	}
	printf("%lld\n", a-b);
	return 0;
}

int nextInt(){
	int f=0; char c=getchar();
	while((c<'0')||('9'<c)){c=getchar();}
	while((c>='0')&&(c<='9')){f=f*10+(c-'0'); c=getchar();}
	return f;
}

char compare(int *x, int *y){
	return *x > *y;
}

int* med3(int *x, int *y, int *z){
	if(compare(x, y)){
		if (compare(y, z)){return y;}else if(compare(z, x)){return x;}else{return z;}
	} else {
		if (compare(z, y)){return y;}else if(compare(x, z)){return x;}else{return z;}
	}
}

void quickSort(int *left, int *right){
	if(left >= right){return;}
	int *pivot = med3(left, left+(right-left)/2, right);
	int *l=left, *r=right;
	int t;
	while(1){
		while (compare(l, pivot)){l++;}
		while (compare(pivot, r)){r--;}
		if(l>=r){break;}
		t=a[l]; a[l]=a[r]; a[r]=t;
		l++; r--;
	}
	quickSort(left, l-1);
	quickSort(r+1, right);
}

void sort(int *a, int size){
	quickSort(a, a+size-1);
}

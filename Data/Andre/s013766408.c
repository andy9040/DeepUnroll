#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
//    return *(long long*)a - *(long long*)b;
}
//  qsort(A, b, sizeof(int), compare_int);

//long long  factorial(long long n) {
//    if (n > 0) {
//        return n * factorial(n - 1);
//    } else {
//        return 1;
//    }
//}
long long  factorial(long long n, long long depth) {
    if (n > 1) {
        depth++;
        return factorial(n / 2, depth);
    } else {
        return depth;
    }
}

int min(int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}

int distance(int a, int b) {
  return abs(a-b)*abs(a-b);
}



//int ()
/*
int triangle(int a, int b, int c){
  if(a<b+c){
    if(b<c+a){
      if(c<a+b){
        printf("1\n");
        return 1;
      }
    }
  }
  printf("1\n");
  return 0;
}
*/

int main()
{
  int  a, b, c, d, e, X, Y ,r;
//  unsigned long long  a, b, c, d, e, X, Y;
  //  double  c;
// long long  A[200003]={};
  int  A[200003]={};
  int  B[100003]={};
//  int  C[100003][100001]={};
  int  C[100003]={};

  int  flg=0;

//  char s[101][101]={};
  char s[100001]={};
  char t[100001]={};
//  int N, M;
//  int A[1000000001]={};
//  long long  C[101]={};
  int i,j,k;
  long long p=0,q=0;
//  int flag=0;
//  int tmp=0;
//  char tmp[101]={};
//  long long min=10000000000;
//  long long min=100000001;
  int min =100000001;
  int len=0;
  int l=0;
//  int r=1000001;
  int cnt=0;
  int num=0;
  int num1=0;
  int num2=0;
  long long  ans=0;
  int ans_ac=0;
  int ans_wa=0;
  int max=0;
  long long sum=0;
  int addr=0;
  int ptn=0;
  int  tmp=0;
  double per=0; 
//  bool on_off[100]={};
  
//  char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  //  a=0;
  scanf("%d %d", &a, &b);
  
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
    sum=sum+A[i];
  } 

  qsort(A, a, sizeof(int), compare_int);
  for(i=0;i<a;i++){
//    printf("%d ",A[i]);
    
  } 
  for(i=a-1;i>=a-b;i--){
//      printf("%d %d\n",A[i],sum/(4*a));
    if(A[i]<(double)(sum/(4*a))){
      printf("No\n");
      return 0;
    }
  } 
  
  
  printf("Yes\n");
  
return 0;
}

#include<stdio.h>
#define MAX 101

void pop(int A[],int *top){

 printf("%d\n",A[(*top)]);
 (*top)--;

 return;
}

void push(int A[],int x,int *top){

 (*top)++;
 A[(*top)]=x;

 return;
}

int main(){
 int x;
 int A[MAX];
 int top=-1;

 while(scanf("%d",&x)!=EOF){

  if(x==0)pop(A,&top);

  else push(A,x,&top);

 }

 return 0;
}

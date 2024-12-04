#include<stdio.h>

void kcut(int a[],int k,int n){
  int i,j,b[200];
  for(i=0,j=2*n-k;i<k;i++,j++){
    b[j] = a[i];
  }
  for(i=k,j=0;j<2*n-k;i++,j++){
    b[j] = a[i];
  }
  for(i=0;i<2*n;i++){
    a[i] = b[i];
    printf("%d kcut\n",a[i]);	
  }
  return;
}

void riffle(int a[],int n){
  int i,j=0,b[200];
  for(i=0;i<n;i++){
    b[j] = a[i];
    j++;
    b[j] = a[i+n];
    j++;
  }
  for(i=0;i<2*n;i++){
    a[i] = b[i];
    printf("%d riffle\n",a[i]);
  }
  return;
}

int main(void){
  int n,m,a[200],b[1000],i;
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d",&b[i]);
  }
  for(i=0;i<2*n;i++){
    a[i] = i + 1;
  }
  for(i=0;i<m;i++){
    if(b[i]==0)riffle(a,n);
    else kcut(a,b[i],n);
  }
  for(i=0;i<2*n;i++){
    printf("%d\n",a[i]);
  }
  return(0);
}
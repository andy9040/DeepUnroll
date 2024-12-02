#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
  int A= *(int *)a;
  int B= *(int *)b;
  return A-B;
}
int main(){
  int n,m,ans=0;
  scanf("%d %d",&n,&m);

  int a[m],i;
 
   for(i=0;i<m;i++){
  scanf("%d",&a[i]);
  }
  qsort(a,m,sizeof(int),cmp);
  int b[m-1];
  for(i=0;i<m-1;i++){
  b[i]=a[i+1]-a[i];
  }
  qsort(b,m-1,sizeof(int),cmp);
  int d,e,f;
    if(n>=m){
    printf("0\n");
  }
  else{
  for(i=0;i<(m-n);i++){
    ans+=b[i];
  }
      printf("%d\n",ans);
  }
}
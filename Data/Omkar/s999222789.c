#include<stdio.h>
#include<stdio.h>
//小さい順にソート
int c[200002];
void merge(int i,int j,int *s){
  if(i!=j){
    merge(i,(i+j)/2,s);
    merge((i+j)/2+1,j,s);
    int a=i,b=(i+j)/2+1;
    int d;
    for(d=i;d<=j;d++){
      if((i+j)/2<a){
        c[d]=s[b];
        b++;
      }
      else if(j<b){
        c[d]=s[a];
        a++;
      }
      else if(s[a]<s[b]){
        c[d]=s[a];
        a++;
      }
      else{
        c[d]=s[b];
        b++;
      }
    }
    for(d=i;d<=j;d++)
      s[d]=c[d];
  }
}

int main(){
  int n,m,i;
  scanf("%d%d",&n,&m);
  int x[m+1],middle[m],min=0;
  for(i=0;i<m;i++)
    scanf("%d",&x[i]);
  merge(0,m-1,x);
  if(m==1){
    printf("0\n");
    return 0;
  }
  for(i=0;i<m-1;i++)
    middle[i]=x[i+1]-x[i];
  merge(0,m-2,middle);
  for(i=0;i<m-n;i++)
    min+=middle[i];
  printf("%d\n",min);
  return 0;
}

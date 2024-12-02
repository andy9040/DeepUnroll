#include <stdio.h>
int ex_search(int a[],int n,int j,int x,int *check_p){
    if(*check_p==1)return 1;
    if(x==0){*check_p=1;return 1;}
    j++;
    if(j<=n) {
        int new_x = x - a[j];
        if(new_x>=0)ex_search(a,n,j,new_x,check_p);
        ex_search(a,n,j,x,check_p);
    }
    return 0;
}

int main() {
  int i,x,m,n;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
  scanf("%d",&a[i]);
  }

  scanf("%d",&m);
  int j;
  int check=0;
  int *check_p=&check;
  for(i=0;i<m;i++){
      j=-1;
      check=0;
      scanf("%d",&x);
      ex_search(a,n,j,x,check_p);
      if(check==1)printf("yes\n");
      if(check==0)printf("no\n");
  }
  return 0;
}

#include<stdio.h>
#define M 2000

int main(){

  int i,j,n,q,num,hai[M+1]={0};
  scanf("%d",&n);


  for(i=0;i<n;i++){
    scanf("%d",&num);

      for(j=M-num;0<j;j--){
        if(hai[j]){
          hai[j+num]= 1;
        }
      }

    hai[num]=1;
  }

  scanf("%d",&q);


  for(i=0;i<q;i++){
    scanf("%d",&num);

    if(hai[num]){
      printf("yes\n");
    }
    else printf("no\n");
  }

  
  return 0;
}


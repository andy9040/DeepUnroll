#include <stdio.h>

void search(int,int,int,int data[]);
int count;

main(){
  int n, temp, data[100], ans, h, t, i;

  while(1){
    scanf("%d", &n);
    if(n==0) break;

    for(i=0;i<n;i++){
      scanf("%d", &data[i]);
    }
    scanf("%d", &ans);

    h=0;
    t=n-1;
    count=0;
    search(h, t, ans, data);
  }
  return 0;
}

void search(int h, int t, int ans, int data[]){
  int a;
  
  a=(t+h)/2;

  count++;
  if(data[a]==ans){
    printf("%d\n", count);
    return;
  }
  if (t==h){
    printf("%d\n",count);
    return;
  }
  if(data[a]>ans) t=a-1;
  else if(data[a]<ans) h=a+1;
  
  search(h, t, ans, data);
}
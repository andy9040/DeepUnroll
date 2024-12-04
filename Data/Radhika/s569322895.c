#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int find();

#define N 100000

char str2[N][12];
int k, l, judge[N];

int main(){

  int i, n;
  char str[N][10];

  scanf("%d",&n);
  k=0;
  l=0;
  for(i=0;i<n;i++){

    scanf("%s",str[i]);

    if(strcmp(str[i],"insert")==0){
      scanf("%s",str2[k]);
      k++;
    }
    else {
      judge[l] = find();
      l++;
    }
  }
  for(i=0;i<l;i++){
    if(judge[i]==1) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
int find(){
  char a[12];
  int j;

  scanf("%s",a);
  for(j=0;j<=k/2;j++){
    if(strcmp(str2[j],a)==0){
      return 1;
    }
    else if(strcmp(str2[k-1-j],a)==0){
      return 1;
    }
  }
  return 0;
}
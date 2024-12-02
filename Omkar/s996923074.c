#include <stdio.h>
#include <string.h>
#define N 10000000
 
void insert(int);
void inorder(int);
void preorder(int);
int find(int, int);
 
typedef struct{
  int k, r, l;
}Node;
 
Node T[N+1];
int M;
 
void insert(int x){
  int n = 0;
  while(1){
    if(x < T[n].k){
      if(T[n].l == -1){
        T[n].l = M;
        T[M++].k = x;
        break;
      }
      else n = T[n].l;
    }
    else{
      if(T[n].r == -1){
        T[n].r = M;
        T[M++].k = x;
        break;
      }
      else n = T[n].r;
    }
  }
}
 
void inorder(int n){
  if(T[n].l != -1){
    inorder(T[n].l);
  }
  printf(" %d", T[n].k);
  if(T[n].r != -1){
    inorder(T[n].r);
  }
}
 
void preorder(int n){
  printf(" %d",T[n].k);
  if(T[n].l != -1){
    preorder(T[n].l);
  }
  if(T[n].r != -1){
    preorder(T[n].r);
  }
}
 
int find(int n, int x){
  if(T[n].k == x) return 1;
  if(x < T[n].k && T[n].l != -1){
      if(find(T[n].l, x)) return 1;
    }
    if(T[n].k < x && T[n].r != -1){
      if(find(T[n].r, x)) return 1;
    }
    return 0;
}
 
int main(){
  int n, i, x, in, first=1;
  char str[100];
 
  scanf("%d",&n);
 
  for(i=0; i<=n; i++){
    T[i].k = T[i].l = T[i].r = -1;
  }
  M = 0;
  while(n--){
    scanf("%s",str);
    if(!strcmp(str, "insert")){
      scanf("%d", &x);
      if(first){
        T[M++].k = x;
        first = 0;
      }
      else insert(x);
    }
    else if(!strcmp(str, "find")){
      scanf("%d", &in);
      if(find(0., in) == 1) printf("yes\n");
      else printf("no\n");
    }
    else{
      inorder(0);
      printf("\n");
      preorder(0);
      printf("\n");
    }
  }
  return 0;
}
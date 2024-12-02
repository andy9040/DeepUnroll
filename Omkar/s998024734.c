#include<stdio.h>
#include<stdlib.h>
#define MAX 500001
#define NIL NULL
struct N{
  int key;
  struct N *parent;
  struct N *left;
  struct N *right;
};
typedef struct N * node;

void insert(int);
void ino(node);
void pr(node);
node Find(node root, int n){
  if(root == NIL || root->n == n)return n;
  if(root->n > n) return find(root->left,n);
  else return Find(root->right,n);
}
node r;

int main(){
  int i,n,x;
  char c[20];
  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%s", c);
  
    if(c[0] == 'i'){
      scanf("%d", &x);
      insert(x);
    }
    else if(c[0] == 'f'){
      scanf ("%d" , &x);
      node t = Find(r , x);
      if(t!= NIL)printf("yes\n");
      else printf("no\n");
    }
    else if(c[0] == 'p'){
      ino(r);
      printf("\n");
      pr(r);
       printf("\n");
    }
  }
  return 0;
}

void insert(int n){
  node x = NIL;
  node y = r;
  node z;
  z = malloc(sizeof(struct N));
  z->key = n;
  z->left = NIL;
  z->right = NIL;
  while(y!=NIL){
    x = y;
    if(z->key < y->key) y = y->left;
    else y = y->right;
  }
  z->parent = x;
  if(x == NIL)r = z;
  else if( z->key < x->key) x->left = z;
  else x->right = z;
}

void ino(node a){
  if(a!=NIL){
    ino(a->left);
    printf(" %d", a->key);
    ino(a->right);
}
}

void pr(node a){
  if(a!=NIL){
    printf(" %d" , a->key);
    pr(a->left);
    pr(a->right);
  }
}
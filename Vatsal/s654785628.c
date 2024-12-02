#define N 2000000
#include<stdio.h>
#include<stdlib.h>

struct Node{
  int key;
  struct Node *left,*right,*parent;
};

struct Node *root,*NIL;

void insert(int n){
  struct Node *y;
  struct Node *x;
  struct Node *z;
  y = NIL;
  x = root;
  z = (struct Node *)malloc(sizeof(struct Node));
  z->key = n;
  z->left = NIL;
  z->right = NIL;
  while(x != NIL){
    y = x;
    if(z->key<x->key){
      x = x->left;
    }
    else{
      x = x->right;
    }
  }
  z->parent = y;
  if(y == NIL){
    root = z;
  }
  else{
    if(z->key < y->key){
      y->left = z;
    }
    else{
      y->right = z;
    }
  }
}


struct Node *find(struct Node *k,int u){
  while(k != NIL && u != k->key){
    if(u < k->key){
      k = k->left;
    }
      else{
	k = k->right;
      }
  }
      return k;
}

void middle(struct Node *k){
  if(k == NIL)return;
  middle(k->left);
  printf(" %d",k->key);
  middle(k->right);
 
}

void precede(struct Node *k){
  if(k == NIL)return;
  printf(" %d",k->key);
  precede(k->left);
  precede(k->right);
}








int main(){
  int n,i,j;
  char m[N];
  struct Node *l;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",m);
    if(m[0] == 'i'){
      scanf("%d",&j);
      insert(j);
    }
  else if(m[0] == 'f'){
      scanf("%d",&j);
      l = find(root,j);
      if(l != NIL){printf("yes\n");}
	else{printf("no\n");
	}
    }
    else if(m[0] == 'p'){
      middle(root);
      printf("\n");
      precede(root);
      printf("\n");
    }
  
  }
  return 0;
}
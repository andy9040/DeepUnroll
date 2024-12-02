#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
  long key;
  struct node *parent,*left,*right;
};

struct node *root,*NIL;

void insert(long k){
  struct node *y = NIL,*x = root,*z;

  z = (struct node *)malloc(sizeof(struct node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while(x != NIL){
    y = x;
    if(z->key < x->key)x = x->left;
    else x = x->right;
  }
  
  z->parent = y;

  if(y == NIL) root = z;
  else if(z->key < y->key) y->left = z;
  else y->right = z;
}

struct node* find(struct node *v,long k){
  while(v != NIL && k != v->key){
    if(k < v->key) v = v->left;
    else v = v->right;
  }
  return v;
}

void inorder(struct node *v){
  if(v == NIL)return;
  inorder(v->left);
  printf(" %d",v->key);
  inorder(v->right);
}

void preorder(struct node *v){
  if(v == NIL)return;
  printf(" %d",v->key);
  preorder(v->left); 
  preorder(v->right);
}

int main(){
  int m;
  long k,f;
  int i,j = 0,l = 0;
  char com[10];
  
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%s",com);
    
    if(strcmp(com,"find") == 0){
      scanf("%ld",&f);
      struct node *p = find(root,f);
	if(p!=NIL)printf("yes\n");
	else printf("no\n");  
    }
    
    if(strcmp(com,"insert") == 0){
      scanf("%ld",&k);
      insert(k);
    }
     
    else if(strcmp(com,"print") == 0){      
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
      continue;
    }
  }
  
  return 0;  
}


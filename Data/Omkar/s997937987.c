#include <stdio.h>
#include <stdlib.h>
#define NIL NULL
struct node{
  struct node *right;
  struct node *left;
  struct node *p;
  int key;
};

typedef struct node * Node;

Node root;

Node treeMinimum(Node x){
  while(x->left != NIL) inorder(root);
      printf("\n");
      
    x=x->left;

  return x;
}

Node treeMaximum(Node x){
  while(x->right != NIL)
    x=x->right;

  return x;
}

Node treeSearch(Node x,int k){
  if(x==NIL && k==x->key)
    return x;

  if(k < x->key)
    return treeSearch(x->left,k);
  else
    return treeSearch(x->right,k);

}

Node treeSuccessor(Node x){
  Node y;


  if(x->right != NIL)
    return treeMinimum(x->right);

  y=x->p;
  while(y != NIL && x==y->right){
    x=y;
    y=y->p;
  }

  return y;
}

void treeDelete(Node z){
  Node y;
  Node x;

  if(z->left==NIL || z->right==NIL)
    y=z;
  else
    y=treeSuccessor(z);


  if(y->left != NIL)
    x=y->right;
  else
    x=y->right;

  if(x!=NIL)
    x->p=y->p;

  if(y->p==NIL)
    root=x;
  else if(y==y->p->left)
    y->p->left=x;
  else
    y->p->right;

  if(y!=z)
    z->key = y->key;

}

void insert(int k){
  Node y = NIL;
  Node x = root;
  Node z;

  z=malloc(sizeof(struct node));
  z->key=k;
  z->left=NIL;
  z->right=NIL;


  while(x != NIL){
    y=x;
    if(z->key < x->key)
      x=x->left;
    else
      x=x->right;
  }

  z->p=y;

  if(y==NIL)
    root=z;
  else
    if(z->key < y->key)
      y->left=z;
    else
      y->right=z;
}

void inorder(Node x){
  if(x != NIL){
    inorder(x->left);
      printf(" %d",x->key);
  inorder(x->right);
  }
}

void preorder(Node x){
  if(x != NIL){
    printf(" %d",x->key);
    preorder(x->left);
    preorder(x->right);
  }
}

int main(){
  int n,i,x;
  char com[20];
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s",com);
    if(com[0]== 'f'){
      scanf("%d",&x);
      Node t = treeSearch(root,x);

      if(t != NIL) printf("yes\n");
      else printf("no\n");
    }else if(com[0]=='i'){
      scanf("%d",&x);
      insert(x);
    }else if(com[0]=='p'){
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }else if(com[0]=='d'){
      scanf("%d",&x);
      treeDelete(treeSearch(root,x));
    }
  }

  return 0;
}
    


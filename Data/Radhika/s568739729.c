#include<stdio.h>
#include<stdlib.h>

struct Node{
  int key;
  struct Node *r,*l,*p;
};

 struct Node *B,*NIL;

void insert(int k){
   struct Node *y = NIL;
   struct Node *x = B;
   struct Node *z;

   z = (struct Node *)malloc(sizeof(struct Node));
   z->key = k;
   z->l = NIL;
   z->r = NIL;

   while(x!=NIL){
     y = x;
     
     if(z->key < x->key){
       x = x->l;
     }
     else x = x->r;
   }
   
   z->p = y;
   if(y == NIL ){
     B=z;
   }
   else if(z->key < y->key){
       y->l = z;
     }
   else y->r = z;
}

struct Node* find(int k,struct Node *u){
  while( u != NIL && k != u->key ){
    if(k < u->key) u = u->l;
    else u = u->r;
  }
  return u;
}


void inorder(struct Node *u){
  if(u==NIL) return;
  inorder(u->l);
  printf(" %d",u->key);
  inorder(u->r);
}

void preorder(struct Node *u){
  if(u == NIL )return;
  printf(" %d",u->key);
  preorder(u->l);
  preorder(u->r);
}

int main(){
  
  int i,j,x,y;
  char G[8];
  struct Node *s;
  scanf("%d",&x);
  
  for(i=0;i<x;i++){
    scanf("%s",&G);
    
    if(G[0] == 'i'){
      scanf("%d",&y);
      insert(y);
    }
    
    else if(G[0] == 'p'){
      inorder(B);
      printf("\n");
      preorder(B);
      printf("\n");
    }

    else if(G[0]=='f'){
      scanf("%d",&y);
      s = find(y,B);
      if(s != NIL) printf("yes\n");
      else if(s == NIL)printf("no\n");
    }
  }
  return 0;
}

  


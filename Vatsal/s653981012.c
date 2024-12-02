#include<stdio.h>
#include<stdlib.h>
#define NIL NULL
struct node{
  int key;
  struct node *right,*left,*parent;
};
typedef struct node * Node;
Node root = NIL;
void prerder(Node);
void insert(int);
int search(int v,Node u)
{
    if(u==NIL){
        return 0;
    }
    if( u->key == v ){
    return 1;
    }else if( u->key < v ){
    return search(v,u->right);
    }else{
    return search(v,u->left);
    }
}



void insert(int k){
struct node *y=NIL;
struct node *x=root;
struct node *z;

z = malloc(sizeof(struct node));
z->key = k;
z->left = NIL;
z->right = NIL;

  while( x != NIL ){
    y = x;
    if( z->key < x->key ) x = x->left;
    else x = x->right;
  }

  z->parent = y;
  if( y == NIL ){
    root = z;
  }
  else if( z->key < y->key ){
    y->left = z;
  }
  else y->right = z;
}

void inorder(Node z){
 if(z==NIL)return;
  inorder(z->left);
  printf(" %d",z->key);
  inorder(z->right);
}

void preorder(struct node *z){
  printf(" %d",z->key);
  if( z->left != NIL ){
    preorder(z->left);
  }
  if( z->right != NIL ){
    preorder(z->right);
  }
}

int main(void){
  int m;
  int i;
  int f;
  int q;
  char kb[84];
  char cf[82];
  scanf("%d", &m);
  i = 0;
  while(i < m ){
  	
    scanf("%s", cf);
    if ( cf[0] == 'i' ){
      scanf("%d", &f);
      insert(f);
    }

    else if( cf[0] == 'p' ){
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
    else {
	scanf("%d", &f);
        if(search(f,root)){
        printf("yes\n");
	
	}else{
                printf("no\n");
    
  }
}

 i++;
}

  return 0;
}

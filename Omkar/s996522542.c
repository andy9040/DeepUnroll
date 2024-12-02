#include<stdio.h>
#include<stdlib.h>

struct node{
  struct node *right;
  struct node *left;
  struct node *parent;
  int key;
};
typedef struct node * Node;
#define NIL NULL

Node root;

void insert(int k){
  Node y = NIL;
  Node x = root;
  Node z;

  z = malloc(sizeof(struct node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  y = NULL; //xの親
  x = root; //Tの根
  while(x != NULL){
    y = x; //親を設定
    if(z->key < x->key) x = x->left; //左の子へ移動
    else x = x->right; //右の子へ移動
  }

  z->parent = y;

  if(y == NULL) root = z; //Tが空の場合
  else if(z->key < y->key) y->left = z; //zをyの左の子にする
  else y->right = z; //zをyの右の子にする

}

Node treeSearch(Node u, int k){
  while(u != NULL) {
    if(k == u->key) return 0;
    else if(k <= u->key){
      u = u->left;
    } else {
      u = u->right;
    }
  }
  return NIL;
}

void inorder(Node x){
  if(x!= NIL){
    inorder(x->left);
    printf(" %d",x->key);
    inorder(x->right);
}
}
void preorder(Node x){
  if(x!= NIL){
    printf(" %d",x->key);
    preorder(x->left);
    preorder(x->right);
  }
}

int main(){
  int n, i, x;
  char com[20];
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ){
    scanf("%s", com);
    if ( com[0] == 'f' ){
      scanf("%d", &x);
      Node t = treeSearch(root, x);
      if ( t == NIL ) printf("no\n");
      else printf("yes\n");
    } if ( com[0] == 'i' ){
      scanf("%d", &x);
      insert(x);
    } else if ( com[0] == 'p' ){
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
  }

  return 0;
}
// Binary Search Tree II
#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *right;
  struct node *left;
  struct node *parent;
  int key;
};
typedef struct node * Node;

Node root, nil;

// 木から key の値を持つノードを探す //
Node treeSearch(Node x, int k){
  if(x == nil || k == x->key) return x;
  if(k < x->key) treeSearch(x->left, k);
  else treeSearch(x->right, k);
}

// ノード x から最小の key を探す //
Node treeMinimum(Node x){
  while(x->left != nil)x = x->left;
  return x;
}

// ノード x から最大の key を探す //
Node treeMaximum(Node x){
  while(x->right != nil)x = x->right;
  return x;
}

//  二分探索木へkを挿入 //
void insert(int k){
  Node y = nil; // x の親
  Node x = root; // T の根
  Node z;
  
  z->parent = y;
  z = (Node)malloc(sizeof(struct node));
  z->key = k;
  z->left = nil;
  z->right = nil;

  while(x != nil){
    y = x;   // 親を設定
    if(z->key < x->key)x = x->left; // 左の子へ移動
    else x = x->right;            // 右の子へ移動
  }

  if(y == nil)root = z; // T が空の場合
  else if(z->key < y->key)y->left = z; // z を y の左の子にする
  else y->right = z; // z を y の右の子にする
}

// 再帰を使って中間順巡回(Inorder)で表示
void printInorder(Node u){
  if(u == nil)return;
  printInorder(u->left);
  printf(" %d", u->key);
  printInorder(u->right);
}

// 再帰を使って先行順巡回(Preorder)で表示
void printPreorder(Node u){
  if(u == nil)return;
  printf(" %d", u->key);
  printPreorder(u->left);
  printPreorder(u->right);
}

int main(){
  int n, i, x;
  char com[20];
  Node t;
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ){
    scanf("%s", com);
    if ( com[0] == 'f' ){
      scanf("%d", &x);
      Node t = treeSearch(root, x);
      if ( t != nil ) printf("yes\n");
      else printf("no\n");
    } else if ( com[0] == 'i' ){
      scanf("%d", &x);
      insert(x);
    } else if ( com[0] == 'p' ){
      printInorder(root);
      printf("\n");
      printPreorder(root);
      printf("\n");
    }
  }

  return 0;
}

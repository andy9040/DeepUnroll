#include <stdio.h>
#include <stdlib.h>

struct node{
  int key;
  struct node *left;
  struct node *right;
};
typedef struct node *NodePointer;

void in(void);
NodePointer makenode(int);
void insert(int, NodePointer);
void preorder(NodePointer);
void inorder(NodePointer);
int find(int, NodePointer);

NodePointer head, tail;

int main(){
  char str[7];
  int n, k;
  in();
  scanf("%d", &n);
  while(n--){
    scanf("%s", str);
    if(str[0] == 'i'){
      scanf("%d", &k);
      insert(k, head);
    }
    else if(str[0] == 'p'){
      inorder(head->right);
      printf("\n");
      preorder(head->right);
      printf("\n");
    }
    else{
      scanf("%d", &k);
      if(find(k, head->right)) printf("yes\n");
      else printf("no\n");
    }
  }
  return 0;
}

void in(void){
  head = makenode(-1);
  tail = makenode(-1);
  head->right = tail;
  head->left = tail;
}

NodePointer makenode(int k){
  NodePointer x;
  x = malloc(sizeof(struct node));
  x->key = k;
  x->left = x->right = tail;
  return x;
}

void insert(int k, NodePointer p){
  if(k < p->key){
    if(p->left ==tail) p->left = makenode(k);
    else insert(k, p->left);
  }
  else{
    if(p->right == tail) p->right = makenode(k);
    else insert(k, p->right);
  }
}

void preorder(NodePointer node){
  if(node != tail){
    printf(" %d", node->key);
    preorder(node->left);
    preorder(node->right);
  }
}

void inorder(NodePointer node){
  if(node != tail){
    inorder(node->left);
    printf(" %d", node->key);
    inorder(node->right);
  }
}

int find(int k, NodePointer node){
  if(node == tail){
    return 0;
  }
  if(node->key == k) return 1;
  else if(node->key < k) return find(k, node->right);
  else return find(k, node->left);
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
  int key;
  struct Node *l;
  struct Node *r;
  struct Node *p;
};

typedef struct Node *node;

void insert(node,node);
void inorder(node);
void preorder(node);
void find(node,int);

int main(){

  node root,T[500000];
  int i,m,num;
  char str[7];

  scanf("%d",&m);
  root=(node)malloc(sizeof(struct Node));

  for(i=0;i<m;i++){
    T[i]=(node)malloc(sizeof(struct Node));
    scanf("%s",str);
    if(strcmp(str,"insert")==0){
      scanf("%d",&T[i]->key);
      T[i]->r=NULL;
      T[i]->l=NULL;
      insert(root,T[i]);

    }else if(strcmp(str,"print")==0){
      inorder(T[0]);
      printf("\n");
      preorder(T[0]);
      printf("\n");

    }else if(strcmp(str,"find")==0){
      scanf("%d",&num);
      find(T[0],num);

    }
  }


  return 0;
}

void insert(node root,node z){

 node x,y;

  y = NULL; // x ??????
  x = root;
  while( x != NULL){
    y = x; // ???????¨????
    if (z->key < x->key){
      x = x->l; // ?????????????§????
    } else{ 
      x = x->r; // ?????????????§????
    }
  }
  z->p = y;

  if( y == NULL){ // T ???????????´???
    root = z;
  }else if( z->key < y->key){
    y->l = z; // z ??? y ?????????????????????
  }else{ 
    y->r = z; // z ??? y ?????????????????????

  }
}
void inorder(node T){
  if(T==NULL)return;
  inorder(T->l);
  printf(" %d",T->key);
  inorder(T->r);
}
void preorder(node T){
  if(T==NULL)return;
  printf(" %d",T->key);
  preorder(T->l);
  preorder(T->r);
}
void find(node T,int num){
  if(T==NULL){
    printf("no\n");
    return;
  }else if(T->key==num){
    printf("yes\n");
    return;
  }
  if(T->key<num)find(T->r,num);
  else find(T->l,num);

}
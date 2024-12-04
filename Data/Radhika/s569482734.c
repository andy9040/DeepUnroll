#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2000001
//???????????£????????????
struct Node{
  int key;
  struct Node *next,*prev;
};

struct Node *nil;

struct Node* listSearch(int key){
  struct Node *cur=nil->next;
  while(cur!=nil&&cur->key!=key){
    cur=cur->next;
  }
  return cur;
}

void init(){
  nil=(struct Node *)malloc(sizeof(struct Node));
  nil->next=nil;
  nil->prev=nil;
}

void output(){
  struct Node *cur=nil->next;
  int i=0;
  while(1){
    if(cur==nil) break;
    if(i++>0) printf(" ");
    printf("%d",cur->key);
    cur=cur->next;
    }
  printf("\n");
}

void delNode(struct Node *t){
  if(t==nil) return;
  t->prev->next=t->next;
  t->next->prev=t->prev;
  free(t);
}

void delF(){
  delNode(nil->next);
}

void delL(){
  delNode(nil->prev);
}

void delKey(int key){
  delNode(listSearch(key));
}

void insert(int key){
  struct Node *a=(struct Node *)malloc(sizeof(struct Node));
  a->key=key;
  a->next=nil->next;
  nil->next->prev=a;
  nil->next=a;
  a->prev=nil;
}

int main(){
  int n,key,i,j,npoi=0,ndel=0,size=0;
  char c[12];

  scanf("%d",&n);

  init();
  for(i=0;i<n;i++){
    scanf("%s %d",c,&key);

    if(c[0]=='i'){
      insert(key);
      npoi++;
      size++;
    }
    else if(c[0]=='d'){
if(strlen(c)>6){
      if(c[6]=='F') delF();
      else if(c[6]=='L') delL();
    } else {
        delKey(key);
        ndel++;
      }
        size--;
      }
    }
    output();
  return 0;
}
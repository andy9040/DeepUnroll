#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{/*ノード作成*/
  unsigned int key;
  struct node *next;
  struct node *prev;
};

typedef struct node * NodePointer;

NodePointer nil;

NodePointer listSearch(int key){
  NodePointer p;
  int i;
  p=nil->next;

  while((p != nil) && (p->key!=key)){
    p=p->next;
  }
    return p;

}

void init(){
  nil = malloc(sizeof(struct node));
  nil->next = nil;
  nil->prev = nil;
}

void printList(){
  NodePointer cur = nil->next;
  int isf = 1;
  while(1){
    if ( cur == nil ) break;
    if ( isf == 0)  printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
    isf = 0;
  }
  printf("\n");
}

void deleteNode(NodePointer t){
  /*node の消去*/
  t->prev->next=t->next;
  t->next->prev=t->prev;
}

void deleteFirst(){
  /*最初のノードの削除*/
  NodePointer t = nil->next;
  if ( t == nil )return;
  deleteNode(t);
}

void deleteLast(){
  /*最後のノード削除*/
  NodePointer t=nil->prev;
  if(t==nil)return;
  deleteNode(t);

}

void delete(int key){

  NodePointer tea;
  if((tea=listSearch(key))!= NULL){
    if(tea == nil) return;
    deleteNode(tea);
    }
}


void insert(int key){
  /*挿入*/
  NodePointer new;
  new = malloc(sizeof(struct node));
  new->key = key;
  new->next=nil->next;
  
  nil->next->prev=new;

  nil->next=new;

  new->prev=nil;
}



int main(void){
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;
  scanf("%d", &n);
  init();
  for ( i = 0; i < n; i++ ){
    scanf("%s%d", com, &key);
    if ( com[0] == 'i' ) {insert(key); np++; size++;}
    else if ( com[0] == 'd' ) {
      if (strlen(com) > 6){
        if ( com[6] == 'F' ) {
deleteFirst();
}
        else if ( com[6] == 'L' ) deleteLast();
      } else {
        delete(key); nd++; 
      }
      size--;
    }
  }

  printList();
  return 0;
}
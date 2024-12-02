#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
  unsigned int key;
  struct node *next;
  struct node *prev;
};

typedef struct node * NodePointer;

NodePointer nil;

NodePointer listSearch(int key){
  /* your code */
  NodePointer p = nil->next;
  while(p != nil){
	  if(p->key == key){
		  break;
	  }
	  p = p->next;
  }
  return(p);
}

void init(){
  nil = (NodePointer)malloc(sizeof(struct node));
  nil->next = nil;
  nil->prev = nil;
}

void printList(){
  NodePointer cur = nil->next;
  int isf = 1;
  while(1){
    if ( cur == nil ){
		break;
	}
    if (isf == 0){
		printf(" ");
	}
    printf("%d", cur->key);
    cur = cur->next;
    isf = 0;
  }
  printf("\n");
}

void deleteNode(NodePointer t){
  /* your code */
	NodePointer w;
	if((nil->next == t) && (t->next == nil)){
		nil->next = nil;
		nil->prev = nil;
	}else{
		nil->next = t->next;
		t->next->prev = nil;
	}
	free(t);
}

void deleteFirst(){
  NodePointer t = nil->next;
  if ( t == nil ) return;
  deleteNode(t);
}

void deleteLast(){
  /* your code */
	NodePointer w;
	if(nil == nil->next){
		return;
	}
	w = nil->prev;
	nil->prev = w->prev;
	w->prev->next = nil;
	w->next = nil;
	free(w);
}

void _delete(int key){
  /* your code */
  NodePointer t = listSearch(key);
  if((nil->next == t) && (t->next == nil)){
	  deleteFirst();
  }else if((nil->prev == t) && (t->next == nil)){
	  deleteLast();
  }else{
	  t->prev->next = t->next;
	  t->next->prev = t->prev;
	  free(t);
  }

}


void insert(int key){
  NodePointer x;
  x = (NodePointer)malloc(sizeof(struct node));
  x->key = key;
  /* 

   your code 


  */
  if(nil == nil->next){
      x->next = nil;
      x->prev = nil;
      nil->next = x;
      nil->prev = x;
  }else{
	  x->next = nil->next;
	  x->prev = nil;
	  nil->next->prev = x;
      nil->next = x;
  }
  return;
}

int main(){
  int key, n, i;
  int size = 0;
  char com[20],s[256];
  int np = 0, nd = 0;
  scanf("%d", &n);
  rewind(stdin);
  init();
  for ( i = 0; i < n; i++ ){
    fgets(s,256-1,stdin);
	sscanf(s, "%s %d", com, &key);
    if ( com[0] == 'i' ){
		insert(key);
		np++;
		size++;
	}
    else if ( com[0] == 'd' ) {
      if (strlen(com) > 6){
	    if ( com[6] == 'F' ) deleteFirst();
	    else if ( com[6] == 'L' ) deleteLast();
      } else {
	    _delete(key); nd++; 
      }
        size--;
    }
  }

  printList();

  return 0;
}
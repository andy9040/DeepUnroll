#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
  int key;
  struct node *next,*prev;
};
  struct node *nil;

void set(void){
  nil=(struct node *)malloc(sizeof(struct node));
  nil->next =nil;
  nil->prev =nil;
}

void insert(int key){
  struct node *x;
  x=(struct node *)malloc(sizeof(struct node));
  x->key=key;
  x->next=nil->next;
  nil->next->prev=x;
  x->prev=nil;
  nil->next=x;
    }

struct node*  finditem(int key){
  struct node *n=nil->next;

  while(n!=nil&&n->key!=key){
    n=n->next;
  }
  return n;
  }

void deletenode(struct node *t){
    if(t==nil) return;
    t->prev->next=t->next;
  t->next->prev=t->prev;
  free(t);
    }

void print(){
  struct node *n;
  int i=0;

  for(n=nil->next;n!=nil;n=n->next){
    if(i++!=0) printf(" ");
    printf("%d",n->key);
  }
  printf("\n");
}

int main(){
  int n,key,i;
  char c[20];

  scanf("%d",&n);
  set();
  for(i=0;i<n;i++){
    scanf("%s",c);
    if(c[0]=='i'){
      scanf("%d",&key);
      insert(key);
    }
    else if(c[0]=='d'&&strlen(c)>6){
      if(c[6]=='F') deletenode(nil->next);
      else if(c[6]=='L')deletenode(nil->prev);
    }
    else{
      scanf("%d",&key);
      deletenode(finditem(key));
    }
  }

  print();

  return;
}

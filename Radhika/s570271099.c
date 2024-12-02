#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{

  int key;
  struct node *next;
  struct node *prev;
};
typedef struct node * NodePointer;

void insert(int);
void delete(NodePointer);
void deleteFirst(void);
void deleteLast(void);
NodePointer findkey(int);
 
NodePointer nil;

int main(){

  int i,in,n;
  char s[20];
  NodePointer x;

  nil=malloc(sizeof(struct node));
  nil->next=nil;
  nil->prev=nil;

  scanf("%d",&n);

  i=0;
  while(i!=n){

    memset(s,'\0',20);
    scanf("%s",s);
    i++;
      if(strcmp(s,"insert")==0){
	scanf("%d",&in);
	insert(in);
      }
      else if(strcmp(s,"delete")==0){
	scanf("%d",&in);
	x=findkey(in);
	if(x==nil) continue;
	else delete(x);
      }
      else if(strcmp(s,"deleteFirst")==0) {
	deleteFirst();
      }
      else if(strcmp(s,"deleteLast")==0){
	  deleteLast();
	}
  }
	
	
  for(x=nil->next;x->next!=nil;x=x->next) printf("%d ",x->key);
  
 printf("%d\n",x->key);


  return 0;
}

void insert(int x){

  NodePointer new;

  new=malloc(sizeof(struct node));

  new->key=x;
  new->next=nil->next;
  nil->next->prev=new;
  nil->next=new;
  new->prev=nil;

}

void delete(NodePointer delnode){

  delnode->prev->next=delnode->next;
  delnode->next->prev=delnode->prev;
  free(delnode);

}

NodePointer findkey(int x){

  NodePointer tmp;

  tmp=malloc(sizeof(struct node));

  tmp=nil->next;
  while(tmp!=nil && tmp->key!=x){
    tmp=tmp->next;
  }

  return tmp;
}

void deleteFirst(void){
  NodePointer delnode;
  delnode=nil->next;

  if(delnode->next==nil){
    nil->next=nil;
    nil->prev=nil;
    free(delnode);
  }
  else{
    nil->next=delnode->next;
    delnode->next->prev=delnode->prev;
    free(delnode);
  }
  

}

void deleteLast(void){

  NodePointer delnode;

  delnode=nil->prev;
  delnode->prev->next=nil;
  nil->prev=delnode->prev;

  free(delnode);
}
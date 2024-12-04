#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
  struct node *prev;
  struct node *next;
  long key;
};
typedef struct node * NP;
NP MN(long);
void IN(NP);
void DN(NP);
void FI(long);
NP dummy;

int main(){
  long int val,i,n;
  char op[12];
  NP roop;

  scanf("%ld",&n);
  dummy = MN(0);

  for(i=0;i<n;i++){
    scanf("%s",op);
    
    if(strcmp(op,"insert") == 0){
      scanf("%ld",&val);
      IN(MN(val));
    }
    else if(strcmp(op,"delete") == 0){
      scanf("%ld",&val);
      FI(val);
    }
    else if(strcmp(op,"deleteFirst") == 0){
      if(dummy->next != dummy){
      DN(dummy->next);
      }
    }
    else if(strcmp(op,"deleteLast") == 0){
      if(dummy->prev != dummy){ 
     DN(dummy->prev);
      }
    }
  }

  for(roop=dummy->next;roop!=dummy;roop =roop->next){
    printf("%ld",roop->key);
    if(roop->next != dummy)printf(" ");
  }  
  printf("\n");

  return 0;
}


void FI(long value){ // find item
  NP n;
  dummy->key = value;
  for(n = dummy->next;;n=n->next){
    if(n->key == value)break;
  }
  if(n != dummy)DN(n);
    
}


void DN(NP th){ //delete node
  th->prev->next = th->next;
  th->next->prev = th->prev;
  th->prev = th->next = th;
  free(th);
  //delete th;
}


void IN(NP newn){ //insert node
  newn->next = dummy->next;
  newn->next->prev = newn;
  dummy->next = newn;
  newn->prev = dummy;
}

NP MN(long key){ //make node
  NP no = (NP)malloc(sizeof(struct node));
  //n = new struct node();
  no->prev = no;
  no->next = no;
  no->key = key;
  return no;
} 
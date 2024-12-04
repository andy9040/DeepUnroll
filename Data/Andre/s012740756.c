#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
  int key;
  struct node *next, *prev;
} node;
node* Insert(int);
node* Finditem(int);
node* Make_1node(int);
void Delete(int);
void DeleteF(void);
void DeleteL(void);
void Print(void);
node *head;
int main(){
  int i, n, key;
  char func[11];
  scanf("%d",&n);
  head = (node*)malloc(sizeof(node));
  head->next = head->prev = NULL;
  for(i=0; i<n; i++){
    scanf("%s",func);
    if(strcmp(func,"insert") == 0){
      scanf("%d",&key);
      Insert(key);
    }
    else if(strcmp(func,"delete") == 0){
      scanf("%d",&key);
      Delete(key);
    }
    else if(strcmp(func,"deleteFirst") == 0) DeleteF();
    else if(strcmp(func,"deleteLast") == 0) DeleteL();
  }
  Print();
  return 0;
}
node* Insert(int key){
  node *n;
  n = Make_1node(key);
  n->next = head->next;
  n->prev = head;
  head->next = n;
  if(n->next != NULL) n->next->prev = n;
  return n;
}
node* Finditem(int key){
  node *n;
  for (n = head; n->next != NULL; n = n->next) {
    if (n->next->key == key) return n;
  }
  return NULL;
}
node* Make_1node(int key){
  node *n;
  n = (node*)malloc(sizeof(node));
  n->key = key;
  return n;
}
void Delete(int key){
  node *n, *del;
  n=Finditem(key);
  if(n == NULL) return;
  del = n->next;
  if(del->next == NULL){
    n->next = NULL;
    free(del);
    return;
  }
  n->next = del->next;
  n->next->prev = n;
  free(del);
}
void Print(){
  node *n;
  for(n=head->next; n!=NULL; n=n->next){
    printf("%d",n->key);
    printf(n->next != NULL ? " " : "\n");
  }
}
void DeleteF(void){
  node *del;
  del = head->next;
  if(del->next != NULL){
    head->next = head->next->next;
    head->next->prev = head;
  }
  else head->next = NULL;
  free(del);
}
void DeleteL(void){
  node *m, *del;
  for(m=head; m->next->next!=NULL; m=m->next);
  del = m->next;
  m->next = NULL;
  free(del);
}
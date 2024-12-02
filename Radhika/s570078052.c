#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct list{
  struct list *next;
  struct list *prev;
  int n;
};
struct list *ls;
void init();
void insert(int);
void delete(int);
void print();
void deleteFirst();
void deleteLast();
int main(){
  int n,i,com;
  char command[13];
  init();
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",command);
    if(!strcmp(command,"deleteFirst"))deleteFirst();
    else if(!strcmp(command,"deleteLast"))deleteLast();
    else{
      scanf("%d",&com);
        if(!strcmp(command,"insert")) insert(com);
        else if(!strcmp(command,"delete"))  delete(com);
    }
  }
  print();

  return 0;
}
void init(){
  ls=(struct list *)malloc(sizeof(struct list));
  ls->next=ls;
  ls->prev=ls;
}
void insert(int com){
  struct list *array;
  array=(struct list *)malloc(sizeof(struct list));
  array->n=com;
  ls->next->prev=array;
  array->next=ls->next;
  array->prev=ls;
  ls->next=array;
}
void print(){
  struct list *a=ls->next;
  while(1){
    printf("%d",a->n);
    if(a->next==ls){
        printf("\n");
        return;
    }
    printf(" ");
    a=a->next;
    free(a->prev);
  }
}
void delete(int x){
  struct list *a=ls->next;
  while(1){
    if(a==ls)return;
    if(a->n==x){
      a->prev->next=a->next;
      a->next->prev=a->prev;
      free(a);
      return;
    }
    a=a->next;
  }
}

void deleteFirst(){
  ls->next=ls->next->next;
  ls->next->prev=ls;
}
void deleteLast(){
  ls->prev->prev=ls;
}

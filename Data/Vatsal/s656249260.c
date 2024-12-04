#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 2000000

struct node {
   int key;
	
   struct node *next;
   struct node *prev;
};

struct node *head = NULL;

struct node *last = NULL;

struct node *current = NULL;

int isEmpty(){
   return head == NULL;
}

int length(){
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next){
      length++;
   }
	
   return length;
}


void displayForward(void){

  
  struct node *ptr = head;
		
  while(ptr != NULL){
    if(ptr+1!=NULL && ptr != head)
      printf(" ");
    printf("%d",ptr->key);
  
    ptr = ptr->next;
  }
	
}



void insertFirst(int key){

 
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
	
   if(isEmpty()){

      last = link;
   }else {

      head->prev = link;
   }

   link->next = head;

   head = link;
}


struct node* deleteFirst(void){


   struct node *tempLink = head;
	
  
   if(head->next == NULL){
      last = NULL;
   }else {
      head->next->prev = NULL;
   }
	
   head = head->next;
 
   return tempLink;
}



struct node* deleteLast(void){
 
   struct node *tempLink = last;
	

   if(head->next == NULL){
      head = NULL;
   }else {
      last->prev->next = NULL;
   }
	
   last = last->prev;
   return tempLink;
}

struct node* delete(int key){
  
   struct node* current = head;
   struct node* previous = NULL;
   if(head == NULL){
      return NULL;
   }
   while(current->key != key){
      if(current->next == NULL){
         return NULL;
      }else {
         previous = current;
         current = current->next;             
      }
   }
   if(current == head) {
      head = head->next;
   }else {
      current->prev->next = current->next;
   }    

   if(current == last){
      last = current->prev;
   }else {
      current->next->prev = current->prev;
   }	
   return current;
}

	


int main() {

  int i,n,*key;
  static char command[N][12];
  char word[4][12]={"insert","delete","deleteFirst","deleteLast"};
  scanf("%d",&n);
  key=malloc(sizeof(int)*n+1);
  for(i=0;i<n;i++){
    scanf("%s",command[i]);
      if(strcmp(command[i],word[0])==0) 
	scanf("%d",&key[i]);
      
         if(strcmp(command[i],word[1])==0) 
	   scanf("%d",&key[i]);
  }

  for(i=0;i<n;i++){
    if(strcmp(command[i],word[0])==0)
   insertFirst(key[i]);
    if(strcmp(command[i],word[1])==0)
      delete(key[i]);
    if(strcmp(command[i],word[2])==0)
      deleteFirst();
    if(strcmp(command[i],word[3])==0)
    deleteLast();
  }

  displayForward();
  printf("\n");
  
   return 0;
}
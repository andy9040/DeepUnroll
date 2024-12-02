#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD 16

typedef struct node_t{
  long key;
  struct node_t *prev;
  struct node_t *next;
} node; 

node *head, *tail;

int insert(node *add){
  if (!add)
    return -1;
  else if (!head)
    // when add a first node
    head = tail = add;
  else {
    head->prev = add;
    add->next = head;
    head = add;
  }
  return 0;
}

node *search(long searchKey){
  node *tmp = head;
  while (tmp) {
    if (tmp->key == searchKey)
      return tmp;
    tmp = tmp->next;
  }
  return NULL;
}

int delete(long deleteKey){
  node *del;
  if (!(del = search(deleteKey)))
    return -1;
  else {
    if (del == head) {
      head = head->next;
      if (head)
    	head->prev = NULL;
      else
	// list is empty
    	head = tail = NULL;
    }
    else if (del == tail) {
      tail = tail->prev;
      tail->next = NULL;
    }
    else {
      // delete node is middle in the list
      del->prev->next = del->next;
      del->next->prev = del->prev;
    }
    free(del);
    return 0;
  }
  return 1;
}

int deleteFirst(){
  if (head == tail && tail == NULL)
    return -1;
  else {
    head = head->next;
    if (head)
      head->prev = NULL;
    else
      // list is empty
      head = tail = NULL;
    return 0;
  }
}

int deleteLast(){
  if (head == tail && tail == NULL)
    return -1;
  else {
    tail = tail->prev;
    if (tail)
      tail->next = NULL;
    else
      // list is empty
      head = tail = NULL;
    return 0;
  }
}

int main(void){
  long n, i, key;
  char command[CMD] = {0};
  char ins[] = "insert", del[] = "delete";
  char delF[] = "deleteFirst", delL[] = "deleteLast";
  node *tmp;
  scanf("%ld", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %ld", command, &key);
    if (!(strcmp(command, ins))) {
      tmp = (node *)malloc(sizeof(node));
      tmp->key = key;
      tmp->next = NULL;
      tmp->prev = NULL;
      insert(tmp);
    }
    else if(!(strcmp(command, del)))
      delete(key);
    else if(!(strcmp(command, delF)))
      deleteFirst();
    else if(!(strcmp(command, delL)))
      deleteLast();
    else
      puts("Not available command!");
  }
  
  // output
  tmp = head;
  for (i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%ld", tmp->key);
    if (tmp == tail)
      break;
    tmp = tmp->next;
  }
  puts("");
  return 0;
}
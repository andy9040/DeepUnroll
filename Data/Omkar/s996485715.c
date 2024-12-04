#include <stdio.h>
#include <string.h>

struct List {
  int num;
  struct List *before;
  struct List *next;
};

struct List l;

void insert(struct List *a) {
  a->before = &l;
  a->next = l.next;
  l.next = a;
  a->next->before = a;
}

void delete(int b) {
  struct List *c;
  c = l.next;
  while(c->num != -1) {
    if (c->num == b) {
      c->next->before = c->before;
      c->before->next = c->next;
      break;
    }  
    c = c->next;
  } 
  }

void delete_First() {
  l.next = l.next->next;
  l.next->before = &l;
}

void delete_Last() {
  l.before = l.before->before;
  l.before->next = &l;
}

int main(void) {
  int n;
  char command[12];
  int key;
  int adress = 1;
  struct List *box;
  l.num = -1;
  l.before = &l;
  l.next = &l;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", command);
    if (strcmp(command, "deleteFirst") == 0)
      delete_First();
    else if (strcmp(command, "deleteLast") == 0)
      delete_Last();
    else {
      scanf("%d", &key);
      if (strcmp(command, "insert") == 0) {
	(&l + adress)->num = key;
	insert(&l + adress);
	adress++;
      }
      else if (strcmp(command, "delete") == 0) {
	delete(key);
      }
      }
    }
 
  
  box = l.next;
  while(box->num != -1) {
    printf("%d", box->num);
    box = box->next;
    if (box->num != -1)
      printf(" ");
  }
  printf("\n");
  
  return 0;
}


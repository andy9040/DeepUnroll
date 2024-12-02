#include <stdio.h>
#include <stdlib.h>

#define M 256

typedef struct Node {
  int x;
  struct Node *prev;
  struct Node *next;
} Node;

Node *head, *tail;

void dump();
void insert(int);
void delete(int);
void deleteFirst();
void deleteLast();



int main(int argc, char **argv) {

  int n;
  scanf("%d\n", &n);

  int i;
  int x;
  char buf[M];
  char tmp[M];
  for (i = 0; i < n; ++i) {
    fgets(buf, 256, stdin);

    if (buf[0] == 'i' || buf[6] == ' ') {
      sscanf(buf, "%s %d", tmp, &x);

      if (buf[0] == 'i') insert(x);
      else               delete(x);
    } else if (buf[6] == 'F') {
      deleteFirst();
    } else if (buf[6] == 'L') {
      deleteLast();
    }
  }

  dump();

  return 0;
}

void dump() {
  int l = 0;
  Node *p = head;
  while (p != NULL) {
    if (l == 0)  printf("%d",  p->x);
    else printf(" %d", p->x);
    ++l;
    p = p->next;
  }
  printf("\n");
}

void insert(int x) {
  Node *nod = malloc(sizeof(Node));
  
  nod->x = x;
  nod->prev = NULL;
  nod->next = NULL;

  if (head == NULL) {
    head = nod;
    tail = nod;
  }
  else {
    nod->next = head;
    head->prev = nod;
    head = nod;
  }
}

void delete(int x) {
  Node *p = head;
  int flg = 0;

  while (flg == 0 && p != NULL) {
    if (p->x == x) {
      Node *c = p;
      if (c->prev != NULL) {
        p->prev->next = c->next;
      }
      else {
        head = c->next;
      }

      if (c->next != NULL) {
        p->next->prev = c->prev;
      }
      else {
        tail = c->prev;
      }
      flg = 1;
    }
    else {
      p = p->next;
    }
  }
}

void deleteFirst() {
  if (head == tail) {
    head = NULL;
    tail = NULL;
  }
  else if (head != NULL) {
    if (head->next != NULL) head->next->prev = NULL;
    head = head->next;
  }
}

void deleteLast() {
  if (head == tail) {
    head = NULL;
    tail = NULL;
  }
  else if (tail != NULL) {
    if (tail->prev != NULL) {
      tail->prev->next = NULL;
    }
    tail = tail->prev;
  }
}


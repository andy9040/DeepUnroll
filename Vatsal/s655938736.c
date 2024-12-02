#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//---List---
struct List{
  int x;
  struct List *next;
  struct List *back;
};
typedef struct List * ListPointer;
//struct List head,end;
ListPointer head;
ListPointer end;
ListPointer find(int);
void insert(int);
void delete(int);
void deleteFirst(int);
void deleteLast(int);

int trance_com(char *);


//---main---
int main()
{
  //(*commnd[])(int) is a method pointer.
  void (*commnd[])(int)={insert, delete, deleteFirst, deleteLast};
  int n;
  char com[20];
  int x;
  int i, j, k;
  ListPointer P;

  //initialization
  head=malloc(sizeof(struct List));
  end=malloc(sizeof(struct List));
  head->next=end;
  head->back=NULL;
  end->next=NULL;
  end->back=head;


  //start
  scanf("%d", &n);
  for(i=0; i<n; i++)
    {
      scanf("%s", com);
      j=trance_com(com);
      switch(j)
	{
	  //insert or delete
	case 0:
	case 1:
	  scanf("%d", &x);
	  (*commnd[j])(x);
	  break;

	  //deleteFirast or deleteLast
	case 2:
	case 3:
	  (*commnd[j])(x);
	  break;

	case -1:
	  printf("not command");
	  break;
	  }
    }


  //print
  for(P=head->next; P->next!=NULL; P=P->next)
    {
      if(P->next->next!=NULL)printf("%d ", P->x);
      else if(P->next->next==NULL)
	{
	  printf("%d\n", P->x);
	  break;
	}
    }
  //printf("\n");

  return 0;
}


//---method---
int trance_com(char *com)
{
  if(strcmp(com, "insert")==0)return 0;
  else if(strcmp(com, "delete")==0)return 1;
  else if(strcmp(com, "deleteFirst")==0)return 2;
  else if(strcmp(com, "deleteLast")==0)return 3;
  //not command
  else return -1;
}


ListPointer find(int x)
{
  ListPointer n;
 for(n=head->next; n->next!=NULL; n=n->next)
    {
      if(n->x==x)return n;
    }
 return NULL;
}

void insert(int x)
{
  ListPointer n;
  n=malloc(sizeof(struct List));
  if(n==NULL)
    {
      printf("Error. It could not make node.\n");
      exit(1);
    }
  n->x=x;
  n->back=head;
  n->next=head->next;
  head->next->back=n;
  head->next=n;
}

void delete(int x)
{
  ListPointer n;
  n=find(x);
  if(n==NULL)printf("Cannot find number!\n");
  else
    {
      n->back->next=n->next;
      n->next->back=n->back;
      free(n);
    }
}

void deleteFirst(int x)
{
  ListPointer n;
  n=head->next;
  head->next=n->next;
  n->next->back=head;
  free(n);
}

void deleteLast(int x)
{
  ListPointer n;
  n=end->back;
  n->back->next=end;
  end->back=n->back;
  free(n);
}
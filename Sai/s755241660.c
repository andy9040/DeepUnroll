#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
  int number;
  struct node *next;
};
typedef struct node * nodepointer;
nodepointer search(int k);
nodepointer insert(int x);
nodepointer delete(int x);
nodepointer makenode(int x,nodepointer node);
nodepointer deleteF();
nodepointer deleteL();
void list();
nodepointer head;
int main()
{
  int n,m,k=0,i,sum=0,u,x=0,num,ema;
  char com[100];
  head=makenode(0,NULL);
  scanf("%d",&n);
  for(i=0;i<n;i++){
    ema=scanf("%s",com);
    if(ema==EOF)break;
    if(strcmp("deleteFirst",com)==0){
      deleteF();
      continue;
    }else if(strcmp("deleteLast",com)==0){
      deleteL();
      continue;
    }
    scanf("%d",&num);
    if(strcmp("insert",com)==0){
      //if(insert(num)==NULL)printf("already exist\n");
    }else if(strcmp("delete",com)==0){
      //if(delete(num)==NULL)printf("originally nothing\n");
    }
  }
  list();
  return 0;
}
nodepointer search(int k){
  nodepointer n;
  for(n=head;n->next!=NULL;n=n->next){
    if(n->next->number==k)return n;
  }
    return NULL;
}
nodepointer insert(int x){
  nodepointer new;
  //if(search(x)==NULL){
    new=makenode(x,head->next);
    head->next=new;
    return new;
    //}
    //else return NULL;
}
nodepointer delete(int x){
  nodepointer n,del;
  if((n=search(x))!=NULL){
    del=n->next;
    n->next=del->next;
    free(del);
    return n;
  }
  else return NULL;
}
nodepointer makenode(int x,nodepointer p){
  nodepointer n;
  if((n=(nodepointer)malloc(sizeof(struct node)))==NULL){
    printf("error\n");
    exit(8);
  }
  n->number=x;
  n->next=p;
  return n;
}
nodepointer deleteL(){
  nodepointer n,del;
  for(n=head; ;n=n->next){
    if(n->next->next==NULL){
      del=n->next;
      n->next=NULL;
      free(del);
      return n;
    }
  }
}
nodepointer deleteF(){
  nodepointer n,del;
  n=head;
  del=n->next;
  n->next=del->next;
  free(del);
  return n;
}
void list(){
  nodepointer n;
for(n=head->next;n!=NULL;n=n->next){
  printf("%d",n->number);
  if(n->next!=NULL)printf(" ");
 }
 printf("\n");
}


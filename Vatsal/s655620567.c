#include<stdio.h>
#include<stdlib.h>

 struct Node{
           struct Node *prev;
           struct Node *next;
           int key;
           };

 typedef struct Node *Nodepointer;

 Nodepointer nil;

 void init(){
          nil=malloc(sizeof(struct Node));

          nil->prev=nil;
          nil->next=nil;
          }

 void printlist(){
          Nodepointer ser=nil->next;
          int isf=1;

          while(1){
                 if(ser==nil)break;
                 if(isf==0)printf(" ");
                 printf("%d",ser->key);
                 ser=ser->next;
                 isf=0;
                 }
          printf("\n");
          }


 void insert(int key){
          Nodepointer x=malloc(sizeof(struct Node));
          x->key=key;

          nil->next->prev=x;
          x->next=nil->next;
          nil->next=x;
          x->prev=nil;
          }

 Nodepointer serch(int key){
          Nodepointer ser=nil->next;
          while(ser != nil && ser->key != key){
                       ser=ser->next;
                       }
          return ser;
          }
          

 void delete(Nodepointer x){
          if(x==nil)return;
          x->prev->next=x->next;
          x->next->prev=x->prev;
          free(x);
          }

 void deletefirst(){
          NodePointer t = nil->next;
  if ( t == nil ) return;
  deleteNode(t);
}

 int deletelast(){
          NodePointer t = nil->prev;
  if (t == nil) return;
  deleteNode(t);
}
 int deletekey(int key){
          delete(serch(key));
          }

 int main(){
       int i,n,k;
       char com[20];
       init();
       scanf("%d",&n);
       for(i=0;i<n;i++){
                 scanf("%s %d",&com,&k);
                 
                 if(com[0]=='i'){insert(k);}
                 else if(com[0]=='d'){
                               if(strlen(com)>6){  
                                     if(com[6]=='F'){deletefirst();}
                                     else if(com[6]=='L'){deletelast();}
                                     }
                               }else{delete(k);}
                }
       printlist();
       return 0;
       }






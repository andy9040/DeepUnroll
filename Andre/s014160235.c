#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct LIST {
  struct LIST *prev;	// 前
  struct LIST *next;	// 後ろ
  double key;
} LIST;

void insert(double key);	// 追加する
void delete(LIST *p);	// 削除する
void show_list(LIST *p);
void free_list(LIST *p);
LIST *search(double key);

LIST head;	  

int main() {
  int n,i;
  double key;
  char c[13];
  LIST *p;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",c);

    if(strcmp("insert",c)==0){
      scanf("%d",&key);
      insert(key);
    }

    if(strcmp("delete",c)==0){
      scanf("%d",&key);
      if(search(key)!=NULL) delete(search(key));
    }

    if(strcmp("deleteFirst",c)==0){
      delete(head.next);
    }

    if(strcmp("deleteLast",c)==0){
      p=head.next;
      while (p->next != NULL) {     /* 次ポインタがNULLまで処理 */
	p=p->next;
      }
      delete(p);
    }
  }
  show_list(head.next);

  free_list(head.next);	// リストの解放
  return 0;			// 正常終了
}


void insert(double key) {
  LIST *p1;		// 追加
  LIST *p2;		// 挿入前: p -> p2  ⇒　挿入後; p -> p1 -> p2
  LIST *p = &head;	
  /* 記憶領域の確保 */
  if ((p1 = (LIST *) malloc(sizeof(LIST))) == NULL) {
    printf("malloc error\n");
    exit(0);
  }

  p1->key = key;

  // 挿入前: p -> p2  ⇒　挿入後; p -> p1 -> p2
  p2 = p->next;
  p->next = p1;
  p1->next = p2;		
  if (p2 != NULL) p2->prev = p1;
  p1->prev = p;

}

// 削除する
void delete(LIST *p) {	// prev -> p -> next　⇒  prev -> next
  LIST *prev = p->prev;
  LIST *next = p->next;
  free(p);
  prev->next = next;
  if (next != NULL) next->prev = prev;
}

/*** リストの表示 ***/
void show_list(LIST *p) {
  while (p != NULL) {	/* 次ポインタがNULLまで処理 */
    printf("%d", p->key);
    p = p->next;
    if(p!=NULL) printf(" ");
  }
  printf("\n");
}

/*** リストの解放 ***/
void free_list(LIST *p) {
  while (p != NULL) {     /* 次ポインタがNULLまで処理 */
    LIST *p2 = p->next;
    free(p);
    p = p2;
  }
}

LIST *search(double key){
  LIST *p;
  p=head.next;
  while(p!=NULL && p->key!=key){
    p = p->next;
  }
  if(p==NULL) return NULL;
  else return p;
}
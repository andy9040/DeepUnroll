#include<stdio.h>
#include<string.h>

#define N 10000

int main(){
  int i,j,k,n,num[N],list[N],head=0,tmp,tail=0;
  char sel[N][11];
  char *s1="insert";
  char *s2="delete";
  char *s3="deleteFirst";
  char *s4="deleteLast";
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s",sel[i]);
    
    if(strcmp(sel[i],s3)==0) {
      head++;
      continue;
    }
    
    else if(strcmp(sel[i],s4)==0){
      tail--;
      continue;
    }
    scanf("%d",&num[i]);
    if(strcmp(sel[i],s1)==0){
      tail++;
      if(i!=0){
	for(j=tail;j>0;j--){
	  list[j]=list[j-1];
	}
      }
      list[head]=num[i];
    }
    
    else if(strcmp(sel[i],s2)==0){
      for(j=0;j<tail;j++){
	if(list[j]==num[i]){
	  for(k=j;k<tail;k++){
	    list[k]=list[k+1];
	  }
	  tail--;
	}
      }
    }
  }

  for(i=head;i<tail-1;i++) printf("%d ",list[i]);
  printf("%d\n",list[tail-1]);
  
  return 0;
}
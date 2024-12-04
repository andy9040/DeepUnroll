#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

#define POS(i,j) (((i)%b)*(m+1)+(j))

const int b=54;
char *ans=NULL;
int top=0;
void calc(char *s,char *t,int n,int m,int *nextN,int *nextM){
  short *dp=(short *)calloc((b+1)*(m+1),sizeof(short));
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(s[i]==t[j]){
	dp[POS(i+1,j+1)]=dp[POS(i,j)]+1;
      } else {
	dp[POS(i+1,j+1)]=MAX(dp[POS(i+1,j)],dp[POS(i,j+1)]);
      }
    }
  }
  i=n;
  j=m;
  while(i>MAX(0,n-b) && j>0){
    if(s[i-1]==t[j-1]){
      ans[top++]=s[i-1];
      i--;
      j--;
    } else if(dp[POS(i,j)]==dp[POS(i,j-1)]){
      j--;
    } else {
      i--;
    }
  }
  *nextN=i;
  *nextM=j;
}

void run(void){
  char *s=(char *)calloc(3001,sizeof(char));
  char *t=(char *)calloc(3001,sizeof(char));
  scanf("%s",s);
  scanf("%s",t);
  int n=strlen(s);
  int m=strlen(t);
  ans=(char *)calloc(n+1,sizeof(char));
  while(n>0 && m>0){
    calc(s,t,n,m,&n,&m);
  }
  while(top>0){
    putchar(ans[--top]);
  }
  putchar('\n');
}

int main(void){
  run();
  return 0;
}

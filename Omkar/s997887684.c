#include<stdio.h>

int main(void){
  char S[100000];
  int N;
  int i;
  int A=0,B=0;
  int ans;
  
  scanf("%s",S);
  
  for(i=0;i<100000;i++){
    if(S[i]=='\0'){
      N=i;
      break;
    }
    else{}
  }
  
  for(i=1;i<N;i++){
    if(S[i-1]=='0'&&S[i]=='0'){
      S[i]='1';
      A++;
	}
    else if(S[i-1]=='1'&&S[i]=='1'){
      S[i]='0';
      A++;
	}
    else{}
  }
  
  B = N-A;
  
  if(A<B) ans=A;
  else ans=B;

  printf("%d\n",ans);
  
  return 0;
  
}

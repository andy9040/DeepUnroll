#include<stdio.h>

int N;
char s[100010];
char a[100010];

int judge (int i, char a[100010]) {
  int ans;
  if(i>1 && i <N){
    if((a[i-1]=='S' && s[i-1]=='o') || (a[i-1]=='W' && s[i-1]=='x')){
      if(a[i-2]==a[i]){
	ans = 1;
      } else {
	ans = 0;
      }
    } else {
      if(a[i-2]!=a[i]){
	ans = 1;
      } else {
	ans = 0;
      }
    }
  } else if(i==1){
    if((a[0]=='S' && s[0]=='o') || (a[0]=='W' && s[0]=='x')){
      if(a[N-1]==a[1]){
	ans = 1;
      } else {
	ans = 0;
      }
    } else {
      if(a[N-1]!=a[1]){
	ans = 1;
      } else {
	ans = 0;
      }
    }
  } else if(i==N){
    if((a[N-1]=='S' && s[N-1]=='o') || (a[N-1]=='W' && s[N-1]=='x')){
      if(a[N-2]==a[0]){
	ans = 1;
      } else {
	ans = 0;
      }
    } else {
      if(a[N-2]!=a[0]){
	ans = 1;
      } else {
	ans = 0;
      }
    }
  } 
  return ans;
}


int dfs (int i, char a[100010]) {
  int ans;
  if(i==N){
    if(judge(N,a)){
      ans = 1;
    } else {
      ans = 0;
    }
  } else {
    a[i-1] = 'S';
    if(judge(i-1,a)){
      ans = dfs(i+1,a);
    } else {
      a[i-1] = 'W';
      if(judge(i-1,a)){
	ans = dfs(i+1,a);
      } else {
	ans = 0;
      }
    }
  }

  return ans;
}


int main (void) {
  scanf("%d",&N);
  scanf("%s",s);
  a[0] = 'S';
  a[N-1] = 'S';
  if(dfs(2,a)){
    printf("%s\n",a);
  } else {
    a[0] = 'S';
    a[N-1] = 'W';
    if(dfs(2,a)){
      printf("%s\n",a);
    } else {
      a[0] = 'W';
      a[N-1] = 'S';
      if(dfs(2,a)){
	printf("%s\n",a);
      } else {
	a[0] = 'W';
	a[N-1] = 'W';
	if(dfs(2,a)){
	  printf("%s\n",a);
	} else {
	  printf("-1\n");
	}
      }
    }
  }
  return 0;
}
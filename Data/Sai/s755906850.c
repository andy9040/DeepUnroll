#define M 3009
#include <stdio.h>
char* F(char *b,int n,FILE *f){char *r=fgets(b,n,f);if(!r)return NULL;b[strlen(b)-1]=0;return r;}
#define max(a,b) ((a)>(b)?(a):(b))
int lcs[M][M];
char a[M],b[M],l[M];
backtrack(i,j){
	if(i==0||j==0);
	else if(a[i]==b[j])backtrack(i-1,j-1),putchar(a[i]);
	else if(lcs[i][j-1]>lcs[i-1][j])backtrack(i,j-1);
	else backtrack(i-1,j);
}
main(int argc, char **argv){
  if(argc>1)freopen(argv[1],"rb",stdin);
  int i,j,_a,_b;
  strcpy(a,"*"),strcpy(b,"*");
  F(l,M,stdin);strcat(a,l);
  F(l,M,stdin);strcat(b,l);
  _a=strlen(a+1);_b=strlen(b+1);
  for(i=1;i<=_a;i++)
    for(j=1;j<=_b;j++){
#if 1
      if(a[i]==b[j])lcs[i][j]=lcs[i-1][j-1]+1;
      else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
#else
      lcs[i][j]=max(max(lcs[i-1][j],lcs[i][j-1]),lcs[i-1][j-1]+(a[i]==b[j]));
#endif
    }
  backtrack(_a,_b);puts("");
}

#include <stdio.h>
#include <string.h>

int min(int a,int b,int c){
    if(a > b) a = b;
    if(a > c) a = c;
    
    return a;
}
  

int main()
{
  int i,j;
  char s1[1000];
  char s2[1000];
  char c;
  for(i=0;i<1000;i++){
    scanf("%c",&c);
    if ( c == '\n'){
      s1[i] = '\0';
      break;
    }
    else
      s1[i] = c;
  }
  
  for(i=0;i<1000;i++){
    scanf("%c",&c);
    if ( c == '\n'){
      s2[i] = '\0';
      break;
    }
    else
      s2[i] = c;
  }
    
    int mat[strlen(s1)+1][strlen(s2)+1];
    for(i=0;i<=strlen(s1);i++){
        mat[i][0] = i;
    }
    for(i=0;i<=strlen(s2);i++){
        mat[0][i] = i;
    }
    
    int m,n,l,x;
    for(i=1;i<=strlen(s1);i++){
        for(j=1;j<=strlen(s2);j++){
            if(s1[i-1] == s2[i-1]) x = 0;
            else x = 1;
            m = mat[i-1][j] + 1;
            n = mat[i][j-1] + 1;
            l = mat[i-1][j-1] + x;
            mat[i][j] = min(m,n,l);
        }
    }
    
    
	

    printf("%d\n",mat[strlen(s1)][strlen(s2)]);
  return 0;
}
    
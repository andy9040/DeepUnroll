#include <stdio.h>
#include <string.h>

int main (){

  char S[105];
  int K = 0;

  scanf("%d", &K);
  scanf("%s", S);

  int len = 0;
  len = strlen( S );

  char SS[105];
  if( len <= K ){
    printf("%s \n", S);
  }
  else{
    strncpy( SS, S, K );
    printf("%s", SS);
    printf("... \n");
  }

  return 0;
}
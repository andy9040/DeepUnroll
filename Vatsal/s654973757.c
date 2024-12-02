/*
  A - One Card Poker
  <http://abc054.contest.atcoder.jp/tasks/abc054_a>
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {

  int A,B;

  scanf("%d %d", &A, &B);

  if( A > B ){
    printf("Alice\n");
  }else if( A < B ){
    printf("Bob\n");
  }else{
    printf("Draw\n");
  }

  return 0;
}

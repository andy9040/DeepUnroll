#include <stdio.h>

int check_bingo(int sheet[3][3]){
  if(
     (sheet[0][0] == 0 && sheet[1][0] == 0 && sheet[2][0] == 0)
  || (sheet[0][1] == 0 && sheet[1][1] == 0 && sheet[2][1] == 0)
  || (sheet[0][2] == 0 && sheet[1][2] == 0 && sheet[2][2] == 0)
     
  || (sheet[0][0] == 0 && sheet[0][1] == 0 && sheet[0][2] == 0)
  || (sheet[1][0] == 0 && sheet[1][1] == 0 && sheet[1][2] == 0)
  || (sheet[2][0] == 0 && sheet[2][1] == 0 && sheet[2][2] == 0)

  || (sheet[0][0] == 0 && sheet[1][1] == 0 && sheet[2][2] == 0)
  || (sheet[2][0] == 0 && sheet[1][1] == 0 && sheet[2][0] == 0)
    )
      return (1);
    return (0);
}

int main(){
  int sheet[3][3];
  int n;
  int i;
  int j;
  int k;
  
  scanf("%d %d %d", &sheet[0][0], &sheet[0][1], &sheet[0][2]);
  scanf("%d %d %d", &sheet[1][0], &sheet[1][1], &sheet[1][2]);
  scanf("%d %d %d", &sheet[2][0], &sheet[2][1], &sheet[2][2]);

  scanf("%d", &n);
  
//  for(j=0; j<3; j++){
//    for(k=0; k<3; k++){
//      printf("%d ", sheet[j][k]);
//    }
//    printf("\n");
//  }
  
  for(i=0; i<n; i++){
    scanf("%d", &n);
    for(j=0; j<3; j++){
      for(k=0; k<3; k++){
        if(sheet[j][k] == n)
          sheet[j][k] = 0;
      }
    }
  }
  
//  for(j=0; j<3; j++){
//    for(k=0; k<3; k++){
//      printf("%d ", sheet[j][k]);
//    }
//    printf("\n");
//  }
  
  if(check_bingo(sheet))
    printf("yes");
  else
    printf("no");
  
  return (0);
}
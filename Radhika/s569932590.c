#include <stdio.h>


int main(void){
  int m,mc,d,dc,setD,n[2],num,check;
  mc = 2;
  dc = 2;
  num = 0;
  check = 0;
  scanf("%d%d",&m,&d );

  do{
    setD = dc;
    n[0] = setD % 10;
    n[1] = (setD - n[0])/10;

    if(mc == n[0]*n[1]){
      if(n[0]>=2 && n[1]>=2){
        num++;
        //printf("%3d %3d\n",mc,dc );

      }
    }

    if(dc == d){
      mc++;
      dc = 2;
    }else{
      dc ++;
    }
    if(m == mc && d == dc){
      check = 1;
    }else if(m<=2 && d<=2){
      check = 1;
    }
  }while(check != 1);

  printf("%d\n",num );

  return 0;
}

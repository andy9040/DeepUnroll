#include<stdio.h>
main(){

  int a,b,y;
  a=0;
  y=0;

  while(1){  /*無限ループ*/
    y++;

    scanf("%d",&a);

    if(a==0){
      break;  /*ループを抜ける*/
    }

    printf("Case %d: %d\n",y,a);

  }
  return 0;
}
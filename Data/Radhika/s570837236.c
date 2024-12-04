#include<stdio.h>
int main(){
  int a;
  int b[21];
  int c = 0;
  int i;
  scanf("%d",&a);
  scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d ",b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9],b[10],b[11],b[12],b[13],b[14],b[15],b[16],b[17],b[18],b[19]);
  for(i = 0; i <= a-2;i++){
    if((b[i]<b[i+1]) && (b[i+1]<b[i+2])){
      c++;
    }else if((b[i]>b[i+1]) && (b[i+1]>b[i+2])){
      c++;
    }else{
      c += 0;
    }
  }
  printf("%d", c);
  return 0;
}

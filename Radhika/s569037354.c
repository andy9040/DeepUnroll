#include <stdio.h>
#include <string.h>
int main(void){
  int bng[3][3];
  int ans[3][3];

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      scanf("%d",&bng[i][j]);
      ans[i][j]=0;
    }
  }
  int n,b,x;
  scanf("%d",&n);
  for(x=0;x<n;x++){
    scanf("%d",&b);
    for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
      if(bng[i][j]==b){
        ans[i][j]=1;
      }
     }
   }
  }
  int w=0;
  if(ans[0][0]+ans[0][1]+ans[0][2]==3)
    w=1;
  if(ans[1][0]+ans[1][1]+ans[1][2]==3)
  w=1;
  if(ans[2][0]+ans[2][1]+ans[2][2]==3)
  w=1;
  if(ans[0][0]+ans[1][0]+ans[2][0]==3)
  w=1;
  if(ans[0][1]+ans[1][1]+ans[2][1]==3)
  w=1;
  if(ans[0][2]+ans[1][2]+ans[2][2]==3)
  w=1;
  if(ans[0][0]+ans[1][1]+ans[2][2]==3)
  w=1;
  if(ans[2][2]+ans[1][1]+ans[0][0]==3)
  w=1;

  if(w==1){
    printf("Yes\n");
  }else{
    printf("No");
  }
  return 0;
}
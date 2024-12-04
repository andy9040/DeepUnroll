	
#include<stdio.h>
main(){
  int i,j;
  char a[8][8];
  while(scanf("%s",a[0])!=EOF){
    for(i=1;i<8;i++){
      scanf("%s",a[i]);
    }
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
    if(a[i][j]=='1'&&a[i][j+1]=='1'&&a[i+1][j]=='1'&&a[i+1][j+1]=='1'){
      printf("A\n");
      break;
      break;
    }
    else if(a[i][j]=='1'&&a[i+1][j]=='1'&&a[i+2][j]=='1'&&a[i+3][j]=='1'){
      printf("B\n");
      break;
      break;
    }
    else if(a[i][j]=='1'&&a[i][j+1]=='1'&&a[i][j+2]=='1'&&a[i][j+3]=='1'){
      printf("C\n");
      break;
      break;
    }
    else if(a[i][j]=='1'&&a[i+1][j-1]=='1'&&a[i+1][j]=='1'&&a[i+2][j-1]=='1'){
      printf("D\n");
      break;
      break;
    }
    else if(a[i][j]=='1'&&a[i][j+1]=='1'&&a[i+1][j+1]=='1'&&a[i+1][j+2]=='1'){
      printf("E\n");
      break;
      break;
    }
    else if(a[i][j]=='1'&&a[i+1][j]=='1'&&a[i+1][j+1]=='1'&&a[i+2][j+1]=='1'){
      printf("F\n");
      break;
      break;
    }
    else if(a[i][j]=='1'&&a[i][j+1]=='1'&&a[i+1][j]=='1'&&a[i+1][j-1]=='1'){
      printf("G\n");
      break;
      break;
    }
      }
    }
  }
  return 0;
}
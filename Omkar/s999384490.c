#include <stdio.h>

main(){
  char map[10][10];
  int i, j,p=0,t;

  while(1){
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
	if(scanf("%c", &map[i][j])==EOF) p=1;
      }
      if(getchar()==EOF) p=1;
    }
    if(getchar()==EOF) p=1;
    if(p==1 && i<7 && j<7) break;

    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
	printf("%c", map[i][j]);
      }
      printf("\n");
    }
    printf("\n");
   




    t=0;
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
	if(map[i][j]=='1' && t==0){
	  if(j<=6 && i<=6 ){
	    if(map[i][j+1]=='1' && map[i+1][j]=='1' && map[i+1][j+1]=='1'){
	      printf("A\n");
	      t=1;
	    }
	  }
	  
	  if(j<=7 && i<=4 ){
	    if(map[i+1][j]=='1' && map[i+2][j]=='1' && map[i+3][j]=='1'){
	      printf("B\n");
	      t=1;
	    }
	  }
	  
	  if(j<=4 && i<=7 ){
	    if(map[i][j+1]=='1' && map[i][j+2]=='1' && map[i][j+3]=='1'){
	      printf("C\n");
	      t=1;
	    }
	  }
	  
	  if(j>=1 && j<=7 && i<=5 ){
	    if(map[i+1][j-1]=='1' && map[i+1][j]=='1' && map[i+2][j-1]=='1'){
	      printf("D\n");
	      t=1;
	    }
	  }
	  
	  if(j<=5 && i<=6 && t==0){
	    if(map[i][j+1]=='1' && map[i+1][j+1]=='1' && map[i+1][j+2]=='1'){
	      printf("E\n");
	      t=1;
	    }
	  }
	  
	  if(j<=6 && i<=5 ){
	    if(map[i+1][j]=='1' && map[i+1][j+1]=='1' && map[i+2][j+1]=='1'){
	      printf("F\n");
	      t=1;
	    }
	  }
	  
	  if(j>=1 && j<=5 && i<=6 ){
	    if(map[i][j+1]=='1' && map[i+1][j-1]=='1' && map[i+1][j]=='1'){
	      printf("G\n");
	      t=1;
	    }
	  }
	}
	if(t==1) break;
      }
      if(t==1) break;
    }
    if(p==1) break;
  }
  return 0;
}
#include <stdio.h>
int main(){
  int i ,go=0 ,cho=0 ,pa=0 ,pattern[5];
  while( scanf( "%d" ,&pattern[0] ) ){
    if( pattern[0] == 0 ){
      break;
    }

    for( i=1 ; i<=4 ; i++ ){
      scanf( "%d" ,&pattern[i] );
      if( pattern[i] == 1 ){
	go++;
      }
      
      else if( pattern[i] == 2 ){
	cho++;
      }
      
      else if( pattern[i] == 3 ){
	pa++;
      }
    }
    
    
    if( go != 0 && cho != 0 && pa != 0 ){
      for( i=0 ; i<5 ; i++ ){
	pattern[i] = 3;
      }
    }

    else if( cho != 0 && pa != 0 ){
      for( i=0 ; i<5 ; i++ ){
	if( pattern[i] == 2 ){
	  pattern[i] = 1;
	}
	else{
	  pattern[i] = 2;
	}
      }
    }

    else if( pa != 0 && go != 0 ){
      for( i=0 ; i<5 ; i++ ){
	if( pattern[i] == 3 ){
	  pattern[i] = 1;
	}
	else{
	  pattern[i] = 2;
	}
      }
    }

    for( i=0 ; i<5 ; i++ ){
      printf( "%d\n" ,pattern[i] );
    }
    go = 0;
    cho = 0;
    pa = 0;
  }

  return 0;
}
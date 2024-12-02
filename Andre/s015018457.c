#include <stdio.h>
int main(void)
{
          int fmat[9] ;
          int i , j;
          for( i = 0 ; i < 9 ; i ++ ) scanf("%d", &fmat[i]) ;
          int n ;
          scanf("%d" , &n) ;
          int numbers[n] ;
          for( i = 0 ; i < n ; i++) scanf("%d" , &numbers[i]) ;
          int flag[9] = {0,0,0,0,0,0,0,0,0} ;

          for(i = 0 ; i < 9; i++)
          {
                    if(flag[i] == 0)
                    {
                    for( j = 0 ; j < n ; j++)
                    {
                              if(fmat[i] == numbers[j]) flag[i] = 1 ;
                    }
                    }

          }
          if (flag[0] == 1 && flag[1] == 1 && flag[2] == 1 ||
                flag[3] == 1 && flag[4] == 1 && flag[5] == 1 ||
                flag[6] == 1 && flag[7] == 1 && flag[8] == 1 ||
               flag[0] == 1 && flag[3] == 1 && flag[6] == 1 ||
               flag[1  ] == 1 && flag[4] == 1 && flag[7] == 1 ||
               flag[2] == 1 && flag[5] == 1 && flag[8] == 1 ||
               flag[0] == 1 && flag[4] == 1 && flag[8] == 1 ||
               flag[2] == 1 && flag[4] == 1 && flag[6] == 1 )
          {
                    printf("Yes") ;
          }
          else printf("No") ;


}
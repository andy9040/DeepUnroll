#include<stdio.h>
int array[3], max, min, i;

int main()
    {
      scanf("%d %d %d",&array[0],&array[1],&array[2]);
     
      max = array[0];
      min = array[0];
      for (i = 0; i <=2 ; i++){ 
        if ( max < array[i]) max = array[i];
        if ( min > array[i]) min = array[i]; 
        }

      if ( (array [0] + array[1] + array[2]== 17) && (max == 7) && (min == 5))
        printf("YES");
      else
        printf("NO");
    }
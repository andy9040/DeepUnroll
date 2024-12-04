#include <stdio.h>

int main(void){
  int i, j, k, max;
  int num, tmp;

  scanf("%d", &max);
  int array[max];
  for(i = 0; i < max; i++){
    scanf("%d", &array[i]);
  }

  if(max < 3) num = 0;
  else{
      for(i = 0; i < max; i++){
        for(j = i + 1; j < max; j++){
          if(array[i] < array[j]){
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
          }
        }
      } 
      for(i = 0; i < max - 2; i++){
        for(j = i + 1; j < max - 1; j++){
          for(k = j + 1; k < max; k++){
            if(array[i] != array[j] && array[j] != array[k] && array[k] != array[i] && array[i] < array[j] + array[k])
            num++;
          }
        }
      }
  }

  printf("%d\n", num);

  return 0;
}



